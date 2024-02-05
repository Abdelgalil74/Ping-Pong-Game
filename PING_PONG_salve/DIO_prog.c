/*
 * DIO_prog.c
 *
 *  Created on: Oct 27, 2023
 *      Author: bagiz
 */
#include "STD_TYPES.h"
#include "bit_math.h"
#include  "ErrType.h"
#include "DIO_interface.h"
#include "DIO_reg.h"
#include "DIO_config.h"

ErrorState  DIO_u8SetPinDirection(port_index Copy_u8Port,pin_index Copy_u8Pin,dirction_t Copy_u8Direction )
{
	ErrorState Local_u8ErrorState=OK;

	if(Copy_u8Direction == DIO_u8PIN_INPUT)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : CLR_BIT(DDRA,Copy_u8Pin); break;
		case DIO_u8PORTB : CLR_BIT(DDRB,Copy_u8Pin); break;
		case DIO_u8PORTC : CLR_BIT(DDRC,Copy_u8Pin); break;
		case DIO_u8PORTD : CLR_BIT(DDRD,Copy_u8Pin); break;
		default: Local_u8ErrorState=NOT_OK;          break;
		}
	}
	else if(Copy_u8Direction == DIO_u8PIN_OUTPUT)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : SET_BIT(DDRA,Copy_u8Pin); break;
		case DIO_u8PORTB : SET_BIT(DDRB,Copy_u8Pin); break;
		case DIO_u8PORTC : SET_BIT(DDRC,Copy_u8Pin); break;
		case DIO_u8PORTD : SET_BIT(DDRD,Copy_u8Pin); break;
		default: Local_u8ErrorState=NOT_OK; 		 break;
		}
	}
	else
	{
		Local_u8ErrorState=NOT_OK;
	}
	return Local_u8ErrorState ;
}


ErrorState  DIO_u8SetPinValue(port_index Copy_u8Port,pin_index Copy_u8Pin,logic_t Copy_u8Value )
{
	ErrorState Local_u8ErrorState=OK;

	if(Copy_u8Value == DIO_u8PIN_LOW)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin); break;
		case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin); break;
		case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin); break;
		case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin); break;
		default: Local_u8ErrorState=NOT_OK;           break;
		}
	}
	else if(Copy_u8Value == DIO_u8PIN_HIGH)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin); break;
		case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin); break;
		case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin); break;
		case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin); break;
		default: Local_u8ErrorState=NOT_OK; 		  break;
		}
	}
	else
	{
		Local_u8ErrorState=NOT_OK;
	}
	return Local_u8ErrorState ;
}


ErrorState  DIO_u8ReadPinValue(port_index Copy_u8Port,pin_index Copy_u8Pin,uint8 * Copy_pu8Value )
{
	ErrorState Local_u8ErrorState=OK;

	if (((Copy_u8Pin >=DIO_u8PIN0) && (Copy_u8Pin <=DIO_u8PIN7)) || ( NULL != Copy_pu8Value ))
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : *Copy_pu8Value=GET_BIT(PINA,Copy_u8Pin);    break;
		case DIO_u8PORTB : *Copy_pu8Value=GET_BIT(PINB,Copy_u8Pin);    break;
		case DIO_u8PORTC : *Copy_pu8Value=GET_BIT(PINC,Copy_u8Pin);    break;
		case DIO_u8PORTD : *Copy_pu8Value=GET_BIT(PIND,Copy_u8Pin);    break;

		default: Local_u8ErrorState=NOT_OK;           				   break;
		}
	}
	else
	{
		if( NULL != Copy_pu8Value )
		Local_u8ErrorState=NULL_PTR_ERR;
		else if((Copy_u8Pin >=DIO_u8PIN0) && (Copy_u8Pin <=DIO_u8PIN7))
		Local_u8ErrorState=NOT_OK;

	}


	return Local_u8ErrorState ;
}

ErrorState  DIO_u8TogglePinValue(port_index Copy_u8Port,pin_index Copy_u8Pin)
{
	ErrorState Local_u8ErrorState=OK;

	if (Copy_u8Pin >=DIO_u8PIN0 && Copy_u8Pin <=DIO_u8PIN7 )
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : TOGGLE_BIT(PORTA,Copy_u8Pin); break;
		case DIO_u8PORTB : TOGGLE_BIT(PORTB,Copy_u8Pin); break;
		case DIO_u8PORTC : TOGGLE_BIT(PORTC,Copy_u8Pin); break;
		case DIO_u8PORTD : TOGGLE_BIT(PORTD,Copy_u8Pin); break;

		default: Local_u8ErrorState=NOT_OK;              break;
		}
	}
	else
	{
		Local_u8ErrorState=NOT_OK;
	}

	return Local_u8ErrorState ;
}


ErrorState  DIO_u8SetPortDirection(port_index Copy_u8Port,uint8 Copy_u8Direction )
{
	ErrorState Local_u8ErrorState=OK;

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA : DDRA=Copy_u8Direction;	 break;
	case DIO_u8PORTB : DDRB=Copy_u8Direction; 	 break;
	case DIO_u8PORTC : DDRC=Copy_u8Direction; 	 break;
	case DIO_u8PORTD : DDRD=Copy_u8Direction;    break;
	default: Local_u8ErrorState=NOT_OK;          break;
	}

	return Local_u8ErrorState ;

}


ErrorState  DIO_u8SetPortValue(port_index Copy_u8Port ,uint8 Copy_u8Value )
{
	ErrorState Local_u8ErrorState=OK;

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA : PORTA=Copy_u8Value;	 break;
	case DIO_u8PORTB : PORTB=Copy_u8Value; 	 break;
	case DIO_u8PORTC : PORTC=Copy_u8Value; 	 break;
	case DIO_u8PORTD : PORTD=Copy_u8Value;   break;
	default: Local_u8ErrorState=NOT_OK;      break;
	}

	return Local_u8ErrorState ;

}


ErrorState  DIO_u8TogglePortValue(port_index Copy_u8Port )
{

	ErrorState Local_u8ErrorState=OK;

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA : PORTA=~PORTA;	 break;
	case DIO_u8PORTB : PORTB=~PORTB; 	 break;
	case DIO_u8PORTC : PORTC=~PORTC; 	 break;
	case DIO_u8PORTD : PORTD=~PORTD;  	 break;
	default: Local_u8ErrorState=NOT_OK;  break;
	}

	return Local_u8ErrorState ;

}

