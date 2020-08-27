/*********************************************************************************/
/* Author    : Amin Zaky                                                         */
/* Version   : V01                                                               */
/* Date      : 11 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_VidSetPinDirection(u8 Copy_u8Pin, u8 u8Copy_u8Mode) {

	if (Copy_u8Pin >= PINA0 && Copy_u8Pin <= PINA15) {

		if ((Copy_u8Pin % 16) <= 7) { //low

			GPIOA_CRL &= ~((0b1111) << ((Copy_u8Pin % 16) * 4)); // R M W
			GPIOA_CRL |= (u8Copy_u8Mode) << ((Copy_u8Pin % 16) * 4);

		} else if ((Copy_u8Pin % 16) <= 15) { //high

			Copy_u8Pin = (Copy_u8Pin % 16) - 8;
			GPIOA_CRH &= ~((0b1111) << ((Copy_u8Pin % 16) * 4));
			GPIOA_CRH |= (u8Copy_u8Mode) << ((Copy_u8Pin % 16) * 4);
		}

		if (u8Copy_u8Mode == INPUT_PULLUP_PULLDOWN) {
			ASS_BIT(GPIOA_ODR, (Copy_u8Pin % 16), INPUT_PULLUP_PULLDOWN_OPTION);
		}
	}

	if (Copy_u8Pin >= PINB0 && Copy_u8Pin <= PINB15) {

		if ((Copy_u8Pin % 16) <= 7) { //low

			GPIOB_CRL &= ~((0b1111) << ((Copy_u8Pin % 16) * 4)); // R M W
			GPIOB_CRL |= (u8Copy_u8Mode) << ((Copy_u8Pin % 16) * 4);

		} else if ((Copy_u8Pin % 16) <= 15) { //high

			Copy_u8Pin = (Copy_u8Pin % 16) - 8;
			GPIOB_CRH &= ~((0b1111) << ((Copy_u8Pin % 16) * 4));
			GPIOB_CRH |= (u8Copy_u8Mode) << ((Copy_u8Pin % 16) * 4);
		}

		if (u8Copy_u8Mode == INPUT_PULLUP_PULLDOWN) {
			ASS_BIT(GPIOB_ODR, (Copy_u8Pin % 16), INPUT_PULLUP_PULLDOWN_OPTION);
		}
	}

	if (Copy_u8Pin >= PINC0 && Copy_u8Pin <= PINC15) {

		if ((Copy_u8Pin % 16) <= 7) { //low

			GPIOC_CRL &= ~((0b1111) << ((Copy_u8Pin % 16) * 4)); // R M W
			GPIOC_CRL |= (u8Copy_u8Mode) << ((Copy_u8Pin % 16) * 4);

		} else if ((Copy_u8Pin % 16) <= 15) { //high

			Copy_u8Pin = (Copy_u8Pin % 16) - 8;
			GPIOC_CRH &= ~((0b1111) << ((Copy_u8Pin % 16) * 4));
			GPIOC_CRH |= (u8Copy_u8Mode) << ((Copy_u8Pin % 16) * 4);
		}

		if (u8Copy_u8Mode == INPUT_PULLUP_PULLDOWN) {
			ASS_BIT(GPIOC_ODR, (Copy_u8Pin % 16), INPUT_PULLUP_PULLDOWN_OPTION);
		}
	}

}

void GPIO_VidSetPinValue( u8 Copy_u8Pin , u8 u8Copy_u8Value) {

	if (Copy_u8Pin >= PINA0 && Copy_u8Pin <= PINA15) {

		if (u8Copy_u8Value == GPIO_HIGH) {
			GPIOA_BSR = 1 << (Copy_u8Pin%16) ;
		} else if (u8Copy_u8Value == GPIO_LOW) {
			GPIOA_BRR = 1 << (Copy_u8Pin%16) ;
		} else if (u8Copy_u8Value == GPIO_TOG) {
			TOG_BIT(GPIOA_ODR, (Copy_u8Pin%16) );
		}

	}

	if (Copy_u8Pin >= PINB0 && Copy_u8Pin <= PINB15) {

		if (u8Copy_u8Value == GPIO_HIGH) {
			GPIOB_BSR = 1 << (Copy_u8Pin%16) ;
		} else if (u8Copy_u8Value == GPIO_LOW) {
			GPIOB_BRR = 1 << (Copy_u8Pin%16) ;
		} else if (u8Copy_u8Value == GPIO_TOG) {
			TOG_BIT(GPIOB_ODR, (Copy_u8Pin%16) );
		}

	}

	if (Copy_u8Pin >= PINC0 && Copy_u8Pin <= PINC15) {

		if (u8Copy_u8Value == GPIO_HIGH) {
			GPIOC_BSR = 1 << (Copy_u8Pin%16) ;
		} else if (u8Copy_u8Value == GPIO_LOW) {
			GPIOC_BRR = 1 << (Copy_u8Pin%16) ;
		} else if (u8Copy_u8Value == GPIO_TOG) {
			TOG_BIT(GPIOC_ODR, (Copy_u8Pin%16) );
		}

	}



}

u8 GPIO_u8GetPinValue( u8 Copy_u8Pin ) {

	u8 LOC_u8Result = 0;

	if (Copy_u8Pin >= PINA0 && Copy_u8Pin <= PINA15) {

		LOC_u8Result = GET_BIT(GPIOA_IDR, (Copy_u8Pin%16) );

	}

	if (Copy_u8Pin >= PINB0 && Copy_u8Pin <= PINB15) {

		LOC_u8Result = GET_BIT(GPIOB_IDR, (Copy_u8Pin%16) );

	}

	if (Copy_u8Pin >= PINC0 && Copy_u8Pin <= PINC15) {

		LOC_u8Result = GET_BIT(GPIOC_IDR, (Copy_u8Pin%16) );

	}



	return LOC_u8Result;

}

void GPIO_VidSetPortDirection(u8 Copy_u8Port, u32 u32Copy_u32PortMode) {
	switch (Copy_u8Port) {
	case GPIOA:
		GPIOA_CRL = u32Copy_u32PortMode;
		GPIOA_CRH = u32Copy_u32PortMode;
		if (u32Copy_u32PortMode == INPUT_PORT_PULLUP_PULLDOWN) {
			GPIOA_ODR = INPUT_PULLUP_PULLDOWN_PORT_OPTION;
		}
		break;
	case GPIOB:
		GPIOB_CRL = u32Copy_u32PortMode;
		GPIOB_CRH = u32Copy_u32PortMode;
		if (u32Copy_u32PortMode == INPUT_PORT_PULLUP_PULLDOWN) {
			GPIOB_ODR = INPUT_PULLUP_PULLDOWN_PORT_OPTION;
		}
		break;
	case GPIOC:
		GPIOC_CRL = u32Copy_u32PortMode;
		GPIOC_CRH = u32Copy_u32PortMode;
		if (u32Copy_u32PortMode == INPUT_PORT_PULLUP_PULLDOWN) {
			GPIOC_ODR = INPUT_PULLUP_PULLDOWN_PORT_OPTION;
		}
		break;
	default:
		break;
	}

}

void GPIO_VidSetPortValue(u8 Copy_u8Port, u32 u32Copy_u8Value) {
	switch (Copy_u8Port) {
	case GPIOA:
		if (u32Copy_u8Value == PORT_HIGH) {
			GPIOA_BSR = 0xFFFFFFFF ;
		} else if (u32Copy_u8Value == PORT_LOW) {
			GPIOA_BRR = 0xFFFFFFFF ;
		} else if (u32Copy_u8Value == PORT_TOG) {
			GPIOA_ODR ^= 0xFFFFFFFF ;
		} else {
			GPIOA_ODR = u32Copy_u8Value;
		}
		break;
	case GPIOB:
		if (u32Copy_u8Value == PORT_HIGH) {
			GPIOB_BSR = 0xFFFFFFFF;
		} else if (u32Copy_u8Value == PORT_LOW) {
			GPIOB_BRR = 0xFFFFFFFF;
		} else if (u32Copy_u8Value == PORT_TOG) {
			GPIOB_ODR ^= 0xFFFFFFFF ;
		} else {
			GPIOB_ODR = u32Copy_u8Value;
		}
		break;
	case GPIOC:
		if (u32Copy_u8Value == PORT_HIGH) {
			GPIOC_BSR = 0xFFFFFFFF;
		} else if (u32Copy_u8Value == PORT_LOW) {
			GPIOC_BRR = 0xFFFFFFFF;
		} else if (u32Copy_u8Value == PORT_TOG) {
			GPIOC_ODR ^= 0xFFFFFFFF ;
		} else {
			GPIOC_ODR = u32Copy_u8Value;
		}
		break;

	}

}

u32 GPIO_u32GetPortValue(u8 Copy_u8Port) {
	u32 LOC_u32PortValue = 0;

	switch (Copy_u8Port) {
	case GPIOA:
		LOC_u32PortValue = GPIOA_IDR;
		break;
	case GPIOB:
		LOC_u32PortValue = GPIOB_IDR;
		break;
	case GPIOC:
		LOC_u32PortValue = GPIOC_IDR;
		break;
	default:
		break;

	}

	return LOC_u32PortValue;
}

u8 GPIO_VidLockPinMode(u8 Copy_u8Pin) {

	u8 LOC_LCKValue = 0;

	if (Copy_u8Pin >= PINA0 && Copy_u8Pin <= PINA15) {

		SET_BIT(GPIOA_LCK, (Copy_u8Pin % 16));
		SET_BIT(GPIOA_LCK, 16);
		CLR_BIT(GPIOA_LCK, 16);
		SET_BIT(GPIOA_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOA_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOA_LCK, 16);

	}

	if (Copy_u8Pin >= PINB0 && Copy_u8Pin <= PINB15) {

		SET_BIT(GPIOB_LCK, (Copy_u8Pin % 16));
		SET_BIT(GPIOB_LCK, 16);
		CLR_BIT(GPIOB_LCK, 16);
		SET_BIT(GPIOB_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOB_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOB_LCK, 16);

	}

	if (Copy_u8Pin >= PINC0 && Copy_u8Pin <= PINC15) {

		SET_BIT(GPIOC_LCK, (Copy_u8Pin % 16));
		SET_BIT(GPIOC_LCK, 16);
		CLR_BIT(GPIOC_LCK, 16);
		SET_BIT(GPIOC_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOC_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOC_LCK, 16);

	}
	return LOC_LCKValue;
}

u8 GPIO_VidLockPortMode(u8 Copy_u8Port) {
	u8 LOC_LCKValue = 0;
	switch (Copy_u8Port) {
	case GPIOA:
		GPIOA_LCK |= 0x0000FFFF;
		SET_BIT(GPIOA_LCK, 16);
		CLR_BIT(GPIOA_LCK, 16);
		SET_BIT(GPIOA_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOA_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOA_LCK, 16);
		break;
	case GPIOB:
		GPIOB_LCK |= 0x0000FFFF;
		SET_BIT(GPIOB_LCK, 16);
		CLR_BIT(GPIOB_LCK, 16);
		SET_BIT(GPIOB_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOB_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOB_LCK, 16);
		break;
	case GPIOC:
		GPIOC_LCK |= 0x0000FFFF;
		SET_BIT(GPIOC_LCK, 16);
		CLR_BIT(GPIOC_LCK, 16);
		SET_BIT(GPIOC_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOC_LCK, 16);
		LOC_LCKValue = GET_BIT(GPIOC_LCK, 16);
		break;
	default:
		break;

	}
	return LOC_LCKValue;
}
