/*
 * DIO_interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: bagiz
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "ErrType.h"

typedef enum
{
	DIO_u8PORTA,
	DIO_u8PORTB,
	DIO_u8PORTC,
	DIO_u8PORTD
}port_index;


typedef enum
{
	DIO_u8PIN0,
	DIO_u8PIN1,
	DIO_u8PIN2,
	DIO_u8PIN3,
	DIO_u8PIN4,
	DIO_u8PIN5,
	DIO_u8PIN6,
	DIO_u8PIN7
}pin_index;

typedef enum
{
	DIO_u8PIN_INPUT,
	DIO_u8PIN_OUTPUT
}dirction_t;

typedef enum
{
	DIO_u8PIN_LOW,
	DIO_u8PIN_HIGH
}logic_t;

#define DIO_u8PORT_INPUT      0x00
#define DIO_u8PORT_OUTPUT     0xff

#define DIO_u8PORT_LOW        0x00
#define DIO_u8PORT_HIGH		  0xff


ErrorState  DIO_u8SetPinDirection(port_index Copy_u8Port,pin_index Copy_u8Pin,dirction_t Copy_u8Direction );
ErrorState  DIO_u8SetPinValue(port_index Copy_u8Port,pin_index Copy_u8Pin,logic_t Copy_u8Value );
ErrorState  DIO_u8ReadPinValue(port_index Copy_u8Port,pin_index Copy_u8Pin,uint8 * Copy_pu8Value );
ErrorState  DIO_u8TogglePinValue(port_index Copy_u8Port,pin_index Copy_u8Pin);

ErrorState  DIO_u8SetPortDirection(port_index Copy_u8Port,uint8 Copy_u8Direction );
ErrorState  DIO_u8SetPortValue(port_index Copy_u8Port ,uint8 Copy_u8Value );
ErrorState  DIO_u8TogglePortValue(port_index Copy_u8Port );

#endif /* DIO_INTERFACE_H_ */
