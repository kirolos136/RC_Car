#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

typedef enum{UART_OK , UART_NOK , UART_NO_DATA} UART_ErrorStatus;

UART_ErrorStatus UART_init(void);

UART_ErrorStatus UART_sendByte(u8 byte);

UART_ErrorStatus UART_recieveByte(u8* byte);

UART_ErrorStatus UART_ReceiveByteNonBlocking(u8* Ptr_byte);

#endif