/*
 * Priklad1.cpp
 *
 * Created: 7.3.2019 18:31:23
 * Author : Juraj
 */ 

#include <avr/io.h>

/*_______________Board_Solar.h____________________*/

#define F_CPU 1000000UL									/* Define CPU clock Frequency e.g. here its 8MHz */
#include <avr/io.h>										/* Include AVR std. library file */
#include <util/delay.h>									/* Include delay header file */
#include <inttypes.h>									/* Include integer type header file */
#include <stdlib.h>										/* Include standard library file */
#include <stdio.h>										/* Include standard library file */


#define sbi(x,y) x |= (1<<y)	//_BV(y)	 //nastav bit     (1<<y)
#define cbi(x,y) x &= ~(1<<y)   //(_BV(y)) //nuluj bit - using bitwise AND operator
#define tbi(x,y) x ^= _BV(y)    //zmen bit - using bitwise XOR operator

/*_________________________________________________________________________*/


/*______________________________LED.h______________________________________*/
class LED{
		
	//variables
	public:
	protected:
	private:
			uint8_t stav = 1;					// len od -std=c++11
			char x = 'A';
			uint8_t ppin = 0;
	//functions
	public:
			LED(uint8_t pin, char P);			//pin 0 - 7,  PORT: D, B, C, 
			~LED();
			void Sviet_LED(void);
			void Blik_LED(uint16_t time);
			void Zhasni_LED(void);
			bool Get_LED();
	protected:
	private:
		};
/*________________________________________________________________*/
/*______________________________LED.cpp___________________________*/

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


int main(void)
{
   
   LED led1(7,'D');
   LED *pled1;       // deklarujeme pointer na triedu
   pled1 = &led1;	// priradime pointru hodnotu ukazujucu na led1
   
   pled1->Sviet_LED();
   _delay_ms(1000);
   led1.Zhasni_LED();
   _delay_ms(1000);
  
  for(uint16_t i = 0; i<20; i++){ 
   led1.Blik_LED(20);  //20 ms
    _delay_ms(300);
  }
  
    while (1) 
    {
    }
}

