//: TMA1Question3.cpp

/* 
 Title: TMA1Question3.cpp
 Description: Creates three vector<float> objects. The first
 			  object is filled with 25 floating-point numbers
 			  from 0-24. The second is filled with the numbers 
 			  from the first vector squared. The third contains 
 			  the sum of the corresponding elements of the first
 			  two vectors.
 			  
 Date: Nov. 7 2019
 Author: Braiden Little
 Student ID# 3364064
 Version: 1.0
 Copyright: 2019 Braiden Little
*/

/*
DOCUMENTATION

Program Purpose:
	To fill three vectors with 25 floating-point numbers. The first
	vector contains the numbers 0-24, the second vector contains the
	numbers in the first vector squared, finally the third vector
	contains the sum of the corresponding elements of the first and 
	second vectors.

 Compile: (assuming mingw compiler and opened command prompt): 
 g++ -o TMA1Question3 TMA1Question3.cpp 
 Alternatively, use the included make file to compile all questions for TMA1.
 Make file execution(assuming mingw compiler): mingw32-make -f makefile.txt
 Execution: (in a Command Prompt window):TMA1Question3.exe (or just TMA1Question3)
 
 Classes: None

 Variables:
 	numbers (vector<float>) = Vector to be filled with the values of a for loop
 							  counter variable.
 	squared (vector<float>) = Vector to be filled with the values of a for loop
 							  counter variable squared.
	sum (vector<float>) = Vector to be filled with the sums of the corresponding
						  elements from the first two vectors, and stores the result
						  in the corresponding element of the third vector. 
 	
*/

/*
TEST PLAN

Normal Case 1 
	<Fill the first vector with values 0 - 24, the second vector with the corresponding
	value squared, and the third vector with the sums of the first and second corresponding
	vecotrs. then print the values in the format “for counter; element + element = element”.

	Expected Output:
					0; 0 + 0 = 0.
					1; 1 + 1 = 2.
					2; 2 + 4 = 6.
					3; 3 + 9 = 12.
					4; 4 + 16 = 20.
					5; 5 + 25 = 30.
					6; 6 + 36 = 42.
					7; 7 + 49 = 56.
					8; 8 + 64 = 72.
					9; 9 + 81 = 90.
					10; 10 + 100 = 110.
					11; 11 + 121 = 132.
					12; 12 + 144 = 156.
					13; 13 + 169 = 182.
					14; 14 + 196 = 210.
					15; 15 + 225 = 240.
					16; 16 + 256 = 272.
					17; 17 + 289 = 306.
					18; 18 + 324 = 342.
					19; 19 + 361 = 380.
					20; 20 + 400 = 420.
					21; 21 + 441 = 462.
					22; 22 + 484 = 506.
					23; 23 + 529 = 552.
					24; 24 + 576 = 600.

	Actual Output: As expected.

Discussion: Since there is no user input required and no files are being read, normal
			case 1 is the only case this program will encounter. 
*/

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	vector<float> numbers, squared, sum;

	for (int i = 0; i < 25; i++) {
		numbers.push_back(i);
		squared.push_back(pow(i, 2));
		sum.push_back(numbers[i] + squared[i]);
		cout << i << "; " << numbers[i] << " + " << squared[i]
			 << " = " << sum[i] << "." << endl;
	}
}