//: TMA1Question5.cpp

/* 
 Title: TMA1Question5.cpp
 Description: Reads the Question5Read.txt file then stores each line
			  as a string object in an array of 100. The program will
			  then output the contents of each line to the user. 
 			  
 Date: Nov. 12 2019
 Author: Braiden Little
 Student ID# 3364064
 Version: 1.0
 Copyright: 2019 Braiden Little
*/

/*
DOCUMENTATION

Program Purpose: To use an array of strings to store each line in
				 Question5Read.txt as a seperate string. Then 
				 display each string in the array to the user.
				 The program will end if the end of the file is 
				 reached before 100 lines have been stored.

 Compile: (assuming mingw compiler and opened command prompt): 
 g++ -o TMA1Question5 TMA1Question5.cpp 
 Alternatively, use the included make file to compile all questions for TMA1.
 Make file execution(assuming mingw compiler): mingw32-make -f makefile.txt
 Execution: (in a Command Prompt window):TMA1Question5.exe (or just TMA1Question5)
 
 Classes: None

 Variables:
 		read (ifstream) = To read the Question5Read.txt file.
 		lines[100] (string) = Array of strings to store the
 							  lines of Question5Read.txt.
*/

/*
TEST PLAN

Normal Case 1:
			  <Read the Question5Read.txt file with 100 lines

			  Expected Output: Line 1: This is the first line.
							   Line 2: This is the second line.
							   Line 3: This is the third line.
							   ...
							   Line 98: This is the ninty-eighth line.
							   Line 99: This is the ninty-ninth line.
							   Line 100: This is the hundredth line.

			  Actual Output: As expected.

Limiting Case 1:
				<Read the Question5Read.txt file with 90 lines.

				Expected Output:Line 1: This is the first line.
							    Line 2: This is the second line.
							    Line 3: This is the third line.
							    ...
							    Line 88: This is the eighty-eighth line.
								Line 89: This is the eighty-ninth line.
								Line 90: This is the nintieth line.

				Actual Output: As expected.

Limiting Case 2:
				<Read the Question5Read.txt file with 110 lines.

				Expected Output: Line 1: This is the first line.
							   	 Line 2: This is the second line.
							     Line 3: This is the third line.
							     ...
							     Line 98: This is the ninty-eighth line.
							     Line 99: This is the ninty-ninth line.
							     Line 100: This is the hundredth line.

			 	 Actual Output: As expected.

Discussion: The program will continue reading lines until there are no 
			more lines to read or 100 lines have been read. Because of
			this the program should never output more than 100 lines.
*/

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream read("Question5Read.txt");
	string lines[100];
	for (int i = 0; i < 100; i++) {
		if (!getline(read, lines[i])) //No more lines in the file.
			break;
		cout << "Line " << (i + 1) << ": " << lines[i] << endl;
	}
}