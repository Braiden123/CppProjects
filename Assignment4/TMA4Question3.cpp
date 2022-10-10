/* 
 Title: TMA4Question3.cpp
 Description: Set template
 Date: Feb. 26 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
 Based on TPStash2.h and TStack2.h by Bruce Eckel, Chapter 16
*/

/*
 DOCUMENTATION

 Program Purpose:

 	Using the Standard C++ Library vector as an underlying implementation,
 	create a Set template class that accepts only one of each type of object 
 	that you put into it. Make a nested iterator class that supports the 
 	“end sentinel” concept in Unit 16. Write test code for your Set in main(), 
 	using both your Set template class and the Standard C++ Library set template 
 	to verify that the behaviour is correct.

 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA4Question3 TMA4Question3.cpp
 Or use the included makefile.

 Execution: (in a Command Prompt window): TMA4Question3.exe (or just TMA4Question3)

 Classes: Set(template): Used as a template to hold any data point and simulate 
 						 a set.
 		  Iterator(nested in Set): Iterator for Set to navigate through the set.

 Variables: data (vector<T>: Vector as the underlying implementation of Set.
 			index(int): To record the position inside the set.
*/

/*
 TEST PLAN

 	Normal Case 1: Input 1,2,2,9,4 into the custom set then delete the element
 				   at position 1. Then create a set containing 1,2,and 3 into 
 				   the standard c library set, then delete 1.

 		Expected Output: 	Adding: 1
							Adding: 2
							Attempting to add element that already exists.
							Data already exists in this set.
							Adding: 9
							Adding: 4
							The elements currently in the set:
							1
							2
							4
							9
							Deleting element at position one...
							Deleting: 2
							Testing deleting an element outside of range...
							Set::iterator::operator+=() tried to move out of bounds.
							Iterator out of bounds.
							The elements currently in the set:
							1
							4
							9
							Testing standard set library for comparison
							The elements currently in the set:
							 1 2 3
							Deleting 1:
							The elements currently in the set:
							 1 3

		Actual Output: As expected.
 
 Due to the static nature of this program Normal Case 1 is the only case.
*/

#include "TMA4Question3.h"
#include <iostream>
#include <set>
using namespace std;

int main() {
	Set<int> set;
	set.insert(1);
	set.insert(2);
	cout << "Attempting to add element that already exists." << endl;
	set.insert(2);
	set.insert(9);
	set.insert(4);
	Set<int>::iterator it = set.begin();
	cout << "The elements currently in the set:" << endl;
	while (it != set.end()) {
		cout << it++ << endl;
	}
	cout << "Deleting element at position one..." << endl;
	set.erase(it -= 3);
	cout << "Testing deleting an element outside of range..." <<endl;
	set.erase(it -= 20);
	Set<int>::iterator it2 = set.begin();
	cout << "The elements currently in the set:" << endl;
	while (it2 != set.end()) {
		cout << it2++ << endl;
	}
	cout << "Testing standard set library for comparison" << endl;
	std::set<int> standardset;
	standardset.insert(1);
	standardset.insert(2);
	standardset.insert(3);
	cout << "The elements currently in the set:" << endl;
	for (std::set<int>::iterator stdit = standardset.begin(); 
		stdit != standardset.end(); stdit++)
		cout << " " << *stdit;
	cout << "\nDeleting 1:" << endl;
	standardset.erase(1);
	cout << "The elements currently in the set:" << endl;
	for (std::set<int>::iterator stdit2 = standardset.begin(); 
		stdit2 != standardset.end(); stdit2++)
		cout << " " << *stdit2;
}