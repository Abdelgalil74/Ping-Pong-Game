/*
 * KPD_prog.c
 *
 *  Created on: Nov 18, 2023
 *      Author: bagiz
 */

#include "ErrType.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"


uint8 KPD_8uGetPressedKey(void)
{
	uint8 Local_u8ColIdx,Local_u8RowIdx ,Local_u8PinState, Local_u8PressedKey=KPD_u8_NoPressedVal;



	uint8 Local_au8ColArr[COL_NUM]={KPD_u8COL0_PIN,KPD_u8COL1_PIN,KPD_u8COL2_PIN,KPD_u8COL3_PIN};
	uint8 Local_au8ROWArr[ROW_NUM]={KPD_u8ROW0_PIN,KPD_u8ROW1_PIN,KPD_u8ROW2_PIN,KPD_u8ROW3_PIN};

	uint8 Local_au8KPDARR[ROW_NUM][COL_NUM]=KPD_au8_BUTTON_ARR;

	for(Local_u8ColIdx=0u ; Local_u8ColIdx < COL_NUM ; Local_u8ColIdx++)
	{
		DIO_u8SetPinValue(KPD_u8COL_PORT,Local_au8ColArr[Local_u8ColIdx],DIO_u8PIN_LOW);


		for(Local_u8RowIdx=0u ; Local_u8RowIdx < ROW_NUM ; Local_u8RowIdx++)
		{
			DIO_u8ReadPinValue(KPD_u8ROW_PORT,Local_au8ROWArr[Local_u8RowIdx], &Local_u8PinState);

			if(Local_u8PinState==DIO_u8PIN_LOW)
			{
				Local_u8PressedKey=Local_au8KPDARR[Local_u8RowIdx][Local_u8ColIdx];

				//while(!DIO_u8ReadPinValue(KPD_u8COL_PORT,Local_au8ColArr[Local_u8RowIdx], &Local_u8PinState));


				 while(Local_u8PinState==DIO_u8PIN_LOW)
				 {
						DIO_u8ReadPinValue(KPD_u8ROW_PORT,Local_au8ROWArr[Local_u8RowIdx], &Local_u8PinState);
				 }


				return Local_u8PressedKey;

			}

		}

		DIO_u8SetPinValue(KPD_u8COL_PORT,Local_au8ColArr[Local_u8ColIdx],DIO_u8PIN_HIGH);
	}


	return Local_u8PressedKey;



}
