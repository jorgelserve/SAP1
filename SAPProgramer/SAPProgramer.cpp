/*
	SAPProgramer.cpp - Libreria para programar SAP1 (74LS89)
	Create by Jorge Luis Serna (@jorgelserve), marzo 28 de 2019

	Este obra está bajo una licencia de Creative Commons Reconocimiento 4.0 Internacional.
	https://creativecommons.org/licenses/by/4.0/
*/

#if !defined(ARDUINO_AVR_MEGA2560)
  #error Solo se soporta Arduino Mega 2560
#endif

#include "Arduino.h"
#include "SAPProgramer.h"
#include "defs.h"


SAPProgramer::SAPProgramer(uint8_t ENram, uint8_t WEram) {
	pinMode(ENram, OUTPUT);
	pinMode(WEram, OUTPUT);
	digitalWrite(ENram, HIGH);
	DDRB = B00001111;
	DDRK = B11111111;
	PORTB = B00000000;
	PORTK = B00000000;

	_addres = 0;
	_ENram = ENram;
	_WEram = WEram;
	
}

void SAPProgramer::lda(int data) {
	if (!_addres) {
		PORTB = _addres;
		PORTK = data;
		_addres += 1;
	} else {
		PORTK = 0;
	}
}

// void SAPProgramer::add(int data) {
// 	if (_addres) {
// 		PORTK 
// 	}
// }


