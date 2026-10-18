#ifndef PWM_PRIVATE
#define PWM_PRIVATE

#include"../../lib/std_types.h"

/* ---------- Settings ---------- */
#define PWM_TOP              999U  /* ICR1 value: 8MHz / (8 x 1000) = 1 kHz PWM */
#define PWM_MAX_DUTY         100U  /* duty is given in percent (0..100)          */
#define PWM_DUTY_SCALE       10U   /* percent -> OCR: 50% x 10 = 500 (out of 999) */

/* ---------- TCCR1A bits ---------- */
#define PWM_COM1A1_BIT       7     /* COM1A = 10 -> non-inverting on OC1A (PD5) */
#define PWM_COM1A0_BIT       6
#define PWM_COM1B1_BIT       5     /* COM1B = 10 -> non-inverting on OC1B (PD4) */
#define PWM_COM1B0_BIT       4
#define PWM_WGM11_BIT        1     /* mode 14 needs WGM11 = 1                    */
#define PWM_WGM10_BIT        0     /* mode 14 needs WGM10 = 0                    */

/* ---------- TCCR1B bits ---------- */
#define PWM_WGM13_BIT        4     /* mode 14 needs WGM13 = 1                    */
#define PWM_WGM12_BIT        3     /* mode 14 needs WGM12 = 1                    */
#define PWM_CS12_BIT         2     /* CS = 010 -> clk/8, starts the timer!       */
#define PWM_CS11_BIT         1     /*            set these LAST                  */
#define PWM_CS10_BIT         0


#define TCCR1A_REG *((volatile u8*) 0x4F)
#define TCCR1B_REG *((volatile u8*) 0x4E)
#define OCR1AH_REG *((volatile u8*) 0x4B)
#define OCR1AL_REG *((volatile u8*) 0x4A)
#define OCR1BH_REG *((volatile u8*) 0x49)
#define OCR1BL_REG *((volatile u8*) 0x48)
#define ICR1H_REG *((volatile u8*) 0x47)
#define ICR1L_REG *((volatile u8*) 0x46)

#endif