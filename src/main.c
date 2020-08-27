/*********************************************************************************/
/* Author    : Amin Zaky                                                         */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "STK_interface.h"
#include "LED_interface.h"

int main (void)
{

	    RCC_voidInitSysClock() ;
		RCC_voidEnableClock(RCC_APB2 , RCC_PORTC) ;

		MSTK_voidInit();
		LED_voidInit(PINC13);


		while (1)
		{


			LED_voidTogLed(PINC13);



			MSTK_voidSetBusyWait(1000000);




		}


		return 0 ;
}
