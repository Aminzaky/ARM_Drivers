/*****************************************/
/* Author  :  Amin Zaky                  */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

void (*Callback) (void);
u8 Periodic_flag =0 ;

#define AHB 0
#define AHB_DIV_8 1

#define STK_CTRL   *((volatile u32*)(0xE000E010))
#define STK_LOAD   *((volatile u32*)(0xE000E014))
#define STK_VAL    *((volatile u32*)(0xE000E018))
#define STK_CALIB  *((volatile u32*)(0xE000E01C))

#endif
