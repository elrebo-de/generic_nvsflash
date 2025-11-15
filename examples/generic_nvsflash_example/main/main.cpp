/*
 * Example program to use the generic NVS flash with elrebo-de/generic_nvsflash
 */

#include <string>
#include "generic_nvsflash.hpp"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soc/clk_tree_defs.h"

static const char *tag = "generic_nvsflash_example";

extern "C" void app_main(void)
{
    /* Open NVS flash Namespace "wifi" for read/write operations */
    GenericNvsFlash nvsWifi(std::string("nvsWifi"), std::string("wifi"), NVS_READWRITE);

    esp_err_t ret = ESP_OK;
    std::string ssid;
    std::string password;

    ESP_LOGI(tag, "NVS Flash namespace wifi Read ssid, password, ssid1, password1, ssid2 and password2");

    /* Read values for keys "ssid" and "password" from Namespace "wifi" */
    ssid = nvsWifi.GetStr(std::string("ssid"), &ret);
    password = nvsWifi.GetStr(std::string("password"), &ret);
    ESP_LOGI(tag, "NVS flash namespace wifi ssid: '%s' password: '%s'", ssid.c_str(), password.c_str());

    /* Read values for keys "ssid1" and "password1" from Namespace "wifi" */
    ssid = nvsWifi.GetStr(std::string("ssid1"), &ret);
    password = nvsWifi.GetStr(std::string("password1"), &ret);
    ESP_LOGI(tag, "NVS flash namespace wifi ssid1: '%s' password1: '%s'", ssid.c_str(), password.c_str());

    /* Read values for keys "ssid2" and "password2" from Namespace "wifi" */
    ssid = nvsWifi.GetStr(std::string("ssid2"), &ret);
    password = nvsWifi.GetStr(std::string("password2"), &ret);
    ESP_LOGI(tag, "NVS flash namespace wifi ssid2: '%s' password2: '%s'", ssid.c_str(), password.c_str());

    vTaskDelay(1000 / portTICK_PERIOD_MS);

    ESP_LOGI(tag, "NVS Flash namespace wifi write ssid1 and password1");

    /* Write values for keys "ssid1" and "password1" to Namespace "wifi" */
    ssid = std::string("Brot!Box");
    password = std::string("geheim!");
    ret = nvsWifi.SetStr(std::string("ssid1"), ssid);
    ret = nvsWifi.SetStr(std::string("password1"), password);

    vTaskDelay(1000 / portTICK_PERIOD_MS);

    ESP_LOGI(tag, "NVS Flash namespace wifi Read ssid, password, ssid1, password1, ssid2 and password2");

    /* Read values for keys "ssid" and "password" from Namespace "wifi" */
    ssid = nvsWifi.GetStr(std::string("ssid"), &ret);
    password = nvsWifi.GetStr(std::string("password"), &ret);
    ESP_LOGI(tag, "NVS flash namespace wifi ssid: '%s' password: '%s'", ssid.c_str(), password.c_str());

    /* Read values for keys "ssid1" and "password1" from Namespace "wifi" */
    ssid = nvsWifi.GetStr(std::string("ssid1"), &ret);
    password = nvsWifi.GetStr(std::string("password1"), &ret);
    ESP_LOGI(tag, "NVS flash namespace wifi ssid1: '%s' password1: '%s'", ssid.c_str(), password.c_str());

    /* Read values for keys "ssid2" and "password2" from Namespace "wifi" */
    ssid = nvsWifi.GetStr(std::string("ssid2"), &ret);
    password = nvsWifi.GetStr(std::string("password2"), &ret);
    ESP_LOGI(tag, "NVS flash namespace wifi ssid2: '%s' password2: '%s'", ssid.c_str(), password.c_str());
}
