#include "../../LIB/std_types.h"
#include "UART_interface.h"
#include "UART_private.h"

UART_ErrorStatus UART_init(void)
{
    UCSRA_REG = 0; //contain the flags

    UBRRH_REG = 0;
    UBRRL_REG = UART_UBRR_VALUE;           /* for baud rate 51 -> 9600 baud */

    UCSRB_REG = (1 << UART_RXEN) | (1 << UART_TXEN);

    UCSRC_REG = (1 << UART_URSEL) | (1 << UART_UCSZ1) | (1 << UART_UCSZ0);

    return UART_OK;
}


UART_ErrorStatus UART_sendByte(u8 byte){
    while (!(UCSRA_REG & (1 << UART_UDRE))); // check buffer is empty to be ready to write in it

    UDR_REG = byte;

    return UART_OK;
}

UART_ErrorStatus UART_receiveByte(u8* Ptr_byte){
    if(Ptr_byte == NULL) return UART_NOK;

    while(!(UCSRA_REG & (1 << UART_RXC)));

    *Ptr_byte = UDR_REG;

    return UART_OK;
}

UART_ErrorStatus UART_ReceiveByteNonBlocking(u8* Ptr_byte){
    if(Ptr_byte == NULL) return UART_NOK;

    if(UCSRA_REG & (1 << UART_RXC)){   /* byte waiting? */
        *Ptr_byte = UDR_REG;           /* read once -> hardware clears RXC */
        return UART_OK;
    }

    return UART_NO_DATA;               /* nothing arrived: return immediately */
}