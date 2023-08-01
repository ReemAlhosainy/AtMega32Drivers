/*
 * timer0_pri.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef MCAL_TIMER1_PWM_TIMER1PWM_PRI_H_
#define MCAL_TIMER1_PWM_TIMER1PWM_PRI_H_

#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)

#define TCNT1H *((volatile u8*)0x4D)
#define TCNT1L *((volatile u8*)0x4C)

#define TCNT1 *((volatile u16*)0x4C)

#define ICR1L *((volatile u8*)0x46)
#define ICR1H *((volatile u8*)0x47)
#define ICR1 *((volatile u16*)0x46)

#define OCR1AH *((volatile u8*)0x4B)
#define OCR1AL *((volatile u8*)0x4A)
#define OCR1A *((volatile u16*)0x4A)

#define OCR1BH *((volatile u8*)0x49)
#define OCR1BL *((volatile u8*)0x48)
#define OCR1B  *((volatile u16*)0x48)


//void __vector_11(void) __attribute__((signal)); /*for time overflow for INT0*/


#endif /* MCAL_TIMER1_PWM_TIMER1PWM_PRI_H_ */
