#include <SAPProgramer.h>

SAPProgramer SAP1(48, 47);

void setup() {
	SAP1.lda(3);
	SAP1.add(2);
	SAP1.sub(1);
	SAP1.out();
	SAP1.hlt();
	DDRD = B00000000;
}

void loop() {
	PORTK = PIND;
}
