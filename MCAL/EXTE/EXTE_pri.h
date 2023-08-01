/*
 * EXTE_pri.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef MCAL_EXTE_EXTE_PRI_H_
#define MCAL_EXTE_EXTE_PRI_H_

#define     GICR     *((volatile u8*)0x5B)  /*enable register for EXIT 0 ,1 ,2*/
#define     MCUCR    *((volatile u8*)0x55)  /*SET state from 4 states(rising,falling,low level,any logical change)for EXTI0,EXTI1 */
#define     MCUCSR   *((volatile u8*)0x54)  /*SET state from 4 states(rising,falling,low level,any logical change)for EXTI2*/
/*FUNCTIONS ARE EXECUTED BUT NOT RUNNED*/
void __vector_1(void) __attribute__((signal)); /*ISR code formal for INT0*/
void __vector_2(void) __attribute__((signal)); /*ISR code formal for INT1*/
void __vector_3(void) __attribute__((signal)); /*ISR code formal for INT2*/

#endif /* MCAL_EXTE_EXTE_PRI_H_ */
