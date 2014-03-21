/* Nama File	: Main.cpp */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#include "Event.h"

int main() {
	DateTime TMax, DT;
	int teller;
	char code;

	cin >> TMax;
	//cout << TMax << endl;
	cout << "teller: "; cin >> teller;
	Event E(TMax, teller);
	do {
		cin >> DT >> code;
		if (DT.compare(TMax) <= 0) {
			E.process(DT, code);
			cout << E << endl;
		}
	} while (DT.compare(TMax) < 0);
	cout << "Loop terminate" << endl;
	E.closing();

	return 0;
}
