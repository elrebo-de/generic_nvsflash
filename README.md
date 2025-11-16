# Generic NVS Flash Component

This repository contains an ESP-IDF component for the NVS flash. It runs on
any ESP32 processor and is built using the ESP-IDF build system in version 6.0.

The component is implemented as C++ class `GenericNvsFlash`.

## Connecting the component

The constructor of class `GenericNvsFlash` has three parameters:

| Parameter    | Type of Parameter | Usage                             |
|:-------------|:------------------|:----------------------------------|
| tag          | std::string       | the tag to be used in the ESP log |
| nvsNamespace | std::string | the NVS namespace to open         |
| nvsOpenMode | nvs_open_mode_t | NVS_READONLY or NVS_READWRITE     |

The constructor opens the nvsNamespace for readonly or read/write operations.
If neccesary, NVS Flash is initialized.

The destructor commits all changes and closes the connection.

# Usage

Currently only values of type 

* std::string
* int8_t
* uint8_t 

are supported. 
Please call me if you want to use values of other types.

Key Value pairs can be written with Method `SetStr` and 
read with method `GetStr` and 
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
```

# License

This component is provided under the MIT license.

The work is based on the github repository 78/esp-wifi-connect

