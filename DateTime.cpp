/* Nama File	: DateTime.cpp */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#include "DateTime.h"
#include <sstream>

DateTime::DateTime() {}

DateTime::DateTime(int DD, int MM, int YY, int H, int M, int S) {
	D.setDate(DD, MM, YY);
	T.setTime(H, M, S);
}

DateTime::DateTime(const DateTime& DT) {
	D = DT.D;
	T = DT.T;
}

DateTime& DateTime::operator=(const DateTime& DT) {
	D = DT.D;
	T = DT.T;

	return *this;
}

DateTime::~DateTime() {}

ostream& operator<<(ostream& os, const DateTime& DT) {
	os << DT.D << ";" << DT.T;
}

istream& operator>>(istream& is, DateTime& DT) {
	string str;
	is >> str;
	for (int i=0; i<str.length(); ++i) {
		if (str[i] == ';') {
			str[i] = ' ';
		}
	}

	istringstream iss(str);

	iss >> DT.D >> DT.T;

	return is;
}

DateTime DateTime::getDateTime() {
	return *this;
}

void DateTime::setDateTime(int DD, int MM, int YY, int H, int M, int S) {
	D.setDate(DD, MM, YY);
	T.setTime(H, M, S);
}

int DateTime::compare(DateTime DT) 
{
	if (D.compare(DT.D) == 0)
		return (T.compare(DT.T));
	else
		return (D.compare(DT.D));
}
