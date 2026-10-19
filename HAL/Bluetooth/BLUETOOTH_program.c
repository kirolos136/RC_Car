#include "BLUETOOTH_interface.h"
#include "../../MCAL/UART/UART_interface.h"

bluetoothErrorStatus bluetooth_init(void){
    UART_ErrorStatus ues = UART_init();

    if(ues == UART_OK) return BLUETOOTH_OK;
    else return BLUETOOTH_NOK;
}

bluetoothErrorStatus bluetooth_sendByte(u8 byte){
    UART_ErrorStatus ues = UART_sendByte(byte);

    if(ues == UART_OK) return BLUETOOTH_OK;
    else return BLUETOOTH_NOK;
}

bluetoothErrorStatus bluetooth_receiveByte(u8* ptr_byte){
    UART_ErrorStatus ues = UART_receiveByte(ptr_byte);

    if(ues == UART_OK) return BLUETOOTH_OK;
    else return BLUETOOTH_NOK;
}