/* 
 Title: TMA3Question1.cpp
 Description: Array creation and runtime recording
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
	reverse order.

 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA3Question1 TMA3Question1.cpp
 Or use the included makefile.

 Execution: (in a Command Prompt window): TMA1Question1.exe (or just TMA3Question1)

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
 			starttime(high_resolution_clock::time_point):
 						Used to track time at the start of runtime.
 			endtime(high_resolution_clock::time_point):
						Used to track the time when the CreateArrays()
						function has completed.
*/

/*
 TEST PLAN

 	Normal Case 1: 

 			Expected Output:
						
						100 * 10099 = 1.0099e+006
						101 * 10098 = 1.0199e+006
						102 * 10097 = 1.02989e+006
						...
						10097 * 102 = 1.02989e+006
						10098 * 101 = 1.0199e+006
						10099 * 100 = 1.0099e+006

						Time for completion: (Difference between start
											  time and end time) milliseconds

			Actual Output: As expected.(I got between 5619-17699 milliseconds during tests)
						   Times were independently tested with a stopwatch.
 
 Due to the static nature of this program Normal Case 1 will be the only
 case, but results will vary between machines.
*/

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std::chrono;

//Create the two arrays, multiply them to create the third array.
void CreateArrays() {
	const double arr2limit = 10199;
	double arr1[10000]; //Sequential int values starting at 100.
	double arr2[10000]; //arr 1 values but in reverse order
	double value = 100; //Used to fill arrays
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
		arr1[i] = value;
		arr2[i] = arr2limit - value;
		value++;
		std::cout << arr1[i] << " * " << arr2[i]
			 << " = " << arr1[i] * arr2[i] << std::endl;
	}
}

int main() {
	//Get current time at runtime
	const high_resolution_clock::time_point starttime = high_resolution_clock::now();
	CreateArrays();
	high_resolution_clock::time_point endtime = high_resolution_clock::now();
	duration<double, std::milli> timediff = endtime - starttime;
	std::cout << "Time for completion: " << timediff.count() << " milliseconds." << std::endl;
	std::cout << "Exiting TMA3Question1.cpp." << std::endl;
}