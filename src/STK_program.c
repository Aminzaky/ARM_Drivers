/*****************************************/
/* Author  :  Amin Zaky                  */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"

void MSTK_voidInit(void) {
#if CLK_SRC == AHB
	SET_BIT(STK_CTRL, 2);
#elif CLK_SRC == AHB_DIV_8
	CLR_BIT(STK_CTRL,2);
#endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks) {

	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL, 0);
	while (GET_BIT(STK_CTRL,16) == 0);
	/* Stop Timer */
	STK_LOAD = 0;
	STK_VAL = 0;
	CLR_BIT(STK_CTRL, 0);

}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void)) {
	/* Disable Timer */
	CLR_BIT(STK_CTRL, 0);
	STK_VAL = 0;
	/*****************/
	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL, 1);
	SET_BIT(STK_CTRL, 0);
	Copy_ptr = Callback;
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void)) {
	Periodic_flag=1;
	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL, 1);
	SET_BIT(STK_CTRL, 0);
	Copy_ptr = Callback;
}

void MSTK_voidStopInterval(void) {
	/* Disable STK Interrupt */
	CLR_BIT(STK_CTRL, 1);

	/* Stop Timer */
	STK_LOAD = 0;
	STK_VAL = 0;
	CLR_BIT(STK_CTRL, 0);
	Periodic_flag = 0;
}

u32 MSTK_u32GetElapsedTime(void) {

	u32 Local_u32ElapsedTime;

	Local_u32ElapsedTime = (STK_LOAD - STK_VAL);

	return Local_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime(void) {

	u32 Local_u32RemainTime;

	Local_u32RemainTime = STK_VAL;

	return Local_u32RemainTime;
}

void SysTick_Handler(void) {

	u8 Local_u8Temporary;

	if (Periodic_flag == 0) {
		/* Disable STK Interrupt */
		CLR_BIT(STK_CTRL, 1);

		/* Stop Timer */
		STK_LOAD = 0;
		STK_VAL = 0;
		CLR_BIT(STK_CTRL, 0);

	}

	Callback();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK_CTRL, 16);
}
