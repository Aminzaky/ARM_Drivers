/*********************************************************************************/
/* Author    : Amin Zaky                                                         */
/* Version   : V01                                                               */
/* Date      : 11 August 2020                                                    */
/*********************************************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define GPIO_HIGH    1
#define GPIO_LOW     0
#define GPIO_TOG     2

#define HIGH_PORTL 0x00FF
#define HIGH_PORTH 0xFF00

#define PORT_HIGH  0xFFFFFFFF
#define PORT_LOW   0x00000000
#define PORT_TOG   0xAAAAAAAA

#define GPIOA   0
#define GPIOB   1
#define GPIOC   2

#define PINA0    0
#define PINA1    1
#define PINA2    2
#define PINA3    3
#define PINA4    4
#define PINA5    5
#define PINA6    6
#define PINA7    7
#define PINA8    8
#define PINA9    9
#define PINA10    10
#define PINA11    11
#define PINA12    12
#define PINA13    13
#define PINA14    14
#define PINA15    15

#define PINB0    16
#define PINB1    17
#define PINB2    18
#define PINB3    19
#define PINB4    20
#define PINB5    21
#define PINB6    22
#define PINB7    23
#define PINB8    24
#define PINB9    25
#define PINB10    26
#define PINB11    27
#define PINB12    28
#define PINB13    29
#define PINB14    30
#define PINB15    31

#define PINC0    32
#define PINC1    33
#define PINC2    34
#define PINC3    35
#define PINC4    36
#define PINC5    37
#define PINC6    38
#define PINC7    39
#define PINC8    40
#define PINC9    41
#define PINC10    42
#define PINC11    43
#define PINC12    44
#define PINC13    45
#define PINC14    46
#define PINC15    47

//PIN MODES
#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

//For Speed 10
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

//For Speed 2
#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

//For Speed 2
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111

//PORT MODES
#define INPUT_PORT_ANLOG             ( (u32)0x00000000 )          // 0b00000000000000000000000000000000
#define INPUT_PORT_FLOATING          ( (u32)0x44444444 )          // 0b01000100010001000100010001000100
#define INPUT_PORT_PULLUP_PULLDOWN   ( (u32)0x88888888 )          // 0b10001000100010001000100010001000
//For Speed 10
#define OUTPUT_SPEED_PORT_10MHZ_PP         ( (u32)0x11111111 )          // 0b00010001000100010001000100010001
#define OUTPUT_SPEED_PORT_10MHZ_OD         ( (u32)0x55555555 )          // 0b01010101010101010101010101010101
#define OUTPUT_SPEED_PORT_10MHZ_AFPP       ( (u32)0x99999999 )          // 0b10011001100110011001100110011001
#define OUTPUT_SPEED_PORT_10MHZ_AFOD       ( (u32)0xDDDDDDDD )          // 0b11011101110111011101110111011101

//For Speed 2
#define OUTPUT_SPEED_PORT_2MHZ_PP          ( (u32)0x22222222 )           // 0b00100010001000100010001000100010
#define OUTPUT_SPEED_PORT_2MHZ_OD          ( (u32)0x66666666 )           // 0b01100110011001100110011001100110
#define OUTPUT_SPEED_PORT_2MHZ_AFPP        ( (u32)0xAAAAAAAA )           // 0b10101010101010101010101010101010
#define OUTPUT_SPEED_PORT_2MHZ_AFOD        ( (u32)0xEEEEEEEE )           // 0b11101110111011101110111011101110

//For Speed 2
#define OUTPUT_SPEED_PORT_50MHZ_PP         ( (u32)0x33333333 )           // 0b00110011001100110011001100110011
#define OUTPUT_SPEED_PORT_50MHZ_OD         ( (u32)0x77777777 )           // 0b01110111011101110111011101110111
#define OUTPUT_SPEED_PORT_50MHZ_AFPP       ( (u32)0xBBBBBBBB )           // 0b10111011101110111011101110111011
#define OUTPUT_SPEED_PORT_50MHZ_AFOD       ( (u32)0xFFFFFFFF )‬           // 0b11111111111111111111111111111111

// PIN specific APIs
void GPIO_VidSetPinDirection(u8 Copy_u8Pin, u8 u8Copy_u8Mode);
void GPIO_VidSetPinValue(u8 Copy_u8Pin, u8 u8Copy_u8Value);
u8 GPIO_u8GetPinValue(u8 Copy_u8Pin);

// PORT specific APIs
void GPIO_VidSetPortDirection(u8 Copy_u8Port, u32 u32Copy_u32PortMode);
void GPIO_VidSetPortValue(u8 Copy_u8Port, u32 u32Copy_u8Value);
u32 GPIO_u32GetPortValue(u8 Copy_u8Port);

#endif

