/*
 * DIO_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"
#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_
/*PORT defines*/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3


/*PIN defines*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
/*PIN directions*/
#define INPUT 0
#define OUTPUT 1
/*PIN value options*/
#define LOW 0
#define HIGH 1


/*prototypes*/
/*set pin is input or output */
void DIO_SetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinDirCopy);
/*if pin is output -set HIGH or LOW voltage*/
void DIO_SetPinValue (u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinValCopy);
/*if pin is input -get value*/
u8 DIO_GetPinValue (u8 u8PortIdCopy,u8 u8PinIdCopy);
void DIO_set_half_Port_dir(u8 u8PortIdCopy,u8 u8PinDirCopy);
void  DIO_SetPort_Value (u8 u8PortIdCopy,u8 u8PinValCopy);
void DIO_set_Fhalf_Port_Val(u8 u8PortIdCopy,u8 u8PinValCopy);

void DIO_SetPORTDirection (u8 u8PortIdCopy,u8 u8PinDirCopy);
#endif /* MCAL_DIO_DIO_INT_H_ */
