#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#include "../../LIB/std_types.h"

#define UART_UBRR_VALUE   51

#define UDR_REG     (*(volatile u8 *)0x2C) 
#define UCSRA_REG   (*(volatile u8 *)0x2B)
#define UCSRB_REG   (*(volatile u8 *)0x2A)
#define UBRRL_REG   (*(volatile u8 *)0x29)   

// note the following 2 registers share the same address bit 7 of the write byte URSEL 1 -> UCSRC and 0 -> UBRRH
#define UCSRC_REG   (*(volatile u8 *)0x40)
#define UBRRH_REG   (*(volatile u8 *)0x40)

/* ================= UCSRA bits ================= */
#define UART_MPCM    0   /* Multi-processor mode (unused)        */
#define UART_U2X     1   /* Double speed (keep 0)                */
#define UART_PE      2   /* Parity error                         */
#define UART_DOR     3   /* Data overrun                         */
#define UART_FE      4   /* Frame error                          */
#define UART_UDRE    5   /* 1 = UDR empty, ready to send         */
#define UART_TXC     6   /* Transmit complete                    */
#define UART_RXC     7   /* 1 = byte received, read UDR          */

/* ================= UCSRB bits ================= */
#define UART_TXB8    0   /* 9th bit to send (9-bit mode only)    */
#define UART_RXB8    1   /* 9th bit received (read-only)         */
#define UART_UCSZ2   2   /* Char size bit 2 (0 for 8-bit)        */
#define UART_TXEN    3   /* Transmitter enable                   */
#define UART_RXEN    4   /* Receiver enable                      */
#define UART_UDRIE   5   /* UDR empty interrupt enable           */
#define UART_TXCIE   6   /* TX complete interrupt enable         */
#define UART_RXCIE   7   /* RX complete interrupt enable         */

/* ================= UCSRC bits ================= */
#define UART_UCPOL   0   /* Clock polarity (sync only, write 0)  */
#define UART_UCSZ0   1   /* Char size bit 0                      */
#define UART_UCSZ1   2   /* Char size bit 1                      */
#define UART_USBS    3   /* Stop bits: 0 = 1 bit                 */
#define UART_UPM0    4   /* Parity mode bit 0                    */
#define UART_UPM1    5   /* Parity mode bit 1                    */
#define UART_UMSEL   6   /* 0 = asynchronous                     */
#define UART_URSEL   7   /* Register select (1 = UCSRC)          */

#endif