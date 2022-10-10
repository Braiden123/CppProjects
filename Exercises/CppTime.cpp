//: C09:CppTime.cpp
//Testing a simple time class

#include "CppTime.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Time start;
	string input;
	while (true) {
		cout << "Press enter to end the timer." << endl;
		getline(std::cin, input);
		if (input == "") 
			break;
	}
	Time end;
	cout << endl;
	cout << "start = " << start.ascii() << endl;
	cout << "end = " << end.ascii() << endl;
	cout << "delta = " << end.delta(&start);
} ///:~