/*
 * PORT_register.h
 *
 *  Created on: Nov 7, 2023
 *      Author: bagiz
 */

#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

#define PORTA        *((volatile uint8*)0x3b)
#define DDRA 		 *((volatile uint8*)0x3a)

#define PORTB    	 *((volatile uint8*)0x38)
#define DDRB 		 *((volatile uint8*)0x37)

#define PORTC        *((volatile uint8*)0x35)
#define DDRC 		 *((volatile uint8*)0x34)

#define PORTD        *((volatile uint8*)0x32)
#define DDRD 		 *((volatile uint8*)0x31)



#endif /* PORT_REGISTER_H_ */
