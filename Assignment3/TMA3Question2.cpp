/* 
 Title: TMA3Question2.cpp
 Description: Array creation and runtime recording with inline functions
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
	 Program Purpose:
	To create two arrays of doubles, multiply their values
	and return the total time to finish the function to
	the user. The first array will contain sequential
	int values starting at 100. The second array will
	contain the same values as the first, but in 
	reverse order. This program will call the 
	CreateArrays() function from TMA3Question2.h, 
	which is an inline function.

 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA3Question2 TMA3Question2.cpp
 Or use the included makefile.

 Execution: (in a Command Prompt window): TMA1Question2.exe (or just TMA3Question2)

 Classes: None

 Variables: 
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

		Actual Output: I ran both TMA3Question1 and TMA3Question2 three times for testing

		Test 1: TMA3Question1 Time = 7677.82 milliseconds.
				TMA3Question2 Time = 7607.97 milliseconds.
				Difference = TMA3Question2 was 69.85 milliseconds faster.
		Test 2: TMA3Question1 Time = 7303.5 milliseconds.
				TMA3Question2 Time = 7652.49 milliseconds.
				Difference = TMA3Question1 was 346.99 milliseconds faster.
		Test 3: TMA3Question1 Time = 7301.45 milliseconds.
				TMA3Question2 Time = 7371.22 milliseconds.
				Difference = TMA3Question1 was 69.77 milliseconds faster

		Conclusion: The original program without inlining was slightly faster
					than the program with inlining. This is likely due to the compiler
					ignoring the inline request since the function contains
					a long for loop.
*/

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include "TMA3Question2.h"
using namespace std::chrono;

int main() {
	//Get current time at runtime
	const high_resolution_clock::time_point starttime = high_resolution_clock::now();
	CreateArrays();
	high_resolution_clock::time_point endtime = high_resolution_clock::now();
	duration<double, std::milli> timediff = endtime - starttime;
	std::cout << "Time for completion: " << timediff.count() << " milliseconds." << std::endl;
	std::cout << "Exiting TMA3Question2.cpp." << std::endl;
}