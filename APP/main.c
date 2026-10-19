#include "../HAL/Led/led.h"
#include <util/delay.h>
#include "../HAL/Bluetooth/BLUETOOTH_interface.h"

int main(void){
    bluetooth_init();
    while(1){
        u8 byte;
        bluetooth_receiveByte(&byte);
        bluetooth_sendByte(byte);
    }
}