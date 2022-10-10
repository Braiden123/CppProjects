//: TMA1Question4.cpp

/* 
 Title: TMA1Question4.cpp
 Description: Finds and prints all the prime numbers from 1-10000.  
 Date: Nov. 8 2019
 Author: Braiden Little
 Student ID# 3364064
 Version: 1.0
 Copyright: 2019 Braiden Little
*/

/*
DOCUMENTATION

Program Purpose: To use two nested for loops and the modulus operator
				 to find every prime number from 1-10000. The first
				 loop will run through each number from 1-10000.
				 The second loop will use the modulus operator
				 to find every even divisor for the counter of the
				 first for loop. An break condition exists for the
				 second loop if more than two even divisors are found
				 to optimize for time. If the number has 2 or 1 divisors
				 then the number will be listed as a prime number.

 Compile: (assuming mingw compiler and opened command prompt): 
 g++ -o TMA1Question4 TMA1Question4.cpp 
 Alternatively, use the included make file to compile all questions for TMA1.
 Make file execution(assuming mingw compiler): mingw32-make -f makefile.txt
 Execution: (in a Command Prompt window):TMA1Question4.exe (or just TMA1Question4)
 
 Classes: None

 Variables:
 		divcounter (int) = Used to track the number of even divisors for a number
*/

/*
TEST PLAN

Normal Case 1:
		<Go through each number from 1-10000 and output each prime number found.

		Expected Output: All the prime numbers from 1-10000. 
						 1 is a prime number.
						 2 is a prime number.
						 3 is a prime number. 
						 5 is a prime number.
						 ...
						 9923 is a prime number.
						 9929 is a prime number.
						 9931 is a prime number.
						 9941 is a prime number.
						 9949 is a prime number.

		Actual Output: As expected.

Discussion: Since there is no user input required and no files are being read, normal
			case 1 is the only case this program will encounter. 
*/


#include <iostream>

using namespace std;

int main() {
	int divcounter = 0;
	for (int i = 1; i < 10000; i++) {
		divcounter = 0; //Reset the counter
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)
				divcounter++;
			if (divcounter > 2) //Number is not prime.
				break;
		}
		if (divcounter <= 2)
			cout << i << " is a prime number." << endl;
	}
}