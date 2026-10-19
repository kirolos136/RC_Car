#include "PWM_private.h"
#include "PWM_interface.h"
#include "../../LIB/bit_math.h"

PWM_ErrorStatus PWM_Init(void){
    //first com to be non inverting 
    SET_BIT(TCCR1A_REG , PWM_COM1A1_BIT);
    CLR_BIT(TCCR1A_REG , PWM_COM1A0_BIT);
    SET_BIT(TCCR1A_REG , PWM_COM1B1_BIT);
    CLR_BIT(TCCR1A_REG , PWM_COM1B0_BIT);

    // setting mode 14 in WGM 
    SET_BIT(TCCR1A_REG , PWM_WGM11_BIT);
    CLR_BIT(TCCR1A_REG, PWM_WGM10_BIT);
    SET_BIT(TCCR1B_REG , PWM_WGM13_BIT);
    SET_BIT(TCCR1B_REG , PWM_WGM12_BIT);

    //setting top value
    ICR1H_REG = (PWM_TOP >> 8);
    ICR1L_REG = ((u8) PWM_TOP);
    
    // setting the prescaler (clk/8)
    CLR_BIT(TCCR1B_REG , PWM_CS12_BIT);
    SET_BIT(TCCR1B_REG , PWM_CS11_BIT);
    CLR_BIT(TCCR1B_REG , PWM_CS10_BIT);

    return PWM_OK;
}

PWM_ErrorStatus PWM_SetDuty(PWM_Channel_t c,u8 duty){
    if(duty >= PWM_MAX_DUTY) return PWM_NOK;

    u16 dutyScaled = duty * PWM_DUTY_SCALE;

    if(c == PWM_CHANNEL_A){
        OCR1AH_REG = ((u8) (dutyScaled >> 8));
        OCR1AL_REG = (u8) dutyScaled;
    }else{
        OCR1BH_REG = ((u8) (dutyScaled >> 8));
        OCR1BL_REG = (u8) dutyScaled;
    }

    return PWM_OK;
}