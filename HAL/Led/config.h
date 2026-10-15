#ifndef CONFIG_H
#define CONFIG_H
#include"../../mcal/DIO_interface.h"

//assume active high
typedef struct Led_config
{
    DIO_Port port;
    DIO_Pin pin;
}Led_config;

#endif