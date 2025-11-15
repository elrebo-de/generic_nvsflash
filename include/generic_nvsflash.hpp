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
    std::string GetStr(std::string key, esp_err_t *ret);
    esp_err_t SetStr(std::string key, std::string outValue);

    esp_err_t EraseKey(std::string key);

private:	
    std::string tag = "GenericNvsFlash";
    std::string nvsNamespace;
    nvs_open_mode_t nvsOpenMode;
    nvs_handle_t nvsHandle = 0;
    bool nvsNamespaceOpen = false;
};

#endif /* GENERIC_NVSFLASH_HPP_ */
