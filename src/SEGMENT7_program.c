/*********************************************************************************/
/* Author    : Amin Zaky                                                         */
/* Version   : V01                                                               */
/* Date      : 26 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SEGMENT7_interface.h"
#include "SEGMENT7_config.h"
#include "SEGMENT7_private.h"

void SEGEMENT7_voidInit(void) {
#if SEMENT7_MODE == COMMON_CATHODE
	GPIO_voidSetPinDirection(PIN_a, SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_b, SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_c, SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_d, SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_e, SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_f, SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_g, SEMENT7_PIN_MODE);
#elif SEMENT7_MODE == COMMON_ANODE
	GPIO_voidSetPinDirection(PIN_a,SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_b,SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_c,SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_d,SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_e,SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_f,SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_g,SEMENT7_PIN_MODE);
#elif SEMENT7_MODE == BCD
	GPIO_voidSetPinDirection(PIN_a,SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_b,SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_c,SEMENT7_PIN_MODE);
	GPIO_voidSetPinDirection(PIN_d,SEMENT7_PIN_MODE);
#endif
}

void SEGEMENT7_voidDisplay(u8 copy_Number) {
#if SEMENT7_MODE == COMMON_CATHODE
	switch (copy_Number) {
	case 0:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_e, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_f, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_g, GPIO_LOW);
		break;
	case 1:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_e, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_f, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_g, GPIO_LOW);
		break;
	case 2:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_e, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_f, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_g, GPIO_HIGH);
		break;
	case 3:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_e, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_f, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_g, GPIO_HIGH);
		break;
	case 4:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_e, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_f, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_g, GPIO_HIGH);
		break;
	case 5:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_e, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_f, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_g, GPIO_HIGH);
		break;
	case 6:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_e, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_f, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_g, GPIO_HIGH);
		break;
	case 7:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_e, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_f, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_g, GPIO_LOW);
		break;
	case 8:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_e, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_f, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_g, GPIO_HIGH);
		break;
	case 9:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_e, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_f, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_g, GPIO_HIGH);
		break;
	case 10:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_e, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_f, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_g, GPIO_LOW);
		break;
	default:

		break;
	}
#elif SEMENT7_MODE == COMMON_ANODE
	switch (copy_Number) {
		case 0:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_e, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_f, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_g, GPIO_HIGH);
		break;
		case 1:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_e, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_f, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_g, GPIO_HIGH);
		break;
		case 2:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_e, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_f, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_g, GPIO_LOW);
		break;
		case 3:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_e, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_f, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_g, GPIO_LOW);
		break;
		case 4:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_e, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_f, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_g, GPIO_LOW);
		break;
		case 5:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_e, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_f, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_g, GPIO_LOW);
		break;
		case 6:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_e, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_f, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_g, GPIO_LOW);
		break;
		case 7:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_e, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_f, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_g, GPIO_HIGH);
		break;
		case 8:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_e, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_f, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_g, GPIO_LOW);
		break;
		case 9:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_e, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_f, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_g, GPIO_LOW);
		break;
		case 10:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_e, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_f, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_g, GPIO_HIGH);
		break;
		default:

		break;
	}
#elif SEMENT7_MODE == BCD
	switch (copy_Number) {
		case 0:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);

		break;
		case 1:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		break;
		case 2:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		break;
		case 3:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		break;
		case 4:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		break;
		case 5:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		break;
		case 6:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		break;
		case 7:
		GPIO_voidSetPinValue(PIN_a, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_b, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_c, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		break;
		case 8:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_LOW);
		break;
		case 9:
		GPIO_voidSetPinValue(PIN_a, GPIO_HIGH);
		GPIO_voidSetPinValue(PIN_b, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_c, GPIO_LOW);
		GPIO_voidSetPinValue(PIN_d, GPIO_HIGH);
		break;
		default:

		break;
	}
#endif
}
