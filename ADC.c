/**********************************************************************/
/* File   : ADC.c                                                     */
/* Author : Mohamed ElMghrbel                                         */
/**********************************************************************/

#include "STD_TYPES.h"
#include "DIO.h"
#include "BIT_MATH.h"
#include "REG.h"
#include "ADC.h"

void ADC_init (void)
{
	//ADC enable
		SET_BIT(ADCSRA_Register,7);		//ADC enable

	//Prescaler to for ADC to be 128
		SET_BIT(ADCSRA_Register,0);
		SET_BIT(ADCSRA_Register,1);
		SET_BIT(ADCSRA_Register,2);

	//select AVCC as voltage reference
		SET_BIT(ADMUX_Register,6);      //select AVCC as voltage refrence
		CLR_BIT(ADMUX_Register,7);

	//SET ADLAR to read from right to left
		CLR_BIT(ADMUX_Register,5);		//SET ADLAR to read from right to left
}

u16 ADC_Convert (u8 channel)
{
	u16 ADC_Digital_Value = 0 ;

	//SET channel in range (0:7)
		channel = channel & 0x07 ;
	//SET which ADC channel to read
		ADMUX_Register &= 0xE0 ;		 //make sure first 5 bits are 0000
		ADMUX_Register |= channel ;

	//Start conversion
		SET_BIT(ADCSRA_Register,6);

	//wait conversion to be finished (waiting flag to be 1)
		while (GET_BIT(ADCSRA_Register,4)==0);

	//Read from ADCH and ADCL
		ADC_Digital_Value = ADCL_Register ;
		ADC_Digital_Value |= (ADCH_Register<<8) ;

	//SET flat to be 1 again
		SET_BIT(ADCSRA_Register,4);


	return ADC_Digital_Value ;
}
