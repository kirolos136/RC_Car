#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H
#include"../../lib/std_types.h"

typedef enum {PWM_OK , PWM_NOK} PWM_ErrorStatus;
typedef enum {PWM_CHANNEL_A , PWM_CHANNEL_B} PWM_Channel_t; //OC1A = PD5 and OC1B = PD4

PWM_ErrorStatus PWM_Init(void);

PWM_ErrorStatus PWM_SetDuty(PWM_Channel_t c,u8 duty); // choose for a duty a value from 0 to 100 oercent

#endif