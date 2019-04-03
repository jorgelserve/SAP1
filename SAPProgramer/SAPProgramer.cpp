/*
	SAPProgramer.cpp - Libreria para programar SAP1 (74LS89)
	Create by Jorge Luis Serna (@jorgelserve), marzo 28 de 2019

	Este obra está bajo una licencia de Creative Commons Reconocimiento 4.0 Internacional.
	https://creativecommons.org/licenses/by/4.0/
*/

#include "Arduino.h"
#include "SAPProgramer.h"

SAPProgramer::SAPProgramer(uint8_t ENram, uint8_t WEram) {
	pinMode(ENram, OUTPUT);
	pinMode(WEram, OUTPUT);
	digitalWrite(ENram, HIGH);
	DDRB = B00001111;
	DDRK = B11111111;
	

	_addres = 0;

	_ENram = ENram;
	_WEram = WEram;
}

void SAPProgramer::lda(uint8_t data) {
	_write();
	PORTB = B00000000;
	if (!_addres) {
		for(; _addres < 16; _addres++) {
			PORTB = _addres;
			PORTK = ~B00000000;
			delay(10);
		}
		_addres = 0;
		PORTB = _addres;
		PORTK = ~data;
		delay(10);
		_addres += 1;
	}
}

void SAPProgramer::add(uint8_t data) {
	_write();
	if (_addres < 16) {
		PORTB = _addres;
		PORTK = ~((B0001<<4) + data);
		delay(100);
		_addres += 1; 
	}
}


void SAPProgramer::_write() { 
	digitalWrite(_ENram, LOW);
	digitalWrite(_WEram, LOW);
}

void SAPProgramer::_read() { 
	digitalWrite(_ENram, LOW);
	digitalWrite(_WEram, HIGH);
}

void SAPProgramer::_disable() { 
	digitalWrite(_ENram, HIGH);
	digitalWrite(_WEram, HIGH);
}
