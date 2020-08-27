/*********************************************************************************/
/* Author    : Amin Zaky                                                         */
/* Version   : V01                                                               */
/* Date      : 26 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SWITCH_interface.h"
#include "SWITCH_config.h"
#include "SWITCH_private.h"

void SWITCH_voidInit(u8 copy_u8PinId) {
	GPIO_voidSetPinDirection(copy_u8PinId, SWITCH_MODE);
}

u8 SWITCH_u8GetStatus(u8 copy_u8PinId) {
	return GPIO_u8GetPinValue(copy_u8PinId);
}
