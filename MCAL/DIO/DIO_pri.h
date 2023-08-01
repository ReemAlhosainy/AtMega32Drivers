/*
 * DIO_pri.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef MCAL_DIO_DIO_PRI_H_
#define MCAL_DIO_DIO_PRI_H_

/*Group A Registers*/
#define PORTA_register *((volatile u8*)0x3B)
#define DDRA_register *((volatile u8*)0x3A)
#define PINA_register *((volatile u8*)0x39)

/*Group B Registers*/
#define PORTB_register *((volatile u8*)0x38)
#define DDRB_register *((volatile u8*)0x37)
#define PINB_register *((volatile u8*)0x36)

/*Group C Registers*/
#define PORTC_register *((volatile u8*)0x35)
#define DDRC_register *((volatile u8*)0x34)
#define PINC_register *((volatile u8*)0x33)

/*Group D Registers*/
#define PORTD_register *((volatile u8*)0x32)
#define DDRD_register *((volatile u8*)0x31)
#define PIND_register *((volatile u8*)0x30)
#endif /* MCAL_DIO_DIO_PRI_H_ */
