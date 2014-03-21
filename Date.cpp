/* Nama File	: Date.cpp */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#include "Date.h"
#include <sstream>

Date::Date() {
	DD = 1;
	MM = 1;
	YY = 1;
}

Date::Date(int DD, int MM, int YY) {
	this->DD = DD;
	this->MM = MM;
	this->YY = YY;
}

Date::Date(const Date& D) {
	DD = D.DD;
	MM = D.MM;
	YY = D.YY;
}

Date& Date::operator=(const Date& D) {
	DD = D.DD;
	MM = D.MM;
	YY = D.YY;

	return *this;
}

Date::~Date() {}

ostream& operator<<(ostream& os, const Date& D) {
	os << D.DD << "-" << D.MM << "-" << D.YY;
}

istream& operator>>(istream& is, Date& D) {
	string str;
	is >> str;
	for (int i=0; i<str.length(); ++i) {
		if (str[i] == '-') {
			str[i] = ' ';
		}
	}

	istringstream iss(str);
	iss >> D.DD >> D.MM >> D.YY;

	return is;
}

Date Date::getDate() {
	return *this;
}

void Date::setDate(int DD, int MM, int YY) {
	this->DD = DD;
	this->MM = MM;
	this->YY = YY;
}

int Date::compare(Date D)
{
	if (DD>D.DD)
		return 1;
	else if (DD<D.DD)
		return -1;
	else
	{
		if (MM>D.MM)
			return 1;
		else if (MM<D.MM)
			return -1;
		else
		{
			if (YY>D.YY)
				return 1;
			else if (YY<D.YY)
				return -1;
			else
				return 0;
		}
	}
}
