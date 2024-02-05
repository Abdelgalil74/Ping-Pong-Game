/*
 * GIE_prog.c
 *
 *  Created on: Dec 6, 2023
 *      Author: bagiz
 */

#include "STD_TYPES.h"
#include "bit_math.h"

#include "GIE_register.h"
#include "GIE_interface.h"


void GIE_voidEnableGlobal(void)
{

	__asm volatile ("SEI");

}
void GIE_voidDisableGlobal(void)
{

	__asm volatile ("CLI");
}
