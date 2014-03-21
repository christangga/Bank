/* Nama File	: Date.h */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#ifndef _DATE_H
#define _DATE_H
#include <iostream>
using namespace std;

class Date {

public:
	Date();
	Date(int DD, int MM, int YY);
	Date(const Date& D);
	Date& operator=(const Date& D);
	~Date();
	friend ostream& operator<<(ostream& os, const Date& D);
	friend istream& operator>>(istream& is, Date& D);

	Date getDate();
	void setDate(int DD, int MM, int YY);

	int compare(Date D);

private:
	int DD;
	int MM;
	int YY;

};

#endif
