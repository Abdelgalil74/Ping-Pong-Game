/*
 * DC_MOTOR.c
 *
 *  Created on: Nov 26, 2023
 *      Author: bagiz
 */

#include "STD_TYPES.h"
#include "bit_math.h"
#include "DIO_interface.h"
#include "DC_MOTOR_interface.h"

/* This driver available to Motor connected to 2 relays		 H-bridge
 * 						and Motor connected to 4 transistors H-bridge
 */



ErrorState Motor_voidRotateCW(motor_config * Motor)
{
	ErrorState Local_u8ErrorState;


	if(NULL==Motor)
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{

		DIO_u8SetPinValue(Motor->port,Motor->pin2,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Motor->port,Motor->pin1,DIO_u8PIN_HIGH);
	}
	return Local_u8ErrorState;

}


ErrorState Motor_voidRotateCCW(motor_config * Motor)
{
	ErrorState Local_u8ErrorState;
	if(NULL==Motor)
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{
		DIO_u8SetPinValue(Motor->port,Motor->pin1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Motor->port,Motor->pin2,DIO_u8PIN_HIGH);
	}

	return Local_u8ErrorState;
}

ErrorState Motor_voidStop(motor_config * Motor)
{
	ErrorState Local_u8ErrorState;
	if(NULL==Motor)
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	else
	{
		DIO_u8SetPinValue(Motor->port,Motor->pin1,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Motor->port,Motor->pin2,DIO_u8PIN_LOW);
	}
	return Local_u8ErrorState;

}
