/*
 * EXTI_cfg.h
 *
 *  Created on: Dec 6, 2023
 *      Author: bagiz
 */

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_



#define INT0_SENCE_CTRL		EXTI_RISING_EDGE
#define INT1_SENCE_CTRL		EXTI_FALLING_EDGE
#define INT2_SENCE_CTRL		EXTI_RISING_EDGE


/* Configure the initial state if INT0 channel , options are :
 * 															1- ENABLED
 * 															2- Disabled
 */
#define INT0_INIT_STATE								ENABLED

/* Configure the initial state if INT1 channel , options are :
 * 															1- ENABLED
 * 															2- Disabled
 */

#define INT1_INIT_STATE								DISABLED

/* Configure the initial state if INT2 channel , options are :
 * 															1- ENABLED
 * 															2- Disabled
 */

#define INT2_INIT_STATE								ENABLED

#endif /* EXTI_CFG_H_ */
