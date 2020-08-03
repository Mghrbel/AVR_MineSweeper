/**********************************************************************/
/* File   : DIO.h                                                     */
/* Author : Mohamed ElMghrbel                                         */
/**********************************************************************/

#ifndef DIO_H_
#define DIO_H_

/* Port Defines */
#define MY_PORTA    0
#define MY_PORTB    1
#define MY_PORTC    2
#define MY_PORTD    3


/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7


/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/* PIN Value Options */
#define HIGH   1
#define LOW    0

/* IO Pins */
void DIO_SetPinDirection (u8 PortNumber, u8 PinNumber, u8 Direction);
void DIO_SetPinValue(u8 PortNumber , u8 PinNumber, u8 PinValue);
u8 DIO_GetPinValue(u8 PortNumber, u8 PinNumber);


/* IO Ports */
void DIO_SetPortDirection (u8 PortNumber, u8 PortDirection);
void DIO_SetPortValue (u8 PortNumber, u8 PortVal);

#endif /* DIO_H_ */
