/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: gq
 */

#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REG.h"
#include "DIO.h"
#include "UART.h"
#include "Timer0.h"
#include "LCD_int.h"
#include "ADC.h"
#define F_CPU 12000000Ul
#include <avr/delay.h>
#include "Project_cfg.h"

static volatile int EchoPinStatus_flag = 0 ;
static volatile int Timer_Counts = 0 ;

void Metal_Detected (void)
{
	 DIO_SetPinValue(Motors_PORT,Motor_RF_PIN,LOW);
	 DIO_SetPinValue(Motors_PORT,Motor_RB_PIN,LOW);
	 DIO_SetPinValue(Motors_PORT,Motor_LF_PIN,LOW);
	 DIO_SetPinValue(Motors_PORT,Motor_LB_PIN,LOW);
	 DIO_SetPinValue(Buzzer_PORT,Buzzer_PIN,HIGH);
	 _delay_ms(200);
	 DIO_SetPinValue(Buzzer_PORT,Buzzer_PIN,LOW);
}
void (*ptr) (void) = Metal_Detected;

int main (void)
{
	//-------------- Motors, buzzer and LCD_CTRL Port --------------
	DIO_SetPortDirection(Motors_PORT,OUTPUT);
	//-------------- UltraSonic trigger pin direction --------------
	DIO_SetPinDirection(UltraSonic_PORT,UltraSonic_Trig_PIN,OUTPUT);

	//-------------- LCD Initialization --------------
	DIO_SetPortDirection(LCD_DATA_PORT,OUTPUT);
	LCD_vidInit();
	u16 Distance = 0 ;

	//-------------- INTERRUPT 0 for metal detector sensor --------------
	SET_BIT(SREG_Register,7);														//Global Interrupt Enable
	DIO_SetPinDirection(MetalSensor_PORT,MetalSensor_Signal_PIN,INPUT);				//external interrupt 0 pin
	SET_BIT(GICR_Register,6);  							 							//External interrupt 0 Enable
	//The rising edge of INT0 generates an interrupt request
	SET_BIT(MCUCR_Register,0);
	SET_BIT(MCUCR_Register,1);

	//-------------- INTERRUPT 2 for UltraSonic sensor --------------
	DIO_SetPinDirection(UltraSonic_PORT,UltraSonic_Echo_PIN,INPUT);					//external interrupt 1 pin
	SET_BIT(GICR_Register,7);  							 							//External interrupt 1 Enable
	//Any logical change on INT1 generates an interrupt request.
	SET_BIT(MCUCR_Register,2);
	CLR_BIT(MCUCR_Register,3);

	//-------------- ADC Initialization --------------
	DIO_SetPinDirection(ADC_PORT,ADC_Channel0,INPUT);
	ADC_init();
	SET_BIT(ADCSRA_Register,3);														//ADC interrupt enable

	//--------------PWM pin for control motors speed--------------
	DIO_SetPinDirection(MY_PORTD,PIN7,OUTPUT);

	//--------------UART--------------
	DIO_SetPinDirection(BlueTooth_PORT,BlueTooth_TX_PIN,INPUT);
	DIO_SetPinDirection(BlueTooth_PORT,BlueTooth_RX_PIN,OUTPUT);
	UART_vidInit();


	while(1)
	{
		DIO_SetPinValue(UltraSonic_PORT,UltraSonic_Trig_PIN,HIGH);			//Trigger PIN
		_delay_us(15);
		DIO_SetPinValue(UltraSonic_PORT,UltraSonic_Trig_PIN,LOW);

		LCD_vidSendCommand(Clr);
		LCD_vidGoToXY(0,0);
		LCD_vidSendString("Distance = ");
		Distance = Timer_Counts*1.45;				  //Distance = (34000 cm/s) * ( (Timer_Counts/2)*1024/12000000 )
		LCD_vidSendNumber(Distance);
		if (Distance < 20 )
		{
			ptr();
		}
	}
	return 0 ;
}


ISR(INT0_vect)
{
	ptr();
}

ISR(INT1_vect)
{
	if (EchoPinStatus_flag == 1)
	{
		TCCR1B_Register = 0 ;								//Stop Timer 1
		Timer_Counts  = TCNT1L_Register ;					//Take number of counts
		Timer_Counts |= (TCNT1H_Register<<8) ;
		TCNT1L_Register = 0 ;								//Reset the counter
		TCNT1H_Register = 0 ;
		EchoPinStatus_flag = 0 ;
	}

	if (EchoPinStatus_flag == 0)
	{
		SET_BIT(TCCR1B_Register,0);							//Timer 1 on, 1024 Pre-scaler
		SET_BIT(TCCR1B_Register,2);
		EchoPinStatus_flag = 1 ;
	}
}

ISR(ADC_vect)
{
	TIMER0_fast_PWM_init( ADC_Convert(0)/4 );					//Control motor speed using potentiometer
}

ISR(USART_RXC_vect)
{
	u8 x ;
	x = UART_u8RecieveData();
	if (x==49)
	{
				 DIO_SetPinValue(Motors_PORT,Motor_RF_PIN,HIGH);
				 DIO_SetPinValue(Motors_PORT,Motor_RB_PIN,LOW);
				 DIO_SetPinValue(Motors_PORT,Motor_LF_PIN,HIGH);
				 DIO_SetPinValue(Motors_PORT,Motor_LB_PIN,LOW);
	}
	else if (x==52)
	{
				 DIO_SetPinValue(Motors_PORT,Motor_RF_PIN,LOW);
				 DIO_SetPinValue(Motors_PORT,Motor_RB_PIN,HIGH);
				 DIO_SetPinValue(Motors_PORT,Motor_LF_PIN,LOW);
				 DIO_SetPinValue(Motors_PORT,Motor_LB_PIN,HIGH);
	}
	else if (x==50)
	{
				 DIO_SetPinValue(Motors_PORT,Motor_RF_PIN,HIGH);
				 DIO_SetPinValue(Motors_PORT,Motor_RB_PIN,LOW);
				 DIO_SetPinValue(Motors_PORT,Motor_LF_PIN,LOW);
				 DIO_SetPinValue(Motors_PORT,Motor_LB_PIN,LOW);
	}
	else if (x==51)
	{
				 DIO_SetPinValue(Motors_PORT,Motor_RF_PIN,LOW);
				 DIO_SetPinValue(Motors_PORT,Motor_RB_PIN,LOW);
				 DIO_SetPinValue(Motors_PORT,Motor_LF_PIN,HIGH);
				 DIO_SetPinValue(Motors_PORT,Motor_LB_PIN,LOW);
	}
	else
	{
				 DIO_SetPinValue(Motors_PORT,Motor_RF_PIN,LOW);
				 DIO_SetPinValue(Motors_PORT,Motor_RB_PIN,LOW);
				 DIO_SetPinValue(Motors_PORT,Motor_LF_PIN,LOW);
				 DIO_SetPinValue(Motors_PORT,Motor_LB_PIN,LOW);
	}
}
