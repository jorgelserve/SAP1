/*
	SAPProgramer.h - Libreria para programar SAP1
	Create by Jorge Luis Serna (@jorgelserve), marzo 28 de 2019

	Este obra está bajo una licencia de Creative Commons Reconocimiento 4.0 Internacional.
	https://creativecommons.org/licenses/by/4.0/
*/
#ifndef SAPProgramer_h
#define SAPProgramer_h

#include "Arduino.h"

class SAPProgramer {
	public:
		SAPProgramer(int ENram, int WEram, );
		void lda(int data);
		void add(int data);
		void sub(int data);
		void out();
		void hlt();
	private:
		int _pin;
};

#endif
