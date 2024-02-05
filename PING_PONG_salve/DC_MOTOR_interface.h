/*
 * DC_MOTOR_interface.h
 *
 *  Created on: Nov 26, 2023
 *      Author: bagiz
 */

#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

typedef struct
{
	port_index port;
	pin_index  pin1;
	pin_index  pin2;

}motor_config;

ErrorState Motor_voidRotateCW(motor_config * Motor);
ErrorState Motor_voidRotateCCW(motor_config * Motor);
ErrorState Motor_voidStop(motor_config * Motor);

#endif /* DC_MOTOR_INTERFACE_H_ */
