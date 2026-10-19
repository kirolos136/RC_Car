#ifndef MOTOR_CONFIG_H
#define MOTOR_CONFIG_H
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/PWM/PWM_interface.h"

typedef struct {
    DIO_Port port;
    DIO_Pin Pin;
} Motor_in_t;

typedef struct{
    Motor_in_t In_a;
    Motor_in_t In_b;
    PWM_Channel_t channel;
}Motor_config_t;

#endif