/*
 * key_pad_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#include "../../LIB/BITT_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/DIO/DIO_pri.h"

#include "Key_pad_int.h"
#include "key_pad_cfg.h"
#include <avr/delay.h>

/*function definetion*/


void KPD_vidInit(void)
{
  	u8 u8PIN_ID_LOCAL;
  	/*set rows as inputs*/

  	for(u8PIN_ID_LOCAL =KPD_COL_INIT; u8PIN_ID_LOCAL<KPD_COL_FIN;u8PIN_ID_LOCAL++)
  	  	{
  	  		DIO_SetPinDirection(KPD_PORT_PINS,u8PIN_ID_LOCAL,OUTPUT);    /*output coloumns*/
  	  		DIO_SetPinValue(KPD_PORT_PINS,u8PIN_ID_LOCAL,HIGH);
  	  	}
  	for(u8PIN_ID_LOCAL =KPD_ROW_INIT;u8PIN_ID_LOCAL<KPD_ROW_FIN;u8PIN_ID_LOCAL++)
  	{
  		DIO_SetPinDirection(KPD_PORT_PINS,u8PIN_ID_LOCAL,INPUT);    /*input rows*/
  		DIO_SetPinValue(KPD_PORT_PINS,u8PIN_ID_LOCAL,HIGH);       /*active pull up*/
  	}

}

u8 u8_key_pad_getpressedKey(void)
{
	u8 LOC_u8Column,LOC_u8Row;
	u8 LOC_u8_Return=KPD_NOT_PRESSED;
	for(LOC_u8Column=0+KPD_COL_INIT;LOC_u8Column<KPD_COL_FIN;LOC_u8Column++)
	{
		DIO_SetPinValue(KPD_PORT_PINS,LOC_u8Column,LOW);

		for(LOC_u8Row=0+KPD_ROW_INIT;LOC_u8Row<KPD_ROW_FIN;LOC_u8Row++)
	   {
		   if(DIO_GetPinValue(KPD_PORT_PINS,LOC_u8Row)==0)
		   {
			   LOC_u8_Return=u8_KPD_switchVal[LOC_u8Column-KPD_COL_INIT][LOC_u8Row-KPD_ROW_INIT];
              while(!DIO_GetPinValue(KPD_PORT_PINS,LOC_u8Row));
              _delay_ms(20);
		   }
	   }
       DIO_SetPinValue(KPD_PORT_PINS,LOC_u8Column,HIGH);
	}
return LOC_u8_Return;

}
