//: C09:Cpptime.h
//A simple time class
#ifndef CPPTIME_H
#define CPPTIME_H
#include <ctime>
#include <cstring>

class Time {
	std::time_t t;
	std:: tm local;
	char asciiRep[26];
	unsigned char lflag, aflag;
	void updateLocal() {
		if(!lflag) {
			local = *std::localtime(&t);
			lflag++;
		}
	}
	void updateAscii() {
		if(!aflag) {
			updateLocal();
			std::strcpy(asciiRep,std::asctime(&local));
			aflag++;
		}
	}
public:
	Time() { mark(); }

	void mark() {
		lflag = aflag = 0;
		std::time(&t);
	}
	const char* ascii() {
		updateAscii();
		return asciiRep;
	}

	//Difference in seconds:
	int delta(Time* dt) const {
		return int(std::difftime(t, dt->t));
	}
	int daylightSavings() {
		updateLocal();
		return local.tm_isdst;
	}
	int dayOfYear() { //Since Jan 1
		updateLocal();
		return local.tm_yday;
	}
	int dayOfWeek() { //Since Sunday
		updateLocal();
		return local.tm_wday;
	}
	int since1900() { //years since 1990
		updateLocal();
		return local.tm_year;
	}
	int month() { //Since Jan
		updateLocal();
		return local.tm_mon;
	}
	int dayOfMonth() {
		updateLocal();
		return local.tm_mday;
	}
	int hour() { //since midnight, 24-hour clock
		updateLocal();
		return local.tm_hour;
	}
	int minute() {
		updateLocal();
		return local.tm_min;
	}
	int second() {
		updateLocal();
		return local.tm_sec;
	}
};
#endif // CPPTIME_H ///:~