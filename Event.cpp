/* Nama File	: Event.cpp */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#include "Event.h"
#include <cstdlib>

Event::Event() {}

Event::Event(DateTime TMax, int teller) {
	Q = new Queue[teller];
	this->TMax = TMax;
	this->teller = teller;
	customer = 0;
}

Event::~Event() {
	delete[] Q;
}

ostream& operator<<(ostream& os, Event& E) {
	bool enter = false;
	for (int i=0; i<E.getTeller(); ++i) {
		if (E.getQueue(i).size() > 0) {
			if (enter) {
				os << endl;
			}
			os << "Q[" << i << "] = {" << E.getQueue(i) << "}";
			enter = true;
		}
	}

	return os;
}

Queue Event::getQueue(int i) {
	return Q[i];
}

DateTime Event::getTMax() {
	return TMax;
}

int Event::getCustomer() {
	return customer;
}

int Event::getTeller() {
	return teller;
}

void Event::setTMax(DateTime TMax) {
	this->TMax = TMax;
}

void Event::setTeller(int teller) {
	this->teller = teller;
}

int Event::jockeying(int iOrigin) {
	int min = 0;
	for (int i=1; i<teller; ++i) {
		if (Q[i].size() < Q[min].size()) {
			min = i;
		}
	}
	if (abs(Q[iOrigin].size() - Q[min].size()) <= 2) {
		return -1;
	}

	list<int> L;
	for (int i=0; i<teller; ++i) {
		if (Q[i].size() == Q[min].size() && i != iOrigin) {
			L.push_back(i);
		}
	}

	min = L.front();
	for (list<int>::iterator it=L.begin(); it!=L.end(); ++it) {
		if (it != L.begin() && abs(iOrigin - *it) < abs(iOrigin - min)) {
			min = *it;
		}
	}

	return min;

}

void Event::process(DateTime DT, char code) {
	int n;
	if (code == 'D') {
		cin >> n;
	}
	if (DT.compare(TMax) <= 0) {
		if (code == 'A') {
			arrival();
		} else if (code =='D') {
			departure(n);
		}
	}
}

void Event::arrival() {
	int min = 0;
	for (int i=1; i<teller; ++i) {
		if (Q[i].size() < Q[min].size()) {
			min = i;
		}
	}
	++customer;
	Q[min].add(customer);
}

void Event::departure(int n) {
	for (int i=0; i<teller; ++i) {
		if (Q[i].getHead() == n) {
			Q[i].del();
			cout << "masuk"<< endl;
			int jockey = jockeying(i);
			cout << "jockey " << jockey << endl;
			if (jockey >= 0) {
				Q[jockey].add(Q[i].move());
			}
			break;
		}
	}
}

void Event::closing() {
	while (!isEmpty()) {
		for (int i=0; i<teller; ++i) {
			if (!Q[i].isEmpty()) {
				cout << "Departure " << Q[i].getHead() << endl;
				Q[i].del();
			}
		}
	}
}

bool Event::isEmpty() {
	for (int i=0; i<teller; ++i) {
		if (!Q[i].isEmpty()) {
			return false;
		}
	}

	return true;
}
