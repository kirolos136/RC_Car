#include"../hal/led/led.h"
#include <util/delay.h>
int main(){
    while(1){
        led_init(LED_0);
        led_init(LED_1);
        led_init(LED_2);

        led_on(LED_0);
        _delay_ms(500);
        led_off(LED_0);

        led_on(LED_1);
        _delay_ms(500);
        led_off(LED_1);

        led_on(LED_2);
        _delay_ms(500);
        led_off(LED_2);
    }
}
