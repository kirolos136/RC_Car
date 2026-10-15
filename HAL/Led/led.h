#ifndef LED_H
#define LED_H
#include"../../mcal/DIO_interface.h"

typedef enum {LED_OK , LED_NOK} led_status;
typedef enum {LED_0 , LED_1 , LED_2} Led_id;


led_status led_init(Led_id led);
led_status led_on(Led_id led);
led_status led_off(Led_id led);

#endif
