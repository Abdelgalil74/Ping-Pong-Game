/*
 * EXTI_prog.c
 *
 *  Created on: Dec 6, 2023
 *      Author: bagiz
 */


#include "STD_TYPES.h"
#include "bit_math.h"
#include "ErrType.h"

#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_cfg.h"


static void (*EXTI_pvCallBack[3])(void) = {0} ;


void EXTI_voidInit(void)
{

#if INT0_SENCE_CTRL == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENCE_CTRL == EXTI_ON_CHANGE

	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENCE_CTRL == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENCE_CTRL == EXTI_RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#else
	#error Wrong INT0_SENCE_CTRL Configuration option

#endif


#if INT1_SENCE_CTRL == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENCE_CTRL ==EXTI_ON_CHANGE

	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT1_SENCE_CTRL == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENCE_CTRL == EXTI_RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#else
	#error Wrong INT1_SENCE_CTRL Configuration option

#endif


#if INT1_SENCE_CTRL == EXTI_FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);

#elif INT1_SENCE_CTRL == EXTI_RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);

#else
	#error Wrong INT1_SENCE_CTRL Configuration option

#endif

#if INT0_INIT_STATE == DISABLED

#elif INT0_INIT_STATE == ENABLED

#else
	#error Wrong INT0_INIT_STATE Configuration option

#endif


#if INT0_INIT_STATE == DISABLED
	CLR_BIT(GICR , GICR_INT0);
#elif INT0_INIT_STATE == ENABLED
	SET_BIT(GICR , GICR_INT0);

#else
	#error Wrong INT0_INIT_STATE Configuration option

#endif


#if INT1_INIT_STATE == DISABLED
	CLR_BIT(GICR , GICR_INT1);

#elif INT1_INIT_STATE == ENABLED
	SET_BIT(GICR , GICR_INT1);

#else
	#error Wrong INT0_INIT_STATE Configuration option

#endif

#if INT2_INIT_STATE == DISABLED
	CLR_BIT(GICR , GICR_INT2);

#elif INT2_INIT_STATE == ENABLED
	SET_BIT(GICR , GICR_INT2);

#else
	#error Wrong INT0_INIT_STATE Configuration option

#endif


}
uint8 EXTI_u8SetSenceCtrl(IntChannel_t Copy_IntCh, SenceCtrl_t Copy_SenceCtrl)
{
	ErrorState Local_u8ErrorState ;

	if(Copy_IntCh == INT0 )
	{
		switch(Copy_SenceCtrl)
		{
		case LOW_LEVEL:	 CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
		case ON_CHAGNE:	 SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
		case FALLING_EDGE : CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
		case RISING_EDGE :  SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;

		default : Local_u8ErrorState = NOT_OK;
		}
	}
	else if (Copy_IntCh == INT1 )
	{
		switch(Copy_SenceCtrl)
		{
		case LOW_LEVEL:	 CLR_BIT(MCUCR,MCUCR_ISC11); CLR_BIT(MCUCR,MCUCR_ISC10); break;
		case ON_CHAGNE:	 CLR_BIT(MCUCR,MCUCR_ISC11); SET_BIT(MCUCR,MCUCR_ISC10); break;
		case FALLING_EDGE : SET_BIT(MCUCR,MCUCR_ISC11); CLR_BIT(MCUCR,MCUCR_ISC10); break;
		case RISING_EDGE :  SET_BIT(MCUCR,MCUCR_ISC11); SET_BIT(MCUCR,MCUCR_ISC10); break;


		default : Local_u8ErrorState = NOT_OK;
		}
	}
	else if (Copy_IntCh == INT2 )
	{
		switch(Copy_SenceCtrl)
		{
		case FALLING_EDGE : CLR_BIT(MCUCSR,MCUCSR_ISC2); break;
		case RISING_EDGE :  SET_BIT(MCUCSR,MCUCSR_ISC2);  break;

		default : Local_u8ErrorState = NOT_OK;

		}

	}
	return Local_u8ErrorState;

}



uint8 EXTI_u8EnableIntChannel(IntChannel_t Copy_IntCh)
{
	ErrorState Local_u8ErrorState;

	switch (Copy_IntCh)
	{
	case INT0: SET_BIT(GICR , GICR_INT0);  break;
	case INT1: SET_BIT(GICR , GICR_INT1);   break;
	case INT2: SET_BIT(GICR , GICR_INT2);   break;

	default:  Local_u8ErrorState=NOT_OK;  break;

	}

	return Local_u8ErrorState;
}
uint8 EXTI_u8DisableIntChannel(IntChannel_t Copy_IntCh)
{
	ErrorState Local_u8ErrorState;

	switch (Copy_IntCh)
	{
	case INT0: CLR_BIT(GICR , GICR_INT0);  break;
	case INT1: CLR_BIT(GICR , GICR_INT1);   break;
	case INT2: CLR_BIT(GICR , GICR_INT2);   break;

	default: Local_u8ErrorState=NOT_OK;  break;

	}

	return Local_u8ErrorState;

}

uint8 EXTI_u8SetCallBack(IntChannel_t Copy_IntCh ,void (*Copy_pvCallBackFunc)(void) )
{
	ErrorState Local_u8ErrorState = OK ;

	if(Copy_pvCallBackFunc != NULL && (Copy_IntCh >= INT0 && Copy_IntCh <= INT2 ))
	{

		EXTI_pvCallBack[Copy_IntCh] = Copy_pvCallBackFunc;

	}
	else
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

/*INT0 ISR*/
__attribute__ ((signal)) void __vector_1(void);
void __vector_1(void)
{
	if(EXTI_pvCallBack[INT0] != NULL)
	{
		EXTI_pvCallBack[INT0]();
	}


}

/*INT1 ISR*/
__attribute__ ((signal)) void __vector_2(void);
void __vector_2(void)
{
	if(EXTI_pvCallBack[INT1] != NULL)
	{
		EXTI_pvCallBack[INT1]();
	}

}

/*INT2 ISR*/
__attribute__ ((signal)) void __vector_3(void);
void __vector_3(void)
{
	if(EXTI_pvCallBack[INT2] != NULL)
	{
		EXTI_pvCallBack[INT2]();
	}

}


