/*
 * RTO_pri.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef SERVICES_RTO_RTO_PRI_H_
#define SERVICES_RTO_RTO_PRI_H_

typedef struct
{
	u16 FirstDelay;
	u16 Periodicity;
	void (*pf)(void);
}RTO_TCB;


#endif /* SERVICES_RTO_RTO_PRI_H_ */
