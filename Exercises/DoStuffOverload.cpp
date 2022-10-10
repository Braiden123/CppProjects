//: DoStuffOverload.cpp

#include "DoStuffOverload.h"
#include <iostream>

using namespace std;

const DoStuff operator+(const DoStuff& left, const DoStuff& right){ 
	return DoStuff(left.i + right.i); 
}

const DoStuff operator-(const DoStuff& left, const DoStuff& right){ 
	return DoStuff(left.i - right.i); 
}

const DoStuff& operator++(DoStuff& ds) {//Prefix
	ds.i++;
	return ds;
}
const DoStuff operator++(DoStuff& ds, int) {//Postfix
	DoStuff before(ds.i);
	ds.i++;
	return before;
}
const DoStuff& operator--(DoStuff& ds) {//Prefix
	ds.i--;
	return ds;
}
const DoStuff operator--(DoStuff& ds, int) {//Postfix
	DoStuff before(ds.i);
	ds.i--;
	return before;
}

ostream& operator<<(ostream& os, const DoStuff& ds) {
	os << ds.i << endl;
	return os;
}

void DoStuff::print(ostream& output) {
	output << i << endl;
}

int main() {
	DoStuff one(1), two(2), three(3);
	DoStuff x = one + two;
	cout << x;
	x.print(cout);
	DoStuff zero = two + one - three;
	cout << zero;
	x++;
	cout << x;
	cout << ++x;
	x--;
	cout << x;
	cout << --x;
	delete &one;
	delete &two;
	delete &three;
}