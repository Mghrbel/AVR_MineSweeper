/**********************************************************************/
/* File   : DIO.c                                                     */
/* Author : Mohamed ElMghrbel                                         */
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REG.h"

#include "DIO.h"


/* IO Pins */

void DIO_SetPinDirection (u8 PortNumber, u8 PinNumber, u8 Direction){
		if ( Direction == INPUT )
		{
			/* Check on the Required PORT Number */
			switch (PortNumber)
			{
				case MY_PORTA: CLR_BIT(DDRA_Register,PinNumber); break;
				case MY_PORTB: CLR_BIT(DDRB_Register,PinNumber); break;
				case MY_PORTC: CLR_BIT(DDRC_Register,PinNumber); break;
				case MY_PORTD: CLR_BIT(DDRD_Register,PinNumber); break;
			}
		}
		else if ( Direction == OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (PortNumber)
			{
				case MY_PORTA: SET_BIT(DDRA_Register,PinNumber); break;
				case MY_PORTB: SET_BIT(DDRB_Register,PinNumber); break;
				case MY_PORTC: SET_BIT(DDRC_Register,PinNumber); break;
				case MY_PORTD: SET_BIT(DDRD_Register,PinNumber); break;
			}
		}
		else
		{
			/* Do nothing, Wrong Direction Required */
		}

}

void DIO_SetPinValue(u8 PortNumber , u8 u8PinIdCopy, u8 u8PinValCopy)
{
		if (u8PinValCopy == LOW)
		{
			/* Check on the Required PORT Number */
			switch (PortNumber)
			{
				case MY_PORTA: CLR_BIT(PORTA_Register,u8PinIdCopy); break;
				case MY_PORTB: CLR_BIT(PORTB_Register,u8PinIdCopy); break;
				case MY_PORTC: CLR_BIT(PORTC_Register,u8PinIdCopy); break;
				case MY_PORTD: CLR_BIT(PORTD_Register,u8PinIdCopy); break;
			}
		}
		else if (u8PinValCopy == HIGH)
		{
			/* Check on the Required PORT Number */
			switch (PortNumber)
			{
				case MY_PORTA: SET_BIT(PORTA_Register,u8PinIdCopy); break;
				case MY_PORTB: SET_BIT(PORTB_Register,u8PinIdCopy); break;
				case MY_PORTC: SET_BIT(PORTC_Register,u8PinIdCopy); break;
				case MY_PORTD: SET_BIT(PORTD_Register,u8PinIdCopy); break;
			}
		}
		else
		{
			/* Do nothing, Wrong value to set */
		}

}

u8 DIO_GetPinValue(u8 PortNumber, u8 u8PinIdCopy)
{
	/* Define Local Variable to get the BIT Value */
	u8 u8ResultLocal;

		/* Check on the Required PORT Number */
		switch (PortNumber)
		{
			case MY_PORTA: u8ResultLocal= GET_BIT(PINA_Register,u8PinIdCopy); break;
			case MY_PORTB: u8ResultLocal= GET_BIT(PINB_Register,u8PinIdCopy); break;
			case MY_PORTC: u8ResultLocal= GET_BIT(PINC_Register,u8PinIdCopy); break;
			case MY_PORTD: u8ResultLocal= GET_BIT(PIND_Register,u8PinIdCopy); break;
		}

	return u8ResultLocal;
}

/* IO Ports */
void DIO_SetPortDirection (u8 PortNumber, u8 PortDirection)
{
	if(PortDirection == INPUT)
	{
		/* Check on the Required PORT Number */
		switch (PortNumber)
		{
			case MY_PORTA: DDRA_Register = 0X00; break;
			case MY_PORTB: DDRB_Register = 0X00; break;
			case MY_PORTC: DDRC_Register = 0X00; break;
			case MY_PORTD: DDRD_Register = 0X00; break;
		}
	}
	else if(PortDirection == OUTPUT)
	{
		/* Check on the Required PORT Number */
		switch (PortNumber)
		{
			case MY_PORTA: DDRA_Register = 0XFF; break;
			case MY_PORTB: DDRB_Register = 0XFF; break;
			case MY_PORTC: DDRC_Register = 0XFF; break;
			case MY_PORTD: DDRD_Register = 0XFF; break;
		}
	}
}

void DIO_SetPortValue (u8 PortNumber, u8 PortVal)
{
	/* Check on the Required PORT Number */
	switch (PortNumber)
	{
		case MY_PORTA: PORTA_Register = PortVal; break;
		case MY_PORTB: PORTB_Register = PortVal; break;
		case MY_PORTC: PORTC_Register = PortVal; break;
		case MY_PORTD: PORTD_Register = PortVal; break;
	}
}
