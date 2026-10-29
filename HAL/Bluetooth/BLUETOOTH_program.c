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

bluetoothErrorStatus bluetooth_receiveByteNonBlocking(u8* ptr_byte){
    UART_ErrorStatus ues = UART_ReceiveByteNonBlocking(ptr_byte);

    switch (ues)
    {
    case UART_OK:
        return BLUETOOTH_OK;
        break;
    
    case UART_NOK:
        return BLUETOOTH_NOK;
        break;
    
    default:
        return BLUETOOTH_NO_DATA; 
        break;
    }
}