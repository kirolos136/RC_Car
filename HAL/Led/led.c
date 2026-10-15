#include"led.h"
#include"config.h"

extern Led_config leds_configuration[];

led_status led_init(Led_id led){
    if(led < LED_0 || led > LED_2) return LED_NOK;
    
    DIO_ErrorStatus st = DIO_setPinDirection(leds_configuration[led].port,leds_configuration[led].pin,DIO_OUTPUT);

    if(st  == DIO_NOK) return LED_NOK;

    return LED_OK;
}

led_status led_on(Led_id led){
    if(led < LED_0 || led > LED_2) return LED_NOK;

    DIO_ErrorStatus st = DIO_setPinValue(leds_configuration[led].port,leds_configuration[led].pin,DIO_HIGH);

    if(st == DIO_NOK) return LED_NOK;

    return LED_OK;
}

led_status led_off(Led_id led){
    if(led < LED_0 || led > LED_2) return LED_NOK;

    DIO_ErrorStatus st = DIO_setPinValue(leds_configuration[led].port,leds_configuration[led].pin,DIO_LOW);

    if(st == DIO_NOK) return LED_NOK;

    return LED_OK;
}