/*********************************************************************************************/
/* Author      : Amin Zaky                                                                   */
/* Version     : V01                                                                         */
/* Date        : 29 July 2020                                                                */
/*********************************************************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT)   ((VAR) |= (1 << (BIT)))
#define CLR_BIT(VAR,BIT)   (VAR &= ~(1 << BIT))
#define GET_BIT(VAR,BIT)   ((VAR >> BIT) & (1))
#define TOG_BIT(VAR,BIT)   ((VAR) ^= (1 <<(BIT)))

#define ASS_BIT(VAR,BIT,VALUE)   ((VAR) = (((VAR) & ( ~(1 << (BIT))))|(VALUE << BIT)))

#endif 
