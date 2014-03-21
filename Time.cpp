/* Nama File	: Time.cpp */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#include "Time.h"
#include <sstream>

Time::Time() {
	H = 1;
	M = 1;
	S = 1;
}

Time::Time(int H, int M, int S) {
	this->H = H;
	this->M = M;
	this->S = S;
}

Time::Time(const Time& T) {
	H = T.H;
	M = T.M;
	S = T.S;
}

Time& Time::operator=(const Time& T) {
	H = T.H;
	M = T.M;
	S = T.S;

	return *this;
}

Time::~Time() {}

ostream& operator<<(ostream& os, const Time& T) {
	os << T.H << ":" << T.M << ":" << T.S;
}

istream& operator>>(istream& is, Time& T) {
	string str;
	is >> str;
	for (int i=0; i<str.length(); ++i) {
		if (str[i] == ':') {
			str[i] = ' ';
		}
	}

	istringstream iss(str);
	iss >> T.H >> T.M >> T.S;

	return is;
}

Time Time::getTime() {
	return *this;
}

void Time::setTime(int H, int M, int S) {
	this->H = H;
	this->M = M;
	this->S = S;
}

int Time::compare(Time T)
{
	if (H > T.H)
		return 1;
	else if (H < T.H)
		return -1;
	else {
		if (M > T.M)
			return 1;
		else if (M < T.M)
			return -1;
		else {
			if (S > T.S)
				return 1;
			else if (S < T.S)
				return -1;
			else
				return 0;
		}
	}
}
