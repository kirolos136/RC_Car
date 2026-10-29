#include "../HAL/Led/led.h"
#include <util/delay.h>
#include "../HAL/Bluetooth/BLUETOOTH_interface.h"
#include "../HAL/Motor/motor_interface.h"

int main(void){
    bluetooth_init();
    Motor_init();
    u16 counter = 0;

    while(1){
        u8 byte;
        bluetoothErrorStatus bes = bluetooth_receiveByteNonBlocking(&byte);

        if(bes == BLUETOOTH_NO_DATA){
            counter++;
            _delay_ms(10);

            if(counter == 30){
                Motor_setDirection(MOTOR_RIGHT , MOTOR_DIRECTION_STOP);
                Motor_setDirection(MOTOR_LEFT , MOTOR_DIRECTION_STOP);
            }

            continue;
        }


        if(byte == 'f' || byte == 'F'){

            Motor_setDirection(MOTOR_RIGHT,MOTOR_DIRECTION_FORWARD);
            Motor_setDirection(MOTOR_LEFT,MOTOR_DIRECTION_FORWARD);
            Motor_setSpeed(MOTOR_LEFT,MOTOR_SPEED_HALF);
            Motor_setSpeed(MOTOR_RIGHT,MOTOR_SPEED_HALF);

        }else if(byte == 'b' || byte == 'B'){

            Motor_setDirection(MOTOR_RIGHT,MOTOR_DIRECTION_BACKWARD);
            Motor_setDirection(MOTOR_LEFT,MOTOR_DIRECTION_BACKWARD);
            Motor_setSpeed(MOTOR_LEFT,MOTOR_SPEED_HALF);
            Motor_setSpeed(MOTOR_RIGHT,MOTOR_SPEED_HALF);

        }else if(byte == 'r' || byte == 'R'){

            Motor_setDirection(MOTOR_RIGHT,MOTOR_DIRECTION_STOP);
            Motor_setDirection(MOTOR_LEFT,MOTOR_DIRECTION_FORWARD);
            Motor_setSpeed(MOTOR_LEFT,MOTOR_SPEED_QUARTER);

        }else if(byte == 'l' || byte == 'L'){

            Motor_setDirection(MOTOR_RIGHT,MOTOR_DIRECTION_FORWARD);
            Motor_setDirection(MOTOR_LEFT,MOTOR_DIRECTION_STOP);
            Motor_setSpeed(MOTOR_RIGHT,MOTOR_SPEED_QUARTER);

        }else if(byte == 's' || byte == 'S'){
            Motor_setDirection(MOTOR_RIGHT , MOTOR_DIRECTION_STOP);
            Motor_setDirection(MOTOR_LEFT , MOTOR_DIRECTION_STOP);
        }else{
            // do nothing
        }

        counter = 0;
        _delay_ms(10);
    }
}