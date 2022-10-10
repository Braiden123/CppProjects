/* 
 Title: TMA3Question2.h
 Description: Header file for TMA3Question2.cpp
 Date: Jan. 27 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
 Based on Cpptime.h and Cpptime.cpp by Bruce Eckel, Chapter 9
 Also based on answer provided by gsamaras at 
 https://stackoverflow.com/questions/41077377/how-to-get-current-time-in-milliseconds
*/

/*
 DOCUMENTATION

 Program Purpose:
	To create two arrays of doubles, multiply their values
	and return the total time to finish the function to
	the user. The first array will contain sequential
	int values starting at 100. The second array will
	contain the same values as the first, but in 
	reverse order. This uses an inline function
	as opposed to TMA3Queston1.cpp which does not use
	an inline function.

 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA3Question2 TMA3Question2.h
 Or use the included makefile.

 Classes: None

 Variables: arr2limit(const double): Used to fill the second array with 
 									 values from the first array in 
 									 reverse order.
 			arr1[10000](double): Array with sequential int values 
 								 starting at 100.
 			arr2[10000](double): Array with the values in arr1
 								 in reverse order.
 			value(double): Used to track which number is being added
 						   to the arrays.
*/

#include <iostream>
using namespace std;

//Create the two arrays, multiply them to create the third array.
inline void CreateArrays() {
	const double arr2limit = 10199;
	double arr1[10000]; //Sequential int values starting at 100.
	double arr2[10000]; //arr 1 values but in reverse order
	double value = 100; //Used to fill arrays
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
		arr1[i] = value;
		arr2[i] = arr2limit - value;
		value++;
		cout << arr1[i] << " * " << arr2[i]
			 << " = " << arr1[i] * arr2[i] << endl;
	}
}