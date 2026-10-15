#include "DIO_interface.h"
#include "DIO_private.h"
#include "../lib/bit_math.h"

DIO_ErrorStatus DIO_setPinDirection(DIO_Port port, DIO_Pin pin, DIO_Dir dir)
{
    if (port > DIO_PORTD || pin > DIO_PIN7 || dir < DIO_INPUT || dir > DIO_OUTPUT) return DIO_NOK;

    switch (port)
    {
    case DIO_PORTA:
        if (dir == DIO_OUTPUT) SET_BIT(DDRA_REG, pin);
        else CLR_BIT(DDRA_REG, pin);
        break;
    case DIO_PORTB:
        if (dir == DIO_OUTPUT) SET_BIT(DDRB_REG, pin);
        else CLR_BIT(DDRB_REG, pin);
        break;
    case DIO_PORTC:
        if (dir == DIO_OUTPUT) SET_BIT(DDRC_REG, pin);
        else CLR_BIT(DDRC_REG, pin);
        break;
    case DIO_PORTD:
        if (dir == DIO_OUTPUT) SET_BIT(DDRD_REG, pin);
        else CLR_BIT(DDRD_REG, pin);
        break;
    default:
        return DIO_NOK;
    }

    return DIO_OK;
}

DIO_ErrorStatus DIO_setPinValue(DIO_Port port, DIO_Pin pin, DIO_Level level)
{
    if (port > DIO_PORTD || pin > DIO_PIN7 || level < DIO_LOW || level > DIO_HIGH) return DIO_NOK;

    switch (port)
    {
    case DIO_PORTA:
        if (level == DIO_HIGH) SET_BIT(PORTA_REG, pin);
        else CLR_BIT(PORTA_REG, pin);
        break;
    case DIO_PORTB:
        if (level == DIO_HIGH) SET_BIT(PORTB_REG, pin);
        else CLR_BIT(PORTB_REG, pin);
        break;
    case DIO_PORTC:
        if (level == DIO_HIGH) SET_BIT(PORTC_REG, pin);
        else CLR_BIT(PORTC_REG, pin);
        break;
    case DIO_PORTD:
        if (level == DIO_HIGH) SET_BIT(PORTD_REG, pin);
        else CLR_BIT(PORTD_REG, pin);
        break;
    default:
        return DIO_NOK;
    }

    return DIO_OK;
}

DIO_ErrorStatus DIO_togglePin(DIO_Port port, DIO_Pin pin)
{
    if (port > DIO_PORTD || pin > DIO_PIN7) return DIO_NOK;

    switch (port)
    {
    case DIO_PORTA: TOG_BIT(PORTA_REG, pin); break;
    case DIO_PORTB: TOG_BIT(PORTB_REG, pin); break;
    case DIO_PORTC: TOG_BIT(PORTC_REG, pin); break;
    case DIO_PORTD: TOG_BIT(PORTD_REG, pin); break;
    default:        return DIO_NOK;
    }

    return DIO_OK;
}

DIO_ErrorStatus DIO_getPinValue(DIO_Port port, DIO_Pin pin, DIO_Level *value)
{
    /* Check the pointer BEFORE using it */
    if (value == NULL || port > DIO_PORTD || pin > DIO_PIN7) return DIO_NOK;

    switch (port)
    {
    case DIO_PORTA: *value = GET_BIT(PINA_REG, pin); break;
    case DIO_PORTB: *value = GET_BIT(PINB_REG, pin); break;
    case DIO_PORTC: *value = GET_BIT(PINC_REG, pin); break;
    case DIO_PORTD: *value = GET_BIT(PIND_REG, pin); break;
    default:        return DIO_NOK;
    }

    return DIO_OK;
}