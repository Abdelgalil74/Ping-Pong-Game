/*
 * EXTI_interface.h
 *
 *  Created on: Dec 6, 2023
 *      Author: bagiz
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	INT0,
	INT1,
	INT2
}IntChannel_t;

typedef enum
{
	LOW_LEVEL, ON_CHAGNE ,FALLING_EDGE , RISING_EDGE

}SenceCtrl_t;


void EXTI_voidInit(void);

uint8 EXTI_u8SetSenceCtrl(IntChannel_t Copy_IntCh, SenceCtrl_t Copy_SenceCtrl);

uint8 EXTI_u8EnableIntChannel(IntChannel_t Copy_IntCh);
uint8 EXTI_u8DisableIntChannel(IntChannel_t Copy_IntCh);

uint8 EXTI_u8SetCallBack(IntChannel_t Copy_IntCh ,void (*Copy_pvCallBackFunc)(void) );


#endif /* EXTI_INTERFACE_H_ */
