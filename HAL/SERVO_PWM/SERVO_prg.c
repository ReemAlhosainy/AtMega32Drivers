/*
 * SERVO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../MCAL/DIO/DIO_int.h"


void SERVO_init_vid(u8 u8PortIdCopy,u8 u8PinIdCopy)
{
DIO_SetPinDirection(u8PortIdCopy,u8PinIdCopy,OUTPUT);
}
