/* 
 Title: TMA3Question2.h
 Description: Header file for TMA3Question3.cpp
 Date: Feb. 10 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
 Based on Integer.h by Bruce Eckel, Chapter 12
*/

/*
Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA3Question3 TMA3Question3.h
Or use the included makefile.
*/

#ifndef TMA3QUESTION3_H
#define TMA3QUESTION3_H

#include <iostream>
using namespace std;

class DoStuff {
	int i;
public: 
	DoStuff() : i(0) {}
	DoStuff(int ii) : i(ii) {}	
	friend const DoStuff operator+(const DoStuff& left, const DoStuff& right);
	friend const DoStuff operator-(const DoStuff& left, const DoStuff& right);
	friend const DoStuff& operator++(DoStuff& ds);//Prefix
	friend const DoStuff operator++(DoStuff& ds, int);//Postfix
	friend const DoStuff& operator--(DoStuff& ds);//Prefix
	friend const DoStuff operator--(DoStuff& ds, int);//Postfix
	friend ostream& operator<<(ostream& os, const DoStuff& ds);
	void print(ostream& output);
};

#endif // TMA3QUESTION3_H ///:~