//: DoStuffOverload.h
#ifndef DOSTUFFOVERLOAD_H
#define DOSTUFFOVERLOAD_H

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

#endif // DOSTUFFOVERLOAD_H ///:~