/*
 * I2C_pri.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Reem Ahmad
 */

#ifndef MCAL_I2C_I2C_PRI_H_
#define MCAL_I2C_I2C_PRI_H_
/*TWI=two wire serial interface*/

#define TWAR  *((volatile u8*)0x22)  /*TWI slave address register*/
#define TWBR  *((volatile u8*)0x20)  /*TWI Bit    rate   register*/
#define TWCR  *((volatile u8*)0x56)  /*TWI    control    register*/
#define TWDR  *((volatile u8*)0x23)  /*TWI      Data     register*/
#define TWSR  *((volatile u8*)0x21)  /*TWI     status    register*/



#endif /* MCAL_I2C_I2C_PRI_H_ */
