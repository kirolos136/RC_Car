#include "motor_config.h"

Motor_config_t motors[2] ={
    {{DIO_PORTA,DIO_PIN7} , {DIO_PORTA,DIO_PIN6} , PWM_CHANNEL_A},
    {{DIO_PORTA,DIO_PIN5} , {DIO_PORTA,DIO_PIN4} , PWM_CHANNEL_B}
};