#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "../../LIB/std_types.h"


typedef enum {DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD} DIO_Port;

typedef enum {DIO_PIN0, DIO_PIN1, DIO_PIN2, DIO_PIN3,
              DIO_PIN4, DIO_PIN5, DIO_PIN6, DIO_PIN7} DIO_Pin;

typedef enum {DIO_INPUT, DIO_OUTPUT} DIO_Dir;

typedef enum {DIO_LOW, DIO_HIGH} DIO_Level;

typedef enum {DIO_OK, DIO_NOK} DIO_ErrorStatus;

DIO_ErrorStatus DIO_setPinDirection(DIO_Port port, DIO_Pin pin, DIO_Dir dir);
DIO_ErrorStatus DIO_setPinValue(DIO_Port port, DIO_Pin pin, DIO_Level level);
DIO_ErrorStatus DIO_togglePin(DIO_Port port, DIO_Pin pin);
DIO_ErrorStatus DIO_getPinValue(DIO_Port port, DIO_Pin pin, DIO_Level *value);

#endif