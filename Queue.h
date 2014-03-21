/* Nama File	: Queue.h */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#ifndef _QUEUE_H
#define _QUEUE_H
#include <iostream>
#include <list>
using namespace std;

class Queue {

public:
	Queue();
	Queue(const Queue& Q);
	Queue& operator=(const Queue& Q);
	~Queue();
	friend ostream& operator<<(ostream& os, const Queue& Q);

	int getHead();
	int getTail();
	bool isEmpty();
	int size();
	void add(int i);
	void del();
	int move();

private:
	list<int> L;

};

#endif
