/*
 * CLCD_prog.c
 *
 *  Created on: Oct 31, 2023
 *      Author: bagiz
 */

#include "STD_TYPES.h"
#include "bit_math.h"
#include "ErrType.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"



static void CLCD_voidSendEnablePusle(void)
{
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_u8PIN_LOW);
}

#if CLCD_u8BIT_MODE==FOUR_BIT
static void CLCD_voidSend4Bits(uint8 Copy_u8Command)
{
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D4_PIN,GET_BIT(Copy_u8Command,0));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D5_PIN,GET_BIT(Copy_u8Command,1));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D6_PIN,GET_BIT(Copy_u8Command,2));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D7_PIN,GET_BIT(Copy_u8Command,3));

}
#endif










void CLCD_voidInit(void)
{



	/* Wait for more than 30ms after power on*/
	/* Wait for more than 30ms after VDD rises to 4.5V */
		_delay_ms(40);

#if CLCD_u8BIT_MODE == EIGHT_BIT
		/*Function Set command : 2 lines , font size 5*11*/
		CLCD_voidSendCommand(0b00111000);

#elif CLCD_u8BIT_MODE == FOUR_BIT
		CLCD_voidSend4Bits(0b0010);
		CLCD_voidSendEnablePusle();
		CLCD_voidSend4Bits(0b0010);
		CLCD_voidSendEnablePusle();
		CLCD_voidSend4Bits(0b1000);
		CLCD_voidSendEnablePusle();
#endif

	/*Display on off control : Display on, cursor off, blink cursor off*/
		CLCD_voidSendCommand(0b00001100);

	/*Clear display*/

    	CLCD_voidSendCommand(CLCD_CLEAR);

}




void CLCD_voidSendCommand(uint8 Copy_u8Command)
{

	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_u8PIN_LOW);
#if CLCD_u8RW_CONN_STS==DIO_CONNECTED
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_u8PIN_LOW);
#endif

#if	  CLCD_u8BIT_MODE ==EIGHT_BIT

	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Command);

	/*Send enable pulse*/
	CLCD_voidSendEnablePusle();

#elif CLCD_u8BIT_MODE ==FOUR_BIT
	/*Send the 4 most most significant of the command first*/
	CLCD_voidSend4Bits(Copy_u8Command>>4);

	CLCD_voidSendEnablePusle();

	/*Send the 4 least   significant of the command first*/
	CLCD_voidSend4Bits(Copy_u8Command);

	CLCD_voidSendEnablePusle();
#else
#error wrong CLCD_u8BIT_MODE configuration option

#endif
}

void CLCD_voidSendData(uint8 Copy_u8Data)
{

	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_u8PIN_HIGH);

#if CLCD_u8RW_CONN_STS==DIO_CONNECTED
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_u8PIN_LOW);
#endif

#if	  CLCD_u8BIT_MODE ==EIGHT_BIT

	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Data);

	/*Send enable pulse*/
	CLCD_voidSendEnablePusle();

#elif CLCD_u8BIT_MODE ==FOUR_BIT
	/*Send the 4 most most significant of the command first*/
	CLCD_voidSend4Bits(Copy_u8Data>>4);

	CLCD_voidSendEnablePusle();

	/*Send the 4 least   significant of the command first*/
	CLCD_voidSend4Bits(Copy_u8Data);

	CLCD_voidSendEnablePusle();

#else
#error

#endif
}


void CLCD_voidSendDataPos(uint8 Copy_u8Row, uint8 Copy_u8Column, uint8 Local_u8Data)
{
	CLCD_u8GoToXY(Copy_u8Row,Copy_u8Column);
	CLCD_voidSendData(Local_u8Data);
}

ErrorState CLCD_voidSendString(const char * Copy_pu8Str)
{
	ErrorState Local_u8ErrorState=OK;
	if(Copy_pu8Str != NULL)
	{

		while(*Copy_pu8Str != '\0')
		{
			CLCD_voidSendData(*Copy_pu8Str++);
			_delay_ms(5);
		}
	}
	else
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

ErrorState CLCD_voidSendStringPos(uint8 Copy_u8Row, uint8 Copy_u8Column, const char * Copy_pu8Str)
{
	ErrorState Local_u8ErrorState=OK;

	Local_u8ErrorState=CLCD_u8GoToXY(Copy_u8Row,Copy_u8Column);

	Local_u8ErrorState=CLCD_voidSendString(Copy_pu8Str);

	return Local_u8ErrorState;
}


void CLCD_voidDisplayNumber(sint32 Copys32Number)
{
	sint32  Local_u32Reminder,Local_u32Reverse=0,Local_u32NewN,Local_u32Length=0;
	sint8 Local_u8Counter;
	Local_u32NewN=Copys32Number;
	if(Copys32Number==0)
	{
		CLCD_voidSendData('0');
		return;
	}
	while(Local_u32NewN!=0)
	{
		Local_u32Length++;
		Local_u32NewN/=10;
	}

	while (Copys32Number != 0)
	{
		Local_u32Reminder=Copys32Number%10;
		Local_u32Reverse=Local_u32Reverse*10+Local_u32Reminder;
		Copys32Number /= 10;
	}

	if(Local_u32Reverse<0)
	{
		CLCD_voidSendData('-');
		Local_u32Reverse*=-1;
	}

	for(Local_u8Counter=0;Local_u8Counter<Local_u32Length;Local_u8Counter++)
	{
		CLCD_voidSendData((Local_u32Reverse%10)+'0');
		Local_u32Reverse/=10;
	}

}

ErrorState CLCD_u8GoToXY(uint8 Copy_u8Row, uint8 Copy_u8Column)
{

	ErrorState Local_u8ErrorState =OK;

	Copy_u8Column--;
	switch(Copy_u8Row)
	{

	case CLCD_u8ROW1: CLCD_voidSendCommand(( 0x80 + Copy_u8Column )); break;
	case CLCD_u8ROW2: CLCD_voidSendCommand(( 0xc0 + Copy_u8Column )); break;

	default : Local_u8ErrorState= NOT_OK ;
	}

	return Local_u8ErrorState;

}


ErrorState CLCD_u8SendSpecialCharacter(uint8 Copy_u8Location,uint8 *Copy_pu8Pattern,uint8 Copy_u8XPos,uint8 Copy_u8YPos)
{

	ErrorState Local_u8ErrorState =OK;
	if(Copy_pu8Pattern != NULL)
	{
		sint8 Local_u8Counter;
		uint8 Local_u8CGRAMAddress =Copy_u8Location * 8;

		/**/
		SET_BIT(Local_u8CGRAMAddress,6u);

		CLCD_voidSendCommand(Local_u8CGRAMAddress);

		for(Local_u8Counter=0u; Local_u8Counter<8u ;Local_u8Counter++ )
		{
			CLCD_voidSendData(Copy_pu8Pattern[Local_u8Counter]);
		}

		CLCD_u8GoToXY(Copy_u8XPos,Copy_u8YPos);

		CLCD_voidSendData(Copy_u8Location);
	}
	else
	{
		Local_u8ErrorState=NOT_OK;
	}
	return Local_u8ErrorState;
}
