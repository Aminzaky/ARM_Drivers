/********************************************************************/
/* Author	: Amin Zaky								          	 	*/
/* Date		: 31 August 2020                                        */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

u8 rows[8] = { LEDMRX_ROW0, LEDMRX_ROW1, LEDMRX_ROW2, LEDMRX_ROW3, LEDMRX_ROW4,
		LEDMRX_ROW5, LEDMRX_ROW6, LEDMRX_ROW7 };
u8 columns[8] = { LEDMRX_COLUMN0, LEDMRX_COLUMN1, LEDMRX_COLUMN2, LEDMRX_COLUMN3,
		LEDMRX_COLUMN4, LEDMRX_COLUMN5, LEDMRX_COLUMN6, LEDMRX_COLUMN7 };


void LEDMRX_voidInit(void) {
	for (u8 i = 0; i <= 7; i++) {
		GPIO_voidSetPinDirection(rows[i], OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(columns[i], OUTPUT_SPEED_2MHZ_PP);
	}
}


void LEDMRX_voidDisplay(u8 *Copy_u8Data) {
	for(u8 i =0; i <= 7; i++){
		LEDMRX_voidSetColumns();
		LEDMRX_voidSetRowValue(Copy_u8Data[i]);
		GPIO_voidSetPinValue(columns[i],GPIO_LOW);
		MSTK_voidSetBusyWait(2500);
	}
}

void LEDMRX_voidAnimation(u8 *Copy_u8Data) {

	u8 index = 0;
	u32 count = 0;
	u8 temp_data[8] = { Copy_u8Data[index], Copy_u8Data[index],
			Copy_u8Data[index], Copy_u8Data[index], Copy_u8Data[index],
			Copy_u8Data[index], Copy_u8Data[index], Copy_u8Data[index] };
	while (1) {
		LEDMRX_voidDisplay(temp_data);
		count++;

		if (count % 20 == 0) {
			temp_data[0] = Copy_u8Data[index];
			temp_data[1] = Copy_u8Data[index + 1];
			temp_data[2] = Copy_u8Data[index + 2];
			temp_data[3] = Copy_u8Data[index + 3];
			temp_data[4] = Copy_u8Data[index + 4];
			temp_data[5] = Copy_u8Data[index + 5];
			temp_data[6] = Copy_u8Data[index + 6];
			temp_data[7] = Copy_u8Data[index + 7];
			index++;
			if (index == 27) {
				index = 0;
			}
		}

	}
}
static void LEDMRX_voidSetColumns(void) {
	for (u8 j = 0; j <= 7; j++) {
		GPIO_voidSetPinValue(columns[j], GPIO_HIGH);
	}
}

static void LEDMRX_voidSetRowValue(u8 Copy_u8Data) {
	u8 LOC_u8BIT;
	for (u8 k = 0; k <= 7; k++) {
		LOC_u8BIT = GET_BIT(Copy_u8Data, k);
		GPIO_voidSetPinValue(rows[k], LOC_u8BIT);
	}
}


