#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"
#include "user_config.h"
#include "wifi.h"
#include "mem.h"
#include "user_interface.h"


void ICACHE_FLASH_ATTR print_info()
{
  INFO("\r\n\r\n[INFO] BOOTUP...\r\n");
  INFO("[INFO] SDK: %s\r\n", system_get_sdk_version());
  INFO("[INFO] Chip ID: %08X\r\n", system_get_chip_id());
  INFO("[INFO] Memory info:\r\n");
  system_print_meminfo();
}


void ICACHE_FLASH_ATTR
init_mqtt_rpc(uint8_t status) {
    if(status != STATION_GOT_IP) {
        return;
    }

    // things that need to be done after connecting to wifi
}


void ICACHE_FLASH_ATTR
init_all(void) {
    // system_set_os_print(0);
    uart_div_modify(0, UART_CLK_FREQ / 115200);
    print_info();

    INFO("Connecting to wifi...\n");
    WIFI_Connect(WIFI_SSID, WIFI_PASS, init_mqtt_rpc);
}

void ICACHE_FLASH_ATTR
user_init()
{
    system_init_done_cb(init_all);
}
