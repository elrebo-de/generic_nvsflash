/*
 * generic_nvsflash.cpp
 *
 *  Created on 01.11.2025
 *      Author: christophoberle
 *
 * this work is licenced under the Apache 2.0 licence
 */

#include "generic_nvsflash.hpp"
#include "esp_log.h"

static bool nvsFlashInitialized = false;

GenericNvsFlash::GenericNvsFlash(std::string tag, std::string nvsNamespace, nvs_open_mode_t nvsOpenMode) {
	this->tag = tag;
    this->nvsNamespace = nvsNamespace;
    this->nvsOpenMode = nvsOpenMode;

    // initialize NVS flash if not already done
    if (!nvsFlashInitialized) {
        //ESP_LOGI(this->tag.c_str(), "nvs_flash_init");
        esp_err_t ret = nvs_flash_init();
        if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
            // erase NVS flash
            //ESP_LOGI(this->tag.c_str(), "not ok: nvs_flash_erase");
            ESP_ERROR_CHECK(nvs_flash_erase());
            // and initialize new NVS flash
            //ESP_LOGI(this->tag.c_str(), "not ok: nvs_flash_init");
            ret = nvs_flash_init();
        }
        ESP_ERROR_CHECK(ret);
        //ESP_LOGI(this->tag.c_str(), "nvsFlashInitialized == true");
        nvsFlashInitialized = true;
    }

    if (this->nvsHandle == 0) {
        //ESP_LOGI(this->tag.c_str(), "nvs_open");
        auto ret = nvs_open(nvsNamespace.c_str(), nvsOpenMode, &nvsHandle);
        if (ret != ESP_OK) {
            // The namespace doesn't exist, just return
            ESP_LOGW(this->tag.c_str(), "NVS namespace %s doesn't exist", nvsNamespace.c_str());
        }
        //ESP_LOGI(this->tag.c_str(), "nvsNamespaceOpen == true");
        this->nvsNamespaceOpen = true;
    }

}

GenericNvsFlash::~GenericNvsFlash() {
    if (this->nvsNamespaceOpen) {
        nvs_commit(this->nvsHandle);
        nvs_close(this->nvsHandle);
    }
}

std::string GenericNvsFlash::GetStr(std::string key, esp_err_t *ret) {
    //ESP_LOGI(this->tag.c_str(), "GetStr für key %s", key.c_str());
    // out_value definieren
    char* outValue = (char *)malloc(4000);
    //char outValue[4000];
    // länge von out_value in length speichern
    size_t length = 4000;
    // out_value abrufen
    //ESP_LOGI(this->tag.c_str(), "GetStr call nvs_get_str");
    *ret = nvs_get_str(this->nvsHandle, key.c_str(), outValue, &length);
    //ESP_LOGI(this->tag.c_str(), "GetStr outValue = %s", outValue);
    std::string result = "";
    if (*ret == ESP_OK) {
        result = std::string(outValue);
    }
    return result;
}

esp_err_t GenericNvsFlash::SetStr(std::string key, std::string outValue) {
    return nvs_set_str(this->nvsHandle, key.c_str(), outValue.c_str());
}

esp_err_t GenericNvsFlash::EraseKey(std::string key) {
    return nvs_erase_key(this->nvsHandle, key.c_str());
}
