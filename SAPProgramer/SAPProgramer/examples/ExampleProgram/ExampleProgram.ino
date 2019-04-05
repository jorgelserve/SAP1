#include <SAPProgramer.h>

SAPProgramer SAP1(3,4);

void setup() {
	SAP1.lda(3);
	SAP1.add(2);
	SAP1.sub(1);
	SAP1.out();
	SAP1.hlt();
}

void loop() {}
