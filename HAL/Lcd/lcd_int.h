/*
 * lcd_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: DELL
 */
#include "../../LIB/STD_Types.h"

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define  LCD_COL0 0x0
#define  LCD_COL1 0x1
#define  LCD_COL2 0x02
#define  LCD_COL3 0x03
#define  LCD_COL4 0x04
#define  LCD_COL5 0x05
#define  LCD_COL6 0x06
#define  LCD_COL7 0x07
#define  LCD_COL8 0x08
#define  LCD_COL9 0x09
#define  LCD_COL10 0xA
#define  LCD_COL11 0xB
#define  LCD_COL12 0xC
#define  LCD_COL13 0xD
#define  LCD_COL14 0xE
#define  LCD_COL15 0xF


#define  LCD_ROW0 0x0
#define  LCD_ROW1 0x1

#define LCD_CLEAR              0x01
#define LCD__HOME              0x02
#define LCD_ENTRY_MODE         0x06
#define LCD_DISPLAY_OFF        0x08
#define LCD_DISPLAY_ON         0x0C
#define LCD_FUNCTION_RESET     0x30
#define LCD_FUNCTION_SET_8BIT  0x38
#define LCD_SET_CURSOR         0x80
/*prototypes*/

void LCD_vidInit(void);

void LCD_vidSendCommand(u8 u8CmdCopy);

void LCD_vidWriteChar (u8 u8DataCopy);

void LCD_vidWriteString (u8* pu8StringCopy);

void LCD_VidGotoRawCol (u8 u8RawCopy, u8 u8ColCopy);

void LCD_vid_num_to_str(u8 u8NumCopy);

#endif /* HAL_LCD_LCD_INT_H_ */
