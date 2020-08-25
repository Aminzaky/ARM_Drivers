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


void Delay (void)
{
	for(int i = 0 ; i < 600 ; i++ )
{
	for(int j = 0 ; j < 600 ; j++ )
	{
		asm("NOP");
	}
}

}

int main (void)
{

	RCC_voidInitSysClock() ;
		RCC_voidEnableClock(RCC_APB2 , RCC_PORTC) ;


		GPIO_VidSetPinDirection(PINC13 , OUTPUT_SPEED_10MHZ_PP);


		while (1)
		{


			GPIO_VidSetPinValue( PINC13 , GPIO_HIGH);



			 Delay();



			GPIO_VidSetPinValue( PINC13  , GPIO_LOW);



			 Delay();

		}


		return 0 ;
}
