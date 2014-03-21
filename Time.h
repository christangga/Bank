/* Nama File	: Time.h */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#ifndef _TIME_H
#define _TIME_H
#include <iostream>
using namespace std;

class Time {

public:
	Time();
	Time(int H, int M, int S);
	Time(const Time& T);
	Time& operator=(const Time& T);
	~Time();
	friend ostream& operator<<(ostream& os, const Time& T);
	friend istream& operator>>(istream& is, Time& T);
	
	Time getTime();
	void setTime(int H, int M, int S);

	int compare(Time T);

private:
	int H;
	int M;
	int S;

};

#endif
