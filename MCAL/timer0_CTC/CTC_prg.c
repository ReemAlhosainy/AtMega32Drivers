/*
 * timer0_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../GIE/GIE_int.h"
#include "../../HAL/LED/LED_int.h"
#include "../timer0_CTC/CTC_cfg.h"
#include "../timer0_CTC/CTC_pri.h"

u16 u16overflowCounter=0;

void timer0_CTC_init_vid(void)
{
    SET_BIT(TCCR0,0);
 	CLR_BIT(TCCR0,1);
    SET_BIT(TCCR0,2);
	OCR0=245;
	TCNT0=0;     /*PRELOAD VALUE*/
	GIE_vid_enable();  /*Global interrupt enable*/
	SET_BIT(TCCR0,7);
	SET_BIT(TCCR0,3);
	SET_BIT(TIMSK,1);  /*PIE: timer ctc interrupt enable*/

}

void __vector_10(void)
{
	if(u16overflowCounter==4) /*reached to one second*/
	{
		u16overflowCounter=0;

		LED_Toggle_vid(PORTC,PIN0);
	}
	u16overflowCounter++;
}
