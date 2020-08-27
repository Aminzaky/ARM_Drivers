/*********************************************************************************/
/* Author    : Amin Zaky                                                         */
/* Version   : V01                                                               */
/* Date      : 26 August 2020                                                    */
/*********************************************************************************/
#ifndef SEGMENT7_CONFIG_H_
#define SEGMENT7_CONFIG_H_

#define SEMENT7_PIN_MODE OUTPUT_SPEED_10MHZ_PP

/* Options:
 COMMON_ANODE
 COMMO_CATHODE
 BCD
 */

#define SEMENT7_MODE COMMON_CATHODE

/* define pins wit GPIO PINS */
/* for BCD_mode select first four pins ONLY */

#define PIN_a PINA0
#define PIN_b PINA1
#define PIN_c PINA2
#define PIN_d PINA3
#define PIN_e PINA4
#define PIN_f PINA5
#define PIN_g PINA6

#endif
