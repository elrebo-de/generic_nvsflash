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
    esp_err_t SetStr(std::string key, std::string value);
    // int8_t
    int8_t GetI8(std::string key, esp_err_t *ret);
    esp_err_t SetI8(std::string key, int8_t value);
    //uint8_t
    uint8_t GetU8(std::string key, esp_err_t *ret);
    esp_err_t SetU8(std::string key, uint8_t value);
    // int16_t
    int16_t GetI16(std::string key, esp_err_t *ret);
    esp_err_t SetI16(std::string key, int16_t value);
    //uint16_t
    uint16_t GetU16(std::string key, esp_err_t *ret);
    esp_err_t SetU16(std::string key, uint16_t value);
    // int32_t
    int32_t GetI32(std::string key, esp_err_t *ret);
    esp_err_t SetI32(std::string key, int32_t value);
    //uint32_t
    uint32_t GetU32(std::string key, esp_err_t *ret);
    esp_err_t SetU32(std::string key, uint32_t value);
    // int64_t
    int64_t GetI64(std::string key, esp_err_t *ret);
    esp_err_t SetI64(std::string key, int64_t value);
    //uint64_t
    uint64_t GetU64(std::string key, esp_err_t *ret);
    esp_err_t SetU64(std::string key, uint64_t value);

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
