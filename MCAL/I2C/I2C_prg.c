/*
 * I2C_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "I2C_pri.h"

void I2C_init_vid_Master(void)
{
	TWBR=2;
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);

	TWAR=2;/*address*/
	SET_BIT(TWCR,2);

}
void I2C_init_vid_Slave(void)
{
  TWAR=2;
  SET_BIT(TWCR,2);/*enable i2c peripheral*/
}

void I2C_Send_start_vid(void)
{
	TWCR=(1<<7) | (1<<5) | (1<<2);
	while(GET_BIT(TWCR,7)==0);

}
void I2C_Send_Repeat_start_vid(void)
{
	TWCR=(1<<7) | (1<<5) | (1<<2);
	while(GET_BIT(TWCR,7)==0);

}

void I2C_Send_Slave_address0_vid(u8 u8SlaveAddCopy,u8 u8RW)
{
	TWDR=(u8SlaveAddCopy<<1) | (u8RW);
	TWCR=(1<<7) |(1<<2);
	while(GET_BIT(TWCR,7)==0);

}

void I2C_Send_stop_vid(void)
{
	TWCR=(1<<7) | (1<<4) | (1<<2);
}

void I2C_Send_Data_vid(u8 u8DataCopy)
{
   TWDR=u8DataCopy;
	TWCR=(1<<7) |(1<<2);
	while(GET_BIT(TWCR,7)==0);

}
u8 I2C_Recieve_Data_u8(void)
{
	TWCR=(1<<7) |(1<<2);
	while(GET_BIT(TWCR,7)==0);
    return TWDR;
}

u8 I2C_check_status_u8(u8 u8ExpecteStatusCopy)
{
   u8 pass;
   if(u8ExpecteStatusCopy == (TWSR & 0xF8))
   {
	   pass=1;
   }else
   {
	   pass=0;
   }
   return pass;
}

