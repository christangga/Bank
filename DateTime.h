/* Nama File	: DateTime.h */
/* NIM - Nama	: 13512003 - Fauzan Hilmi Ramadhian */
/*				: 13512019 - Christ Angga Saputra */

#ifndef _DATETIME_H
#define _DATETIME_H
#include "Date.h"
#include "Time.h"

class DateTime {

public:
	DateTime();
	DateTime(int DD, int MM, int YY, int H, int M, int S);
	DateTime(const DateTime& DT);
	DateTime& operator=(const DateTime& DT);
	~DateTime();
	friend ostream& operator<<(ostream& os, const DateTime& DT);
	friend istream& operator>>(istream& is, DateTime& DT);

	DateTime getDateTime();
	void setDateTime(int DD, int MM, int YY, int H, int M, int S);

	int compare(DateTime DT);

private:
	Date D;
	Time T;

};

#endif
