/*
 * LED_interface.h
 *
 *  Created on: Nov 5, 2023
 *      Author: bagiz
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define ACT_HIGH  1
#define ACT_LOW   0

typedef struct {

	port_index port;
	pin_index  pin;
	uint8 	   ActiveType;

}led_config_t;

ErrorState LED_u8SetON(const led_config_t * led_obj);
ErrorState LED_u8SetOFF(const led_config_t * led_obj);
ErrorState LED_u8SetToggle(const led_config_t * led_obj);


#endif /* LED_INTERFACE_H_ */
