

#include "STD_TYPES.h"
#include "bit_math.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "DC_MOTOR_interface.h"
#include "SWITCH_interface.h"
#include "LED_interface.h"
#include <util/delay.h>

void int2_func(void);
void int0_func(void);

uint8 counter=0;
switch_config_t switch1={
		.pin=DIO_u8PIN5,
		.port=DIO_u8PORTB,
		.pull=PULL_UP
};

button_state state;

uint8 x=1;
uint8 r=0;
uint8 y=1;
uint8 flag=1;
uint8 flag2=1;
uint8 countdelay=90;

void main(void)
{


	PORT_voidInit();
	CLCD_voidInit();

	EXTI_u8SetCallBack(INT2, &int2_func);
	EXTI_u8SetCallBack(INT0, &int0_func);

	EXTI_u8EnableIntChannel(INT2);
	EXTI_u8SetSenceCtrl(INT2,RISING_EDGE);
	EXTI_u8EnableIntChannel(INT0);
	EXTI_u8SetSenceCtrl(INT0,RISING_EDGE);
	GIE_voidEnableGlobal();

	uint8 Paddle_1 [8] =
	{
			0b00111,
			0b00111,
			0b00111,
			0b00111,
			0b00111,
			0b00111,
			0b00111,
			0b00111
	};

	uint8 BALL[8] =
	{
			0b00000,
			0b00000,
			0b00000,
			0b01111,
			0b01111,
			0b01111,
			0b00000,
			0b00000
	};
	sint8 i=1;

	switch_config_t switch1={
			.pin=DIO_u8PIN5,
			.port=DIO_u8PORTB,
			.pull=PULL_UP
	};

	while(1)
	{
		if(flag2==1)
		{
			CLCD_u8SendSpecialCharacter(1 , Paddle_1 , x , 16);
			if(y==1)
			{
				y=2;
			}
			else if(y==2)
			{
				y=1;
			}

			if(counter==1)
			{
				if(countdelay>30)
				{
					countdelay=(90-30*r);
					r++;
				}
				for(i=1;i<=15;i++)
				{
					CLCD_u8SendSpecialCharacter(1 , Paddle_1 , x , 16);

					CLCD_u8SendSpecialCharacter(2,BALL,y,i);

					_delay_ms(countdelay);



					SWITCH_u8GetState(&switch1,&state);
					if(state==BUTTON_PRESSED)
					{
						if(x==1)
						{
							CLCD_voidSendDataPos(x,16,' ');
							x=2;
						}
						else if(x==2)
						{
							CLCD_voidSendDataPos(x,16,' ');
							x=1;
						}
					}
					CLCD_voidSendDataPos(y,i,' ');

				}
				if(y!=x)
				{

					CLCD_voidSendCommand(CLCD_CLEAR);
					CLCD_voidSendStringPos(1,3,"Player 1 Won");
					DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);

					flag=0;
					flag2=0;
				}
				else
				{
					DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);

				}
				if(flag==1)
				{
					for(i=15;i>=1;i--)
					{
						CLCD_u8SendSpecialCharacter(1 , Paddle_1 , x , 16);

						CLCD_u8SendSpecialCharacter(2,BALL,y,i);
						_delay_ms(countdelay);



						SWITCH_u8GetState(&switch1,&state);
						if(state==BUTTON_PRESSED)
						{
							if(x==1)
							{
								CLCD_voidSendDataPos(x,16,' ');
								x=2;
							}
							else if(x==2)
							{
								CLCD_voidSendDataPos(x,16,' ');
								x=1;
							}
						}
						CLCD_voidSendDataPos(y,i,' ');

					}

					if(i==0)
					{
						DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
					}
				}
			}
			counter=0;
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);



		}
	}
}


void int2_func(void)
{
	counter=1;

}
void int0_func(void)
{
	CLCD_voidSendCommand(CLCD_CLEAR);
	CLCD_voidSendStringPos(1,3,"Player 2 Won");


}
