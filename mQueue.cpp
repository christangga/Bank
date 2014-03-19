/* Nama File	: mQueue.cpp */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#include "Queue.h"

int main() {
	Queue Q1, Q2;
	int n;

	cout << Q1.isEmpty() << endl;
	cin >> n;
	while (n >= 0) {
		Q1.add(n);
		cin >> n;
	}
	cin >> n;
	while (n >= 0) {
		Q1.del();
		cin >> n;
	}
	Q2 = Q1;
	Queue Q3 = Q2;
	cout << Q3.size() << endl;
	cout << Q3 << endl;

	return 0;
}
