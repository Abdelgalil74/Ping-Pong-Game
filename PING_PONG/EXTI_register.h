/*
 * EXTI_register.h
 *
 *  Created on: Dec 6, 2023
 *      Author: bagiz
 */

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define GICR         *((volatile uint8  *)(0X5B))
#define GICR_INT1		7U
#define GICR_INT0		6U
#define GICR_INT2		5U


#define MCUCR        *((volatile uint8  *)(0X55))
#define MCUCR_ISC00			0U
#define MCUCR_ISC01			1U
#define MCUCR_ISC10			2U
#define MCUCR_ISC11			3U



#define MCUCSR		  *((volatile uint8  *)(0X54))
#define MCUCSR_ISC2 		6U

#endif /* EXTI_REGISTER_H_ */
