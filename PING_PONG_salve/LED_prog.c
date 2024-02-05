/*
 * LED_prog.c
 *
 *  Created on: Nov 5, 2023
 *      Author: bagiz
 */

#include "STD_TYPES.h"
#include "bit_math.h"
#include "DIO_reg.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include <util/delay.h>



ErrorState LED_u8SetON(const led_config_t * led_obj)
{
	ErrorState Local_u8ErrorState;
	if(NULL==led_obj)
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{
		if(led_obj->ActiveType==ACT_HIGH)
		DIO_u8SetPinValue(led_obj->port,led_obj->pin,DIO_u8PIN_HIGH);

		else if(led_obj->ActiveType==ACT_LOW)
		DIO_u8SetPinValue(led_obj->port,led_obj->pin,DIO_u8PIN_LOW);
	}
	return Local_u8ErrorState;
}


ErrorState LED_u8SetOFF(const led_config_t * led_obj)
{
	ErrorState Local_u8ErrorState;
	if(NULL==led_obj)
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{
		if(led_obj->ActiveType==ACT_HIGH)
		DIO_u8SetPinValue(led_obj->port,led_obj->pin,DIO_u8PIN_LOW);

		else if(led_obj->ActiveType==ACT_LOW)
		DIO_u8SetPinValue(led_obj->port,led_obj->pin,DIO_u8PIN_HIGH);
	}
	return Local_u8ErrorState;
}


ErrorState LED_u8SetToggle(const led_config_t * led_obj)
{
	ErrorState Local_u8ErrorState;
	if(NULL==led_obj)
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{
		DIO_u8TogglePinValue(led_obj->port,led_obj->pin);
	}
	return Local_u8ErrorState;
}
