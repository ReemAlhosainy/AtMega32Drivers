/*
 * timer0_pri.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef MCAL_TIMER0_CTC_CTC_PRI_H_I_H_
#define fMCAL_TIMER0_CTC_CTC_PRI_H_C_PRI_H_

#define TCNT0 *((volatile u8*)0x52)
#define OCR0 *((volatile u8*)0x5C)
#define TIMSK *((volatile u8*)0x59)
//#define TIFR *((volatile u8*)0x58)
#define TCCR0 *((volatile u8*)0x53)


void __vector_10(void) __attribute__((signal)); /*for time ctc for INT0*/


#endif /* MCAL_TIMER0_CTC_CTC_PRI_H_C_CTC_PRI_H_*/
