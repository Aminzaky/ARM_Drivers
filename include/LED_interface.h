/*********************************************************************************/
/* Author    : Amin Zaky                                                         */
/* Version   : V01                                                               */
/* Date      : 26 August 2020                                                    */
/*********************************************************************************/
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define Forward 0
#define Reverse 1

void LED_voidInit(u8 copy_u8PinId);

void LED_voidOnLed(u8 copy_u8PinId , u8 copy_u8PinConnection);

void LED_voidOffLed(u8 copy_u8PinId , u8 copy_u8PinConnection);

void LED_voidTogLed(u8 copy_u8PinId);


#endif
