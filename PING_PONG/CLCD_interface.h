/*
 * CLCD_interface.h
 *
 *  Created on: Oct 31, 2023
 *      Author: bagiz
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


#define CLCD_CLEAR                                  0X01
#define CLCD_RETURN_HOME                            0x02
#define CLCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF    0x0C
#define CLCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON     0x0D
#define CLCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF     0x0E
#define CLCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON      0x0F


#define  CLCD_u8ROW1    1
#define  CLCD_u8ROW2	2







void CLCD_voidSendCommand(uint8 Copy_u8Command);
void CLCD_voidInit(void);
void CLCD_voidSendData(uint8 Local_u8Data);
void CLCD_voidSendDataPos(uint8 Copy_u8Row, uint8 Copy_u8Column, uint8 Local_u8Data);
ErrorState CLCD_voidSendString(const char * Copy_pu8Str);
ErrorState CLCD_voidSendStringPos(uint8 Copy_u8Row, uint8 Copy_u8Column, const char * Copy_pu8Str);
void CLCD_voidDisplayNumber(sint32 Localu8Number);
ErrorState CLCD_u8GoToXY(uint8 Copy_u8Row, uint8 Copy_u8Column);
ErrorState CLCD_u8SendSpecialCharacter(uint8 Copy_u8Location,uint8 *Copy_pu8Pattern,uint8 Copy_u8XPos,uint8 Copy_u8YPos);
#endif /* CLCD_INTERFACE_H_ */
