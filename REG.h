/**********************************************************************/
/* File   : REG.h                                                     */
/* Author : Mohamed ElMghrbel                                         */
/**********************************************************************/

#ifndef _REG_H
#define _REG_H

/* Group A Registers */
#define PORTA_Register  *((volatile u8*)0x3B)
#define DDRA_Register   *((volatile u8*)0x3A)
#define PINA_Register   *((volatile u8*)0x39)

/* Group B Registers */
#define PORTB_Register  *((volatile u8*)0x38)
#define DDRB_Register   *((volatile u8*)0x37)
#define PINB_Register   *((volatile u8*)0x36)

/* Group C Registers */
#define PORTC_Register  *((volatile u8*)0x35)
#define DDRC_Register   *((volatile u8*)0x34)
#define PINC_Register   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD_Register  *((volatile u8*)0x32)
#define DDRD_Register   *((volatile u8*)0x31)
#define PIND_Register   *((volatile u8*)0x30)

/* Interrupt */
#define SREG_Register  *((volatile u8*)0x5F)
#define GICR_Register   *((volatile u8*)0x5B)
#define MCUCR_Register  *((volatile u8*)0x55)
#define MCUCSR_Register  *((volatile u8*)0x54)
#define GIFR_Register   *((volatile u8*)0x5A)

/* Timer 0 */
#define TCNT0_Register  *((volatile u8*)0x52)
#define OCR0_Register   *((volatile u8*)0x5C)
#define TCCR0_Register  *((volatile u8*)0x53)
#define TIMSK_Register  *((volatile u8*)0x59)
#define TIFR_Register   *((volatile u8*)0x58)

/* Timer 1 */
#define TCCR1A_Register  *((volatile u8*)0x4F)
#define TCCR1B_Register   *((volatile u8*)0x4E)
#define TCNT1H_Register  *((volatile u8*)0x4D)
#define TCNT1L_Register  *((volatile u8*)0x4C)
#define OCR1AH_Register   *((volatile u8*)0x4B)
#define OCR1AL_Register  *((volatile u8*)0x4A)
#define OCR1BH_Register  *((volatile u8*)0x49)
#define OCR1BL_Register   *((volatile u8*)0x48)
#define ICR1H_Register  *((volatile u8*)0x47)
#define ICR1L_Register  *((volatile u8*)0x46)

/* ADC */
#define ADMUX_Register  *((volatile u8*)0x27)
#define ADCSRA_Register  *((volatile u8*)0x26)
#define ADCH_Register  *((volatile u8*)0x25)
#define ADCL_Register  *((volatile u8*)0x24)

#endif
