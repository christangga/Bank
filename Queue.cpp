/* Nama File	: Queue.cpp */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#include "Queue.h"

Queue::Queue() {}

Queue::Queue(const Queue& Q) {
	L.assign(Q.L.begin(), Q.L.end());
}

Queue& Queue::operator=(const Queue& Q) {
	L.assign(Q.L.begin(), Q.L.end());

	return *this;
}

Queue::~Queue() {}

ostream& operator<<(ostream& os, const Queue& Q) {
	for (list<int>::const_iterator it=Q.L.begin(); it!=Q.L.end(); ++it) {
		if (it != Q.L.begin()) {
			os << ", ";
		}
		os << *it;
	}

	return os;
}

int Queue::getHead() {
	return L.front();
}

int Queue::getTail() {
	return L.back();
}

bool Queue::isEmpty() {
	return L.empty();
}

int Queue::size() {
	return L.size();
}

void Queue::add(int i) {
	L.push_back(i);
}

void Queue::del() {
	L.pop_front();
}

int Queue::move() {
	int tail = getTail();
	L.pop_back();

	return tail;
}
