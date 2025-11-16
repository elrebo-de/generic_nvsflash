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

    ESP_LOGI(tag, "NVS Flash namespace wifi Erase key password1");

    /* Erase Key "password1" of Namespace "wifi" */
    ret = nvsWifi.EraseKey(std::string("password1"));

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

    ESP_LOGI(tag, "NVS Flash namespace wifi Read and Write all int and uint types");
    int8_t i8 = -125;
    uint8_t u8 = 250U;
    int16_t i16 = -32760;
    uint16_t u16 = 65000U;
    int32_t i32 = -2147483600L;
    uint32_t u32 = 4294967200UL;
    int64_t i64 = -9223372036854775000LL;
    uint64_t u64 = 18446744073709551000ULL;

    /* Write value all int - and uint-types to Namespace "wifi" */
    ret = nvsWifi.SetI8(std::string("i8"), i8);
    ret = nvsWifi.SetU8(std::string("u8"), u8);
    ret = nvsWifi.SetI16(std::string("i16"), i16);
    ret = nvsWifi.SetU16(std::string("u16"), u16);
    ret = nvsWifi.SetI32(std::string("i32"), i32);
    ret = nvsWifi.SetU32(std::string("u32"), u32);
    ret = nvsWifi.SetI64(std::string("i64"), i64);
    ret = nvsWifi.SetU64(std::string("u64"), u64);

    vTaskDelay(1000 / portTICK_PERIOD_MS);

    ESP_LOGI(tag, "NVS Flash namespace wifi Read values of all keys for int- and uint-types");

    int8_t i8r = nvsWifi.GetI8(std::string("i8"), &ret);
    ESP_LOGI(tag, "NVS Flash namespace wifi key i8: %hhi", i8r);
    uint8_t u8r = nvsWifi.GetU8(std::string("u8"), &ret);
    ESP_LOGI(tag, "NVS Flash namespace wifi key u8: %hhu", u8r);
    int16_t i16r = nvsWifi.GetI16(std::string("i16"), &ret);
    ESP_LOGI(tag, "NVS Flash namespace wifi key i16: %hi", i16r);
    uint16_t u16r = nvsWifi.GetU16(std::string("u16"), &ret);
    ESP_LOGI(tag, "NVS Flash namespace wifi key u16: %hu", u16r);
    int32_t i32r = nvsWifi.GetI32(std::string("i32"), &ret);
    ESP_LOGI(tag, "NVS Flash namespace wifi key i32: %li", i32r);
    uint32_t u32r = nvsWifi.GetU32(std::string("u32"), &ret);
    ESP_LOGI(tag, "NVS Flash namespace wifi key u32: %lu", u32r);
    int64_t i64r = nvsWifi.GetI64(std::string("i64"), &ret);
    ESP_LOGI(tag, "NVS Flash namespace wifi key i64: %lli", i64r);
    uint64_t u64r = nvsWifi.GetU64(std::string("u64"), &ret);
    ESP_LOGI(tag, "NVS Flash namespace wifi key u64: %llu", u64r);
}
