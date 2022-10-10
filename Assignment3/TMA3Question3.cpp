/* 
 Title: TMA3Question2.h
 Description: Operator overloader testing
 Date: Feb. 10 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
 Based on Integer.cpp and IOstreamOperatorOverloading.cpp by Bruce Eckel, Chapter 12
*/

/*
 DOCUMENTATION

 Program Purpose: To create simple class called DoStuff
 				  which holds an int. This also contains
 				  the function print(&ostream) to display the
 				  integer contained in the class. 
 				  DoStuff also contains overloaded 
 				  operators operator+, operator-,
 				  operator++(prefix and postfix), 
 				  operator--(prefix and postfix), and 
 				  operator<<(same function as print()).
 				  Main() will contain the tests for 
 				  these operators and print().

 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA3Question3 TMA3Question3.cpp
 Or use the included makefile.

 Execution: (in a Command Prompt window): TMA1Question3.exe (or just TMA3Question3).
 
 Classes: DoStuff

 variables: i(int): The integer contained in a DoStuff class.
*/

/*
 TEST PLAN

 	Normal Case 1: Program is run(program contains no user input.)

 		Expected Output: 
 			Testing the additon and subtraction operators : DoStuff: one - two - four + five + three = 3

			Testing the postfix increment operator: 4
			Testing the prefix increment operator: 5
			Testing the postfix decrement operator: 4
			Testing the prefix decrement operator: 3
			Testing the print() function: 3

		Actual Output: As expected

 All overloaded operators are tested in main and there should be no
 abnormal or limiting cases. Normal case 1 is the only case the program
 will run into. 
*/

#include "TMA3Question3.h"
#include <iostream>

using namespace std;

//Overloaded binary addition operator
const DoStuff operator+(const DoStuff& left, const DoStuff& right){ 
	return DoStuff(left.i + right.i); 
}

//Overloaded binary subtraction operator
const DoStuff operator-(const DoStuff& left, const DoStuff& right){ 
	return DoStuff(left.i - right.i); 
}

const DoStuff& operator++(DoStuff& ds) {//Prefix increment
	ds.i++;
	return ds;
}
const DoStuff operator++(DoStuff& ds, int) {//Postfix increment
	DoStuff before(ds.i);
	ds.i++;
	return before;
}
const DoStuff& operator--(DoStuff& ds) {//Prefix decrement
	ds.i--;
	return ds;
}
const DoStuff operator--(DoStuff& ds, int) {//Postfix decrement
	DoStuff before(ds.i);
	ds.i--;
	return before;
}

ostream& operator<<(ostream& os, const DoStuff& ds) { //Output i
	os << ds.i << endl;
	return os;
}

void DoStuff::print(ostream& output) { //Output i
	output << i << endl;
}

int main() {
	DoStuff one(1), two(2), three(3), four(4), five(5);
	DoStuff x = one - two - four + five + three;
	cout << "Testing the additon and subtraction operators : "
		 << "DoStuff: one - two - four + five + three = " << x << endl;
	cout << "Testing the postfix increment operator: ";
	x++;
	cout << x;
	cout << "Testing the prefix increment operator: " << ++x;
	cout << "Testing the postfix decrement operator: ";
	x--;
	cout << x;
	cout << "Testing the prefix decrement operator: " << --x;
	cout << "Testing the print() function: ";
	x.print(cout);
	cout << "Exiting TMA3Question3..." << endl;
}