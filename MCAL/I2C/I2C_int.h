/*
 * I2C_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef MCAL_I2C_I2C_INT_H_
#define MCAL_I2C_I2C_INT_H_

#define READ 1
#define WRITE 0

void I2C_init_vid_Master(void);
void I2C_init_vid_Slave(void);

void I2C_Send_start_vid(void);
void I2C_Send_Repeat_start_vid(void);

void I2C_Send_Slave_address0_vid(u8 u8SlaveAddCopy,u8 u8RW);

void I2C_Send_stop_vid(void);

void I2C_Send_Data_vid(u8 u8DataCopy);
u8 I2C_Recieve_Data_u8(void);

u8 I2C_check_status_u8(u8 u8ExpecteStatusCopy);

#endif /* MCAL_I2C_I2C_INT_H_ */
