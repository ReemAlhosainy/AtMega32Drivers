/*
 * ADC_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "ADC_pri.h"
#include "ADC_int.h"
#include "avr/delay.h"
#include "../../LIB/STD_Types.h"
#include "../../LIB/BITT_Math.h"
#include "../DIO/DIO_int.h"
#include "../timer1_PWM/timer1PWM_int.h"
#define NULL 0
void (*CallBackPtr)(void)=NULL;

u32 u8ADC_Channel_Reading(u8 u8ChannelReadCopy)
{
	ADMUX&=0b11100000;
	ADMUX|=u8ChannelReadCopy;

	SET_BIT(ADCSRA,6);   /*start conversion*/
	while(GET_BIT(ADCSRA,4)==0);
	SET_BIT(ADCSRA,4); /*clear the flag==set the bit 1*/

	return ADC_DATA;
}

void ADC_init(void)
{

//	/*8 bit mode , aVcc ref voltage polling (not interrupt)*/
//	CLR_BIT(ADMUX,7);

	/*8 bit mode , aVcc ref voltage (interrupt)*/
	SET_BIT(ADMUX,7);


	SET_BIT(ADMUX,6);
	/*when interrupt is finished it will be cleared*/
	SET_BIT(ADCSRA,4);

	/*activate left adjust mode*/
	CLR_BIT(ADMUX,5);
	/*prescaller division by 128*/
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	/*interrupt enable*/
	SET_BIT(ADCSRA,3);

	/*ADC enable*/
	SET_BIT(ADCSRA,7);
}
/*set Call back function*/
void ADC_Set_CallBack( void (*CopyFuncPtr)(void))
{
	CallBackPtr=CopyFuncPtr;

}

void __vector_16(void)
{
	if(CallBackPtr != NULL)
	{
		CallBackPtr();

	}

}
