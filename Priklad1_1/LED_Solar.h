/* 
* LED.h
*
* Created: 12.3.2019 12:37:47
* Author: Juraj
*/


#ifndef __LED_H__
#define __LED_H__

#include "Board_Solar.h"

class LED{
	
	//variables
	public:
	protected:
	private:
	uint8_t stav = 1;			// = 1;					// len od std=c++11
	char x ='A';				//='A'
	uint8_t ppin = 0;			//=0
	//functions
	public:
	LED(uint8_t, char);			//pin 0 - 7,  PORT: A, B, C, pin P
	~LED();
	void Sviet_LED(void);
	void Blik_LED(uint16_t time);
	void Zhasni_LED(void);
	bool Get_LED();
	protected:
	private:
/*________________________________________________________________*/
}; //LED

#endif //__LED_H__
