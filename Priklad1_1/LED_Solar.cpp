/* 
* LED.cpp
*
* Created: 12.3.2019 12:37:47
* Author: Juraj
*/


#include "LED_Solar.h"


LED::LED(uint8_t pin, char P){   //konstruktor
	if(P == 'B'){
		sbi(DDRB,pin);		// nastavenie smeru
		sbi(PORTB,pin);	//nesvieti
		x = 'B';
	}
	if(P == 'C'){
		sbi(DDRC,pin);		// nastavenie smeru
		sbi(PORTC,pin);	//nesvieti
		x = 'C';
	}
	if(P == 'D'){
		sbi(DDRD,pin);		// nastavenie smeru
		sbi(PORTD,pin);		//nesvieti
		x = 'D';
	}
	stav = 1;
	ppin = pin;
};
//-----------------------------------------------------

LED::~LED(){};					//destruktor
//-----------------------------------------------------
void LED::Sviet_LED(void){		// metoda (funkcia)
	if(x == 'B') cbi(PORTB,ppin);
	if(x == 'C') cbi(PORTC,ppin);
	if(x == 'D') cbi(PORTD,ppin);
	stav = 0;
};
//-----------------------------------------------------
void LED::Blik_LED(uint16_t time){
	this->Sviet_LED();
	for(uint16_t i=0; i<time; i++)_delay_ms(1);
	this->Zhasni_LED();
	
};
//----------------------------------------------------
void LED::Zhasni_LED(void){
	if(x == 'B') sbi(PORTB,ppin);
	if(x == 'C') sbi(PORTC,ppin);
	if(x == 'D') sbi(PORTD,ppin);
	stav = 1;
};
//----------------------------------------------------
bool LED::Get_LED(){
	return stav;
};
/*_________________________________________________________*/
