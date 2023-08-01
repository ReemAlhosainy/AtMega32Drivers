/*
 * GIE_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"

#include"../DIO/DIO_int.h"
#include"GIE_pri.h"
void GIE_vid_enable(void)
{
	SET_BIT(SREG,7);
}

void GIE_vid_disable(void)
{
	CLR_BIT(SREG,7);

}
