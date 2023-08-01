/*
 * EXTE_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../LIB/BITT_Math.h"
#include "../../LIB/STD_Types.h"
#include "EXTE_int.h"
#include "EXTE_confg.h"
#include "EXTE_pri.h"
#include"../DIO/DIO_int.h"
#include"../DIO/DIO_pri.h"

void EXTE_vid_init(void)
{
#if(ISC0==FALLING)
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
#elif(ISC0==RISING)
		SET_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);

#elif(ISC0==OCH)
		CLR_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);

#elif(ISC0==LOW_LEVEL)
		CLR_BIT(MCUCR,1);
		CLR_BIT(MCUCR,0);
#endif

#if(ISC2==FALLING)
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
#elif(ISC2==RISING)
		SET_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);

#elif(ISC2==OCH)
		CLR_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);

#elif(ISC2==LOW_LEVEL)
		CLR_BIT(MCUCR,1);
		CLR_BIT(MCUCR,0);
#endif

#if(ISC1==FALLING)
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
#elif(ISC1==RISING)
		SET_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);

#elif(ISC1==OCH)
		CLR_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);

#elif(ISC1==LOW_LEVEL)
		CLR_BIT(MCUCR,1);
		CLR_BIT(MCUCR,0);
#endif
}

void EXTE0_vid_disable(void)
{
	CLR_BIT(GICR,6);
}
void EXTE0_vid_enable(void)
{
	SET_BIT(GICR,6);
}

void EXTE1_vid_disable(void)
{
	CLR_BIT(GICR,7);

}
void EXTE1_vid_enable(void)
{
	SET_BIT(GICR,7);

}
/*2nd interrupt*/
void EXTE2_vid_disable(void)
{
	CLR_BIT(GICR,5);

}
void EXTE2_vid_enable(void)
{
	SET_BIT(GICR,5);

}
void __vector_1(void)
{
	/*PORTC_register^=(1<<0);*/
	TOG_BIT(PORTC_register,0);
	TOG_BIT(PORTC_register,5);
	TOG_BIT(PORTC_register,6);
}
