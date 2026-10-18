#ifndef MOTOR_H
#define MOTOR_H

#define MOTOR_COUNT 2

typedef enum {MOTOR_LEFT , MOTOR_RIGHT} Motor_id;
typedef enum {MOTOR_SPEED_QUARTER=25 , MOTOR_SPEED_HALF=50 , MOTOR_SPEED_THREEQUARTERS=75 , MOTOR_SPEED_FULL=99} Motor_speed_t;
typedef enum {MOTOR_DIRECTION_FORWARD , MOTOR_DIRECTION_BACKWARD , MOTOR_DIRECTION_STOP} Motor_direction_t;
typedef enum {MOTOR_OK , MOTOR_NOK} Motor_ErrorStatus;

 
Motor_ErrorStatus Motor_setSpeed(Motor_id id, Motor_speed_t speed);
Motor_ErrorStatus Motor_setDirection(Motor_id id, Motor_direction_t speed);

#endif