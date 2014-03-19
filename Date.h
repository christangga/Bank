/* Nama File	: Date.h */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#ifndef _DATE_H
#define _DATE_H

class Date {

public:
	Date();
	Date(int DD, int MM, int YY);
	Date(const Date& D);
	Date& operator=(const Date& D);
	~Date();

	Date getDate();
	void setDate(int DD, int MM, int YY);

	int compare(Date D);

private:
	int DD;
	int MM;
	int YY;

};

#endif
