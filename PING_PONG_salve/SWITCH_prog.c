/*
 * SWITCH_prog.c
 *
 *  Created on: Nov 5, 2023
 *      Author: bagiz
 */

#include "STD_TYPES.h"
#include "bit_math.h"
#include "DIO_interface.h"
#include "SWITCH_interface.h"



ErrorState SWITCH_u8GetState(const switch_config_t * switch_obj , uint8 *Copy_u8State)
{
	ErrorState Local_u8ErrorState;
	if(switch_obj == NULL || Copy_u8State == NULL)
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{
		DIO_u8ReadPinValue(switch_obj->port,switch_obj->pin,Copy_u8State);

		if(switch_obj->pull==PULL_UP)
		{
			if(*Copy_u8State==DIO_u8PIN_LOW)
			{
				*Copy_u8State=BUTTON_PRESSED;
			}
			else if(*Copy_u8State==DIO_u8PIN_HIGH)
			{
				*Copy_u8State=BUTTON_RELEASED;
			}
		}

		else if (switch_obj->pull==PULL_DOWN)
		{

			if(*Copy_u8State==DIO_u8PIN_HIGH)
			{
				*Copy_u8State=BUTTON_PRESSED;
			}

			else if(*Copy_u8State==DIO_u8PIN_LOW)
			{
				*Copy_u8State=BUTTON_RELEASED;
			}
		}

	}

	return Local_u8ErrorState;
}
