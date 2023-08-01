/*
 * RTO_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef SERVICES_RTO_RTO_INT_H_
#define SERVICES_RTO_RTO_INT_H_
#include "../../LIB/STD_Types.h"
void RTO_vid_init(void);
void RTO_vid_SCheduler(void);
void RTO_vid_CreateTask(u8 u8Priority_Copy,u16 u16Periodicity_Copy, u16 u16FirstDelay_Copy,void (*pf)(void));


#endif /* SERVICES_RTO_RTO_INT_H_ */
