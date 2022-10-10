/* 
 Title: TMA2Question3.cpp
 Description: Nested class program
 Date: Jan. 14 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
 Based on Stack3.cpp by Bruce Eckel, chapter 6.
*/

/*
 DOCUMENTATION

 Program Purpose: 
	To create a Hen class which has a nested class
	called "Nest" which will have another nested
	class called "Egg". Each class will have 
	constructors and destructors which will
	print an appropriate message when called.
	Each class will have a display() function
	which will print out information regarding
	the class.
 
 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA2Question3 TMA2Question3.cpp
 Execution: (in a Command Prompt window): TMA2Question3.exe (or just TMA2Question3)

 Classes: Hen
 		  Nest(nested in Hen)
 		  Egg(nested in Nest)

 Variables: None
*/

/*
 TEST PLAN

 	Normal case 1: 

 		Expected Output: Hen constructor called.
 						 Nest constructor called.
 						 Egg constructor called
 						 Hen
 						 Nest is nested in Hen.
 						 Egg is nested in Nest, which is nested in Hen
 						 Hen destructor called.
 						 Nest destructor called.
 						 Egg destructor called.

 		Actual Output: As expected.

 	Due to the static nature of this program Normal case 1 is the only test case.
*/

#include <iostream>
#include <string>
#include "TMA2Question3.h"

using namespace std;

Hen::Hen() { //Hen constructor
	cout << "Hen constructor called." << endl;
}

Hen::~Hen() { //Hen destructor
	cout << "Hen destructor called." << endl;
}
void Hen::display() { //Display Hen info
	cout << "Hen" << endl;
}

Hen::Nest::Nest() { //Nest constructor
	cout << "Nest constructor called." << endl;
}

Hen::Nest::~Nest() { //Nest destructor
	cout << "Nest destructor called." << endl;
}

void Hen::Nest::display() { //Display Nest Info
	cout << "Nest is nested in Hen." << endl;
}

Hen::Nest::Egg::Egg() { //Egg constructor
	cout << "Egg constructor called." << endl;
}

Hen::Nest::Egg::~Egg() { //Egg destructor
	cout << "Egg destructor called." << endl;
}

void Hen::Nest::Egg::display() { //Display Egg info
	cout << "Egg is nested in Nest, which is nested"
		 << " in Hen." << endl;
}

int main() {
	Hen* hen = new Hen();
	Hen::Nest* nest = new Hen::Nest();
	Hen::Nest::Egg* egg = new Hen::Nest::Egg();
	hen->display();
	nest->display();
	egg->display();
	delete hen;
	delete nest;
	delete egg;
}