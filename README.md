# Generic NVS Flash Component

This repository contains an ESP-IDF component for the NVS flash. It runs on
any ESP32 processor and is built using the ESP-IDF build system in version 5.5.0+.

The component is implemented as C++ class `GenericNvsFlash`.

## Connecting the component

The constructor of class `GenericNvsFlash` has three parameters:

| Parameter    | Type of Parameter | Usage                             |
|:-------------|:------------------|:----------------------------------|
| tag          | std::string       | the tag to be used in the ESP log |
| nvsNamespace | std::string       | the NVS namespace to open         |
| nvsOpenMode  | nvs_open_mode_t   | NVS_READONLY or NVS_READWRITE     |

The constructor opens the nvsNamespace for readonly or read/write operations.
If neccesary, NVS Flash is initialized.

The destructor commits all changes and closes the connection.

# Usage

Key Value pairs can be written with methods `SetStr`, `SetI8`, `SetU8`, `SetI16`, `SetU16`, `SetI32`, `SetU32`, `SetI64`, `SetU64`,

read with methods `GetStr`, `GetI8`, `GetU8`, `GetI16`, `GetU16`, `GetI32`, `GetU32`, `GetI64`, `GetU64` and 

erased with method `EraseKey`:

```C++
/* Open NVS flash Namespace "wifi" for read/write operations */
GenericNvsFlash nvsWifi(std::string("nvsWifi"), std::string("wifi"), NVS_READWRITE);

/* Write Key Value pair */
esp_err_t ret;
ret = nvsWifi.SetStr(std::string("ssid1"), std::string("myWLANssid");

/* Read Value of Key Value pair */
std::string ssid1;
ssid1 = nvsWifi.GetStr(std::string("ssid1"), &ret);

/* Erase Key Value pair */
ret = nvsWifi.EraseKey(std::string("ssid1"));

```

## API
The API of the component is located in the include directory ```include/generic_nvsflash.hpp``` and defines the
C++ class ```GenericNvsFlash```

```C++
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
```

# License

This component is provided under the MIT license.

The work is based on the github repository 78/esp-wifi-connect

