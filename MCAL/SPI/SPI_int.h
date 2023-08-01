/*
 * SPI_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

void SPI_init_vid_MASTER(void);
void SPI_init_vid_SLAVE(void);

void SPI_send_byte_vid_MASTER(u8 u8ByteCopy);
void SPI_send_byte_vid_SLAVE(u8 u8ByteCopy);

u8 SPI_init_Recieve_BOTH(void);

void SPI_vid_send_MASTER_string(const u8*pu8bstringCopy);

void SPI_vid_recieve_string(u8*pu8bstringCopy);

void SPI_vid_send_SLAVE_string(const u8*pu8bstringCopy);

#endif /* MCAL_SPI_SPI_INT_H_ */
