/*
 * RTO_prg.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#define F_CPU 8000000UL

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "RTO_int.h"
#include "RTO_cfg.h"
#include "RTO_pri.h"
#include "../../MCAL/timer0_CTC/CTC_int.h"


RTO_TCB RTO_AStrTasks[RTO_u8_MAX_NUMBER_TASKS];

void RTO_vid_init(void)
{
	//set scheduler as call back function after tick time
    MTIMERS_vid_Timer0CTC_SET_Call_Back(&(RTO_vid_SCheduler));

    //starting os by starting timer
    timer0_CTC_init_vid();
}
void RTO_vid_SCheduler(void)
{
	u8 u8local_Counter;
	for(u8local_Counter=0;u8local_Counter<RTO_u8_MAX_NUMBER_TASKS;u8local_Counter++)
	{
		if(RTO_AStrTasks[u8local_Counter].FirstDelay==0)
		{
		RTO_AStrTasks[u8local_Counter].pf();
		RTO_AStrTasks[u8local_Counter].FirstDelay=RTO_AStrTasks[u8local_Counter].Periodicity-1;
		}
		else
		{
			RTO_AStrTasks[u8local_Counter].FirstDelay--;
		}
	}
}

void RTO_vid_CreateTask(u8 u8Priority_Copy,u16 u16Periodicity_Copy, u16 u16FirstDelay_Copy,void (*pf)(void))
{
	if((u8Priority_Copy <RTO_u8_MAX_NUMBER_TASKS) && (pf != NULL))
	{
		RTO_AStrTasks[u8Priority_Copy].FirstDelay=u16FirstDelay_Copy;
		RTO_AStrTasks[u8Priority_Copy].Periodicity=u16Periodicity_Copy;
		RTO_AStrTasks[u8Priority_Copy].pf=pf;

	}
}
