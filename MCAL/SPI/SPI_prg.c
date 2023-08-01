/*
 * SPI_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include "../DIO/DIO_int.h"
#include "SPI_pri.h"
#include "SPI_int.h"


u8 temp_SPCR=0b00000000;
void SPI_init_vid_MASTER(void)
{
	/*3 pins o/p     1pin i/p*/
	DIO_SetPinDirection(PORTB,PIN5,OUTPUT);
	 DIO_SetPinDirection(PORTB,PIN6,INPUT);
	 DIO_SetPinDirection(PORTB,PIN4,OUTPUT);
	 DIO_SetPinDirection(PORTB,PIN7,OUTPUT);
	SET_BIT(temp_SPCR,1);/*PRESCALLER*/
	SET_BIT(temp_SPCR,2);/**/
	SET_BIT(temp_SPCR,3);
	SET_BIT(temp_SPCR,4);
	SET_BIT(temp_SPCR,5);
	SET_BIT(temp_SPCR,6);
SPCR=temp_SPCR;


}

void SPI_init_vid_SLAVE(void)
{
	/*3 pins i/p     1pin o/p*/
 DIO_SetPinDirection(PORTB,PIN5,INPUT);
 DIO_SetPinDirection(PORTB,PIN6,OUTPUT);
 DIO_SetPinDirection(PORTB,PIN4,INPUT);/*SS*/
 DIO_SetPinDirection(PORTB,PIN7,INPUT);
		SET_BIT(temp_SPCR,2);
		SET_BIT(temp_SPCR,3);
		CLR_BIT(temp_SPCR,4);
		SET_BIT(temp_SPCR,5);
		SET_BIT(temp_SPCR,6);
		SPCR=temp_SPCR;




}

void SPI_send_byte_vid_MASTER(u8 u8ByteCopy)
{
  DIO_SetPinValue(PORTB,PIN4,LOW);
  SPDR=u8ByteCopy;
  while(GET_BIT(SPSR,7)==0);
  DIO_SetPinValue(PORTB,PIN4,HIGH);/*slave select*/

}

void SPI_send_byte_vid_SLAVE(u8 u8ByteCopy)
{
	SPDR=u8ByteCopy;
	  while(GET_BIT(SPSR,7)==0);
}

u8 SPI_init_Recieve_BOTH(void)
{
	while(GET_BIT(SPSR,7)==0);
		  return SPDR;
}

void SPI_vid_send_SLAVE_string(const u8*pu8bstringCopy)
{
	u8 i=0;
	while(pu8bstringCopy[i]!='\0')
	{
		SPI_send_byte_vid_SLAVE(pu8bstringCopy[i]);
		i++;
	}
}
void SPI_vid_send_MASTER_string(const u8*pu8bstringCopy)
{
	u8 i=0;
	while(pu8bstringCopy[i]!='\0')
	{
		SPI_send_byte_vid_MASTER(pu8bstringCopy[i]);
		i++;
	}
}
void SPI_vid_recieve_string(u8*pu8bstringCopy)
{
	u8 i=0;
	pu8bstringCopy[i]=SPI_init_Recieve_BOTH();

	while(pu8bstringCopy[i] !='#')
	{
		i++;
		pu8bstringCopy[i]=SPI_init_Recieve_BOTH();
	}

	pu8bstringCopy[i]='\0';
}
