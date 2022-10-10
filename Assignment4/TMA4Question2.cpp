/* 
 Title: TMA4Question2.cpp
 Description: Rodent inheritance heirarchy
 Date: Feb. 22 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
 Based on PureVirtualDefinitions.cpp by Bruce Eckel, Chapter 12
*/

/*
 DOCUMENTATION

 Program Purpose:
 	Create an inheritance hierarchy of Rodent: Mouse, Gerbil, Hamster, etc.
 	In the base class, provide methods that are common to all Rodents, 
 	and refine these in the derived classes to perform different behaviours 
 	depending on the specific type of Rodent. Rodent must be created as a
 	pure abstract base class. Create an array of pointers (10) to Rodent, 
 	and fill it with different specific types of Rodents. 
 	Call your base class methods, and display the results.

 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA4Question2 TMA4Question2.cpp
 Or use the included makefile.

 Execution: (in a Command Prompt window): TMA4Question2.exe (or just TMA4Question2)

 Classes: Rodent: Pure abstract base class for all other classes in this program to derive from.
 				  Contains pure virtual functions for speak(),eat(), sleep() and destructor.
 		  Mouse: Derives from the Rodent class, contains unique functions for speak(),eat(), and sleep().
 		  Gerbil: Derives from the Rodent class, contains unique functions for speak(),eat(), and sleep().
 		  Hamster: Derives from the Rodent class, contains unique functions for speak(),eat(), and sleep().

 Variables: No significant variables used.
*/

/*
 TEST PLAN

 	Normal Case 1: Array of 10 rodent pointers containing: [Hamster]
 											   			   [Hamster]
 											   			   [Hamster]
 											   			   [Gerbil]
 											   			   [Gerbil]
 											   			   [Gerbil]
 											   			   [Gerbil]
 											   			   [Mouse]
 											   			   [Mouse]
 											   			   [Mouse]

 	Expected Output:Hamster::speak()
					Hamster::eat()
					Hamster::sleep()

					Hamster::speak()
					Hamster::eat()
					Hamster::sleep()

					Hamster::speak()
					Hamster::eat()
					Hamster::sleep()

					Gerbil::speak()
					Gerbil::eat()
					Gerbil::sleep()

					Gerbil::speak()
					Gerbil::eat()
					Gerbil::sleep()

					Gerbil::speak()
					Gerbil::eat()
					Gerbil::sleep()

					Gerbil::speak()
					Gerbil::eat()
					Gerbil::sleep()

					Mouse::speak()
					Mouse::eat()
					Mouse::sleep()

					Mouse::speak()
					Mouse::eat()
					Mouse::sleep()

					Mouse::speak()
					Mouse::eat()
					Mouse::sleep()

	Actual Output: As expected.
*/

#include <iostream>
#include <string>
using namespace std;

class Rodent {
public:
	virtual ~Rodent() = 0;
	virtual void speak() = 0;
	virtual void eat() = 0;
	virtual void sleep() = 0;
};

inline Rodent::~Rodent() {}

class Mouse : public Rodent {
public:
	~Mouse() {};
	void speak() {cout << "Mouse::speak()" << endl;}
	void eat() {cout << "Mouse::eat()" << endl;}
	void sleep() {cout << "Mouse::sleep()" << endl;}
};

class Gerbil : public Rodent {
public:
	~Gerbil() {};
	void speak() {cout << "Gerbil::speak()" << endl;}
	void eat() {cout << "Gerbil::eat()" << endl;}
	void sleep() {cout << "Gerbil::sleep()" << endl;}
};

class Hamster : public Rodent {
public:
	~Hamster() {};
	void speak() {cout << "Hamster::speak()" << endl;}
	void eat() {cout << "Hamster::eat()" << endl;}
	void sleep() {cout << "Hamster::sleep()" << endl;}
};

int main() {
	Rodent* rodArray[] = {new Hamster(), new Hamster(), 
					new Hamster(), new Gerbil(),
					new Gerbil(), new Gerbil(),
					new Gerbil(), new Mouse(),
					new Mouse(), new Mouse()};
	for (int i = 0; i < sizeof(rodArray) / sizeof(rodArray[0]); i++) {
		rodArray[i]->speak();
		rodArray[i]->eat();
		rodArray[i]->sleep();
		cout << endl;
	}
	//Cleanup
	for (int i = 0; i < sizeof(rodArray) / sizeof(rodArray[0]); i++)
		delete rodArray[i];
}