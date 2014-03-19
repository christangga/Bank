/* Nama File	: Event.h */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#ifndef _EVENT_H
#define _EVENT_H
#include "Queue.h"
#include "DateTime.h"
#include <iostream>
//#include <ostream>

class Event {

public:
	Event();
	Event(DateTime TMax, int teller);
	~Event();
	friend ostream& operator<<(ostream& os, Event& E);

	Queue getQueue(int i);
	DateTime getTMax();
	int getCustomer();
	int getTeller();
	void setTMax(DateTime TMax);
	void setTeller(int teller);

	int jockeying(int iOrigin);
	void process(DateTime DT, char code);
	void arrival();
	void departure(int n);
	void closing();
	bool isEmpty();

private:
	Queue* Q;
	DateTime TMax;
	int teller;
	static int customer;

};

#endif
