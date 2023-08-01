/*
 * key_pad_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */

#ifndef HAL_KEY_PAD_KEY_PAD_CFG_H_
#define HAL_KEY_PAD_KEY_PAD_CFG_H_

#define KPD_PORT_PINS  PORTA
#define KPD_COL_INIT    4      /*first coloumn is at pin4*/
#define KPD_COL_FIN     8      /*LAST coloumn is at pin7*/
#define KPD_ROW_INIT    0      /*first coloumn is at pin0*/
#define KPD_ROW_FIN     4      /*LAST coloumn is at pin4*/

const u8 u8_KPD_switchVal[4][4]=
{
		{
				0x07,  /*row 0  column 0 */
				0x04,  /*row 1  column 0 */
				0x01,  /*row 2  column 0 */
				0x0A   /*row 3  column 0 */
		},
		{
				0x08,  /*row 0  column 1 */
				0x05,  /*row 1  column 1 */
				0x02,  /*row 2  column 1 */
				0x00   /*row 3  column 1 */
		},
		{
				0x09,
				0x06,
				0x03,
				0x0B
		},
		{
				0x01,
				0x05,
				0x09,
				0x0D
		}


};

/*
const u8 u8_KPD_switchVal[4][4]=
{
		{7,4,1,'c'},
		{8,5,2,0},
		{9,6,3,'='},
		{'/','*','-','+'}
};
*/
#endif /* HAL_KEY_PAD_KEY_PAD_CFG_H_ */
