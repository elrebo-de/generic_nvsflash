/*
 * generic_nvsflash.hpp
 *
 *  Created on: 30.10.2025
 *      Author: christophoberle
 *
 * this work is licenced under the Apache 2.0 licence
 */

#ifndef GENERIC_NVSFLASH_HPP_
#define GENERIC_NVSFLASH_HPP_

#include <stdio.h>

#include <nvs_flash.h>
#include <cstdint>
#include <string>

class GenericNvsFlash {
public:
	GenericNvsFlash(std::string tag, std::string nvsNamespace, nvs_open_mode_t nvsOpenMode);
	virtual ~GenericNvsFlash();
	// std::string
    std::string GetStr(std::string key, esp_err_t *ret);
    esp_err_t SetStr(std::string key, std::string outValue);
    // int8_t
    int8_t GetI8(std::string key, esp_err_t *ret);
    esp_err_t SetI8(std::string key, int8_t outValue);
    //uint8_t
    uint8_t GetU8(std::string key, esp_err_t *ret);
    esp_err_t SetU8(std::string key, uint8_t outValue);

    esp_err_t EraseKey(std::string key);
    bool NvsFlashInitialized();
    bool NvsNamespaceOpen();

private:	
    std::string tag = "GenericNvsFlash";
    std::string nvsNamespace;
    nvs_open_mode_t nvsOpenMode;
    nvs_handle_t nvsHandle = 0;
    bool nvsNamespaceOpen = false;
};

#endif /* GENERIC_NVSFLASH_HPP_ */
