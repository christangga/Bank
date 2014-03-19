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
	const Queue& q(E);
	for (int i=0; i<E.getTeller(); ++i) {
		if (i > 0) {
			os << endl;
		}
		if (E.getQueue(i).size() > 0) {
			os << "Q[" << i << "] = {";
			os << E.getQueue(i);
			os << "}";
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
	int min = Q[0].size();
	for (int i=1; i<teller; ++i) {
		if (Q[i].size() < min && i != iOrigin) {
			min = Q[i].size();
		}
	}
	if (abs(Q[iOrigin].size() - Q[min].size()) <= 2) {
		return -1;
	}

	list<int> L;
	for (int i=0; i<teller; ++i) {
		if (Q[i].size() == min && i != iOrigin) {
			L.push_back(i);
		}
	}

	min = L.front();
	for (list<int>::iterator it=L.begin(); it!=L.end(); ++it) {
		if (it == L.begin()) {
			++it;
		} else if (abs(iOrigin - *it) < abs(iOrigin - min)) {
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
	int min = Q[0].size();
	for (int i=1; i<teller; ++i) {
		if (Q[i].size() < min) {
			min = Q[i].size();
		}
	}
	++customer;
	Q[min].add(customer);
}

void Event::departure(int n) {
	for (int i=0; i<teller; ++i) {
		if (Q[i].getHead() == n) {
			Q[i].del();
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
