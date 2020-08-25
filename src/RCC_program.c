/*********************************************************************************/
/* Author    : Amin Zaky                                                         */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void) {
#if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	RCC_CR = 0x00010000; /* Enable HSE with no bypass */
	RCC_CFGR = 0x00000001;

#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
	RCC_CR = 0x00050000; /* Enable HSE with bypass */
	RCC_CFGR = 0x00000001;

#elif   RCC_CLOCK_TYPE == RCC_HSI
	RCC_CR = 0x00000081; /* Enable HSI + Trimming = 0 */
	RCC_CFGR = 0x00000000;

#elif   RCC_CLOCK_TYPE == RCC_PLL
#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	RCC_CR = 0x00000081; /* Enable HSI + Trimming = 0 */
	SET_BIT(RCC_CFGR,PLLSRC_BIT); /*HSI oscillator clock / 2 selected as PLL input clock*/
#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	RCC_CR = 0x00010000; /* Enable HSE with no bypass */
	CLR_BIT(RCC_CFGR,PLLSRC_BIT); /*HSE oscillator clock selected as PLL input clock*/
	SET_BIT(RCC_CFGR,PLLXTPRE_BIT); /*HSE clock divided by 2*/
#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
	RCC_CR = 0x00050000; /* Enable HSE with bypass */
	SET_BIT(RCC_CFGR,PLLSRC_BIT);/*HSE oscillator clock selected as PLL input clock*/
	CLR_BIT(RCC_CFGR,PLLXTPRE_BIT); /*HSE clock not divided*/
#endif
	if (RCC_PLL_MUL_VAL >= 2 )
	{
		RCC_CFGR |= ((RCC_PLL_MUL_VAL - 2 ) << PLLMUL_BIT ); /* SET PLL multiplier */
	}
	else
	{
		RCC_CFGR |= (( 0b0000 ) << PLLMUL_BIT ); /* SET PLL multiplier */
	}
	SET_BIT(RCC_CR , PLLON_BIT); /* enable PLL */
#else
#error("You chosed Wrong Clock type")
#endif
}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId) {
	if (Copy_u8PerId <= 31) {
		switch (Copy_u8BusId) {
		case RCC_AHB:
			SET_BIT(RCC_AHBENR, Copy_u8PerId);
			break;
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR, Copy_u8PerId);
			break;
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR, Copy_u8PerId);
			break;
		}
	}

	else {
		/* Return Error */
	}

}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId) {
	if (Copy_u8PerId <= 31) {
		switch (Copy_u8BusId) {
		case RCC_AHB:
			CLR_BIT(RCC_AHBENR, Copy_u8PerId);
			break;
		case RCC_APB1:
			CLR_BIT(RCC_APB1ENR, Copy_u8PerId);
			break;
		case RCC_APB2:
			CLR_BIT(RCC_APB2ENR, Copy_u8PerId);
			break;
		}
	}

	else {
		/* Return Error */
	}

}

