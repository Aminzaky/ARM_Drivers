/*********************************************************************************/
/* Author    : Amin Zaky                                                         */
/* Version   : V01                                                               */
/* Date      : 26 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

void LED_voidInit(u8 copy_u8PinId) {
	GPIO_voidSetPinDirection(copy_u8PinId, LED_MODE);
}

void LED_voidOnLed(u8 copy_u8PinId, u8 copy_u8PinConnection) {
	if (copy_u8PinConnection == Forward) {
		GPIO_voidSetPinValue(copy_u8PinId,GPIO_HIGH);
	} else {
		GPIO_voidSetPinValue(copy_u8PinId,GPIO_LOW);
	}
}

void LED_voidOffLed(u8 copy_u8PinId, u8 copy_u8PinConnection) {
	if (copy_u8PinConnection == Forward) {
		GPIO_voidSetPinValue(copy_u8PinId,GPIO_LOW);
	} else {
		GPIO_voidSetPinValue(copy_u8PinId,GPIO_HIGH);
	}
}

void LED_voidTogLed(u8 copy_u8PinId) {
	GPIO_voidSetPinValue(copy_u8PinId,GPIO_TOG);
}
