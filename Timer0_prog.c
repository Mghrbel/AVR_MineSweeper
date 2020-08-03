//**********************************************************************/
/* File   : Timer0_prog.c                                              */
/* Author : Mohamed ElMghrbel                                          */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REG.h"
#include "DIO.h"



void TIMER0_Normal_init ()
{
	//normal mode
	CLR_BIT(TCCR0_Register,3);
	CLR_BIT(TCCR0_Register,6);

	//Disconnect OC0
	CLR_BIT(TCCR0_Register,4);
	CLR_BIT(TCCR0_Register,5);

	//Pre_scaler = 256
	CLR_BIT(TCCR0_Register,0);
	CLR_BIT(TCCR0_Register,1);
	SET_BIT(TCCR0_Register,2);
}



void TIMER0_CTC_normal_init (u8 Compare_value)
{
	TCNT0_Register = 0 ;
	OCR0_Register = Compare_value ;

	//CTC mode
	SET_BIT(TCCR0_Register,3);
	CLR_BIT(TCCR0_Register,6);

	SET_BIT(TCCR0_Register,7);

	//normal CTC mode
	CLR_BIT(TCCR0_Register,4);
	CLR_BIT(TCCR0_Register,5);

	//Pre_scaler = 256
	CLR_BIT(TCCR0_Register,0);
	CLR_BIT(TCCR0_Register,1);
	SET_BIT(TCCR0_Register,2);
}



void TIMER0_CTC_square_wave_init (u8 Compare_value)
{
	TCNT0_Register = 0 ;
	OCR0_Register = Compare_value ;
	DIO_SetPinDirection(MY_PORTB,PIN3,OUTPUT);

	//CTC mode
	SET_BIT(TCCR0_Register,3);
	CLR_BIT(TCCR0_Register,6);
	SET_BIT(TCCR0_Register,7);

	//Toggle OC0 bin at compare match
	SET_BIT(TCCR0_Register,4);
	CLR_BIT(TCCR0_Register,5);

	//Pre_scaler = 1024
	SET_BIT(TCCR0_Register,0);
	CLR_BIT(TCCR0_Register,1);
	SET_BIT(TCCR0_Register,2);
}



void TIMER0_PWM_init (u8 Compare_value)
{
	TCNT0_Register = 0 ;
	OCR0_Register = Compare_value ;
	DIO_SetPinDirection(MY_PORTB,PIN3,OUTPUT);

	//PWM phase correct mode
	CLR_BIT(TCCR0_Register,3);
	SET_BIT(TCCR0_Register,6);
	CLR_BIT(TCCR0_Register,7);

	//Clear OC0 on compare match when up-counting. Set OC0 on compare match when down-counting
	SET_BIT(TCCR0_Register,5);
	CLR_BIT(TCCR0_Register,4);

	//Pre_scaler = 1024
	SET_BIT(TCCR0_Register,0);
	CLR_BIT(TCCR0_Register,1);
	SET_BIT(TCCR0_Register,2);
}



void TIMER0_fast_PWM_init (u8 Compare_value)
{
	TCNT0_Register = 0 ;
	OCR0_Register = Compare_value ;
	DIO_SetPinDirection(MY_PORTB,PIN3,OUTPUT);

	//fast PWM mode
	SET_BIT(TCCR0_Register,3);
	SET_BIT(TCCR0_Register,6);
	CLR_BIT(TCCR0_Register,7);

	//Clear OC0 on compare match
	SET_BIT(TCCR0_Register,5);
	CLR_BIT(TCCR0_Register,4);

	//Pre_scaler = 1024
	SET_BIT(TCCR0_Register,0);
	CLR_BIT(TCCR0_Register,1);
	SET_BIT(TCCR0_Register,2);
}
