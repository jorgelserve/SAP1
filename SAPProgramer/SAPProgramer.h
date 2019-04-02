/*
	SAPProgramer.h - Libreria para programar SAP1 (74LS89)
	Create by Jorge Luis Serna (@jorgelserve), marzo 28 de 2019

	Este obra está bajo una licencia de Creative Commons Reconocimiento 4.0 Internacional.
	https://creativecommons.org/licenses/by/4.0/
*/

#ifndef SAPProgramer_h
#define SAPProgramer_h

#include "Arduino.h"

class SAPProgramer {
	public:
		SAPProgramer(uint8_t ENram, uint8_t WEram);
		void lda(uint8_t data);
		void add(uint8_t data);
		void sub(uint8_t data);
		void out(void);
		void hlt(void);
	private:
		uint8_t _ENram;
		uint8_t _WEram;
		uint8_t _addres;
}

#endif
