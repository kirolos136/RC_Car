#include"motor_config.h"
#include"motor_interface.h"
#include"../../MCAL/PWM/PWM_interface.h"

extern Motor_config_t motors[];

Motor_ErrorStatus Motor_init(void){
    PWM_ErrorStatus pes = PWM_Init();

    if(pes == PWM_NOK) return MOTOR_NOK;

    DIO_ErrorStatus des = DIO_setPinDirection(motors[MOTOR_LEFT].In_a.port,motors[MOTOR_LEFT].In_a.Pin,DIO_OUTPUT);
    if(des == DIO_NOK) return MOTOR_NOK;

    des = DIO_setPinDirection(motors[MOTOR_LEFT].In_b.port,motors[MOTOR_LEFT].In_b.Pin,DIO_OUTPUT);
    if(des == DIO_NOK) return MOTOR_NOK;

    des = DIO_setPinDirection(motors[MOTOR_RIGHT].In_a.port,motors[MOTOR_RIGHT].In_a.Pin,DIO_OUTPUT);
    if(des == DIO_NOK) return MOTOR_NOK;

    des = DIO_setPinDirection(motors[MOTOR_RIGHT].In_b.port,motors[MOTOR_RIGHT].In_b.Pin,DIO_OUTPUT);
    if(des == DIO_NOK) return MOTOR_NOK;

    des = DIO_setPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);   /* OC1A -> ENA */
    if(des == DIO_NOK) return MOTOR_NOK;
    
    des = DIO_setPinDirection(DIO_PORTD, DIO_PIN4, DIO_OUTPUT);   /* OC1B -> ENB */
    if(des == DIO_NOK) return MOTOR_NOK;

    return MOTOR_OK;
}

Motor_ErrorStatus Motor_setSpeed(Motor_id id, Motor_speed_t speed){
    if( speed != MOTOR_SPEED_QUARTER && speed != MOTOR_SPEED_HALF && speed != MOTOR_SPEED_THREEQUARTERS && speed != MOTOR_SPEED_FULL) return MOTOR_NOK;
    if(id > 1) return MOTOR_NOK;

    PWM_ErrorStatus pes;
    if(id == MOTOR_LEFT){
        pes = PWM_SetDuty(motors[MOTOR_LEFT].channel , speed);
    }else if(id == MOTOR_RIGHT){
        pes = PWM_SetDuty(motors[MOTOR_RIGHT].channel , speed);
    }else{
        return MOTOR_NOK;
    }

    if(pes == PWM_OK) return MOTOR_OK;
    else return MOTOR_NOK;    
}

Motor_ErrorStatus Motor_setDirection(Motor_id id, Motor_direction_t dir){
    if(id > 1) return MOTOR_NOK;

    if(id == MOTOR_LEFT){
        if(dir == MOTOR_DIRECTION_FORWARD){
            DIO_setPinValue(motors[MOTOR_LEFT].In_a.port,motors[MOTOR_LEFT].In_a.Pin,DIO_HIGH);
            DIO_setPinValue(motors[MOTOR_LEFT].In_b.port,motors[MOTOR_LEFT].In_b.Pin,DIO_LOW);
        }else if(dir == MOTOR_DIRECTION_BACKWARD){
            DIO_setPinValue(motors[MOTOR_LEFT].In_a.port,motors[MOTOR_LEFT].In_a.Pin,DIO_LOW);
            DIO_setPinValue(motors[MOTOR_LEFT].In_b.port,motors[MOTOR_LEFT].In_b.Pin,DIO_HIGH);
        }else if(dir == MOTOR_DIRECTION_STOP){
            DIO_setPinValue(motors[MOTOR_LEFT].In_a.port,motors[MOTOR_LEFT].In_a.Pin,DIO_LOW);
            DIO_setPinValue(motors[MOTOR_LEFT].In_b.port,motors[MOTOR_LEFT].In_b.Pin,DIO_LOW);
        }else{
            return MOTOR_NOK;
        }
    }else if(id == MOTOR_RIGHT){
        if(dir == MOTOR_DIRECTION_FORWARD){
            DIO_setPinValue(motors[MOTOR_RIGHT].In_a.port,motors[MOTOR_RIGHT].In_a.Pin,DIO_HIGH);
            DIO_setPinValue(motors[MOTOR_RIGHT].In_b.port,motors[MOTOR_RIGHT].In_b.Pin,DIO_LOW);
        }else if(dir == MOTOR_DIRECTION_BACKWARD){
            DIO_setPinValue(motors[MOTOR_RIGHT].In_a.port,motors[MOTOR_RIGHT].In_a.Pin,DIO_LOW);
            DIO_setPinValue(motors[MOTOR_RIGHT].In_b.port,motors[MOTOR_RIGHT].In_b.Pin,DIO_HIGH);
        }else if(dir == MOTOR_DIRECTION_STOP){
            DIO_setPinValue(motors[MOTOR_RIGHT].In_a.port,motors[MOTOR_RIGHT].In_a.Pin,DIO_LOW);
            DIO_setPinValue(motors[MOTOR_RIGHT].In_b.port,motors[MOTOR_RIGHT].In_b.Pin,DIO_LOW);
        }else{
            return MOTOR_NOK;
        }
    }else{
        return MOTOR_NOK;
    }

    return MOTOR_OK;
}