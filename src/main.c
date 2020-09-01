/*********************************************************************************/
/* Author    : Amin Zaky                                                         */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"

u8 DataArray[34] = { 0, 62, 72, 72, 72, 62, 0, 0, 126, 32, 16, 32, 126, 0, 0, 66, 126, 66, 0, 0, 126, 32, 24, 4, 126, 0, 0, 62, 72, 72, 72, 62, 0 , 0};


int main (void)
{

	    RCC_voidInitSysClock() ;

		RCC_voidEnableClock(RCC_APB2 , RCC_PORTA) ;
		RCC_voidEnableClock(RCC_APB2 , RCC_PORTB) ;

		MSTK_voidInit();
		LEDMRX_voidInit();

        LEDMRX_voidAnimation(DataArray);



		return 0 ;
}
