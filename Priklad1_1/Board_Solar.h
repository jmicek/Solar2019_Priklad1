/*
 * Board1.h
 *
 * Created: 12.3.2019 12:33:16
 *  Author: Juraj
 */ 


#ifndef BOARD_SOLAR_H_
#define BOARD_SOLAR_H_
#include <avr/io.h>

/*_______________Board.h____________________*/
#define F_CPU 1000000UL	
#include <avr/io.h>				/* Include AVR std. library file */
#include <util/delay.h>			/* Include delay header file */
#include <inttypes.h>			/* Include integer type header file */
#include <stdlib.h>				/* Include standard library file */
#include <stdio.h>				/* Include standard library file */

								/* Define CPU clock Frequency e.g. here its 1MHz */
#define sbi(x,y) x |= (1<<y)	//_BV(y)	 //nastav bit     (1<<y)
#define cbi(x,y) x &= ~(1<<y)   //(_BV(y)) //nuluj bit - using bitwise AND operator
#define tbi(x,y) x ^= _BV(y)    //zmen bit - using bitwise XOR operator
/*_________________________________________________________________________*/

#endif /* BOARD_SOLAR_H_ */