/*
 * timer0_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BITT_Math.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "timer1_PWM_cfg.h"
#include "timer1PWM_pri.h"

u8 u8overflowCounter=0;

void timer1_FAST_PWM_init_vid(void)
{
	TCNT1=0;
	ICR1=2499;

	  SET_BIT(TCCR1B,0);
	  SET_BIT(TCCR1B,1);

	  SET_BIT(TCCR1B,3);
	  SET_BIT(TCCR1B,4);


	  CLR_BIT(TCCR1A,0);
	  SET_BIT(TCCR1A,1);
	  SET_BIT(TCCR1A,7);

}

void Timer_set_dutyCycle(u16 Copy_u8_OCR1)
{
	OCR1A=Copy_u8_OCR1;

}




