/**********************************************************************/
/* File   : Timer0.h                                                  */
/* Author : Mohamed ElMghrbel                                         */
/**********************************************************************/

#ifndef TIMER0_H_
#define TIMER0_H_

void TIMER0_Normal_init ();
void TIMER0_CTC_normal_init (u8 Compare_value);
void TIMER0_CTC_square_wave_init (u8 Compare_value);

void TIMER0_PWM_init (u8 Compare_value);
void TIMER0_fast_PWM_init (u8 Compare_value);

#endif /* TIMER0_H_ */
