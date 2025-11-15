## Generic NVS Flash Example

This example demonstrates how to utilize the `generic_nvsflash` component to use the NVS Flash.

It reads six keys from namespace "wifi", 
then it writes two keys to this namespace,
then it reads all six keys again,
then it erases one key and
then it reads all six keys again.

If you run the program a second time, 
the keys "ssid1" is set from the beginning.

The flash can be erased with `idf.py erase-flash`

## Build and Flash

Build the project and flash it to the board, then run the monitor tool to view the serial output:

* Run `. <directory with ESP-IDF version>/export.sh` to set IDF environment
* Run `idf.py set-target esp32xx` to set target chip
* Run `idf.py -p PORT flash monitor` to build, flash and monitor the project

(To exit the serial monitor, type `Ctrl-]` (or on a Mac `Ctrl-Option-6`).

See the Getting Started Guide for all the steps to configure and use the ESP-IDF to build projects.

## Example Output

```
I (267) main_task: Calling app_main()
I (267) generic_nvsflash_example: NVS Flash namespace wifi Read ssid, password, ssid1, password1, ssid2 and password2
I (267) generic_nvsflash_example: NVS flash namespace wifi ssid: '' password: ''
I (277) generic_nvsflash_example: NVS flash namespace wifi ssid1: '' password1: ''
I (287) generic_nvsflash_example: NVS flash namespace wifi ssid2: '' password2: ''
I (1297) generic_nvsflash_example: NVS Flash namespace wifi write ssid1 and password1
I (2297) generic_nvsflash_example: NVS Flash namespace wifi Read ssid, password, ssid1, password1, ssid2 and password2
I (2297) generic_nvsflash_example: NVS flash namespace wifi ssid: '' password: ''
I (2297) generic_nvsflash_example: NVS flash namespace wifi ssid1: 'Brot!Box' password1: 'geheim!'
I (2307) generic_nvsflash_example: NVS flash namespace wifi ssid2: '' password2: ''
I (2317) main_task: Returned from app_main()
```