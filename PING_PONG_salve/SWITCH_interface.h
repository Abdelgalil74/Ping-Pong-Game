/*
 * SWITCH_interface.h
 *
 *  Created on: Nov 5, 2023
 *      Author: bagiz
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

typedef enum{

	BUTTON_PRESSED=0,
	BUTTON_RELEASED
}button_state;

typedef enum{

	PULL_UP=0,
	PULL_DOWN
}pull_t;


typedef struct
{

	port_index port;
	pin_index  pin;
	pull_t     pull;

}switch_config_t;

//ErrorState SWITCH_u8Init(const switch_config_t * switch_obj );
ErrorState SWITCH_u8GetState(const switch_config_t * switch_obj , uint8 *State);

#endif /* SWITCH_INTERFACE_H_ */
