/*
 * Priklad1_1.cpp
 *
 * Created: 12.3.2019 12:32:23
 * Author : Juraj
 */ 


#include "LED_Solar.h"

int main(void)
  {
	  
	  LED led1(7,'D');
	  LED *pled1;       // deklarujeme pointer na triedu
	  pled1 = &led1;	// priradime smerniku hodnotu ukazujucu na led1
	  
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

