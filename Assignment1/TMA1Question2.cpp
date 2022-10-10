//: TMA1Question2.cpp

/* 
 Title: TMA1Question2.cpp
 Description: Opens a text file and display the contents of
 			  that file one line at a time, prompting the
 			  user to hit enter to continue to the next
 			  line in the file. 
 Date: Nov. 25 2019
 Author: Braiden Little
 Student ID# 3364064
 Version: 1.1
 Copyright: 2019 Braiden Little
 Based on Scopy.cpp and DynamicDebugflags.cpp by Bruce Eckel, chapter 2, chapter 3.
*/

/*
DOCUMENTATION

Program Purpose:
	To open the Question2Read.txt file read the file one line
	at a time, continuing to the next line when the user
	presses the enter key. 
	Also contains code to provide debugging information if


 Compile: (assuming mingw compiler and opened command prompt): 
 g++ -o TMA1Question2 TMA1Question2.cpp 
 Alternatively, use the included make file to compile all questions for TMA1.
 Make file execution(assuming mingw compiler): mingw32-make -f make
 Execution: (in a Command Prompt window):TMA1Question2.exe (or just TMA1Question2)
 Debug mode compile and execution(assuming mingw compiler): mingw32-make -f make debug
 
 Classes: None

 Variables:
 	read (ifstream) = Object to read the Question2Read.txt file.
 	line (string) = String to contain the next line of Question2Read.txt
 	input (string) = String to contain user input.
 	
*/

/*
TEST PLAN
	
Normal case 1:
	>This program will read Question2Read.txt one line at 
	 a time, press enter to read the next line. Otherwise, 
	 enter q to exit the program.

	Input: Pressing enter until the file has been read.

	Expected Output: This file is to be read

					 by the program TMA1Question2.cpp

					 one line at at time.

					 This file contains

					 5 lines to be read.

					 End of the file has been reached.
					 Exiting the program 'TMA1Question2'.

	Actual Output: As expected

Normal case 2:
	>This program will read Question2Read.txt one line at 
	 a time, press enter to read the next line. Otherwise, 
	 enter q to exit the program.

	Input: Pressing enter two times then entering q to exit the program

	Expected Output: This file is to be read

					 by the program TMA1Question2.cpp

					 Exiting the program 'TMA1Question2'.

	Actual Output: As expected

Normal case 3:
	>This program will read Question2Read.txt one line at 
	 a time, press enter to read the next line. Otherwise, 
	 enter q to exit the program.
		
	Input: Enter 'Q' at the start of the program

	Expected Output: Exiting the program 'TMA1Question2'.

	Actual Output: As expected.

Normal case 4:
	>Debugging mode

	Input: Enter 'on' when starting debugging

	Expected Output: Debugger is on!

	Actual Output: As expected.

Normal case 5:
	>Debugging mode

	Input: Enter 'off' when starting debugging

	Expected Output: Debugger is off!

	Actual Output: As expected.

Normal case 6:
	>Debugging mode

	Input: Enter 'quit' when starting debugging

	Expected Output: Proceed to the production build
					 of the program.

	Actual Output: As expected.


Limiting case 1:
	>This program will read Question2Read.txt one line at 
	 a time, press enter to read the next line. Otherwise, 
	 enter q to exit the program.
	
	Input: "This sentence is a limiting test of the program."
		   Then entering q to exit the program

	Expected Output: Use only the enter key to continue or enter q
					 to exit the program.

					 Exiting the program 'TMA1Question2'.

	Actual Output: As expected.

Abnormal case 1:
	>This program will read Question2Read.txt one line at 
	 a time, press enter to read the next line. Otherwise, 
	 enter q to exit the program.
	
	Input: -100000
		   Then pressing enter until the file has been read

	Expected Output: Use only the enter key to continue or enter q
					 to exit the program.

					 This file is to be read

					 by the program TMA1Question2.cpp

					 one line at at time.

					 This file contains

					 5 lines to be read.

					 End of the file has been reached.
					 Exiting the program 'TMA1Question2'.

	Actual Output: As expected.

Abnormal case 2:
	>This program will read Question2Read.txt one line at 
	 a time, press enter to read the next line. Otherwise, 
	 enter q to exit the program.
	
	Input: 100%
		   Then pressing enter until the file has been read

	Expected Output: Use only the enter key to continue or enter q
					 to exit the program.

					 This file is to be read

					 by the program TMA1Question2.cpp

					 one line at at time.

					 This file contains

					 5 lines to be read.

					 End of the file has been reached.
					 Exiting the program 'TMA1Question2'.

	Actual Output: As expected.

Discussion: The program will only accept the inputs of q (uppercase or lowercase)
			and blank input(user simply hitting enter) and will not continue or
			exit the program until the user provides valid input.
*/

#include <fstream>
#include <iostream>
#include <string>

bool debug = false; //Global debug
bool test_mode = false; //Global test_mode

using namespace std;

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		if (string(argv[i]) == "debug=on")
			debug = true;
	}
	if (debug) {
	while(true) {
		if (debug)
			cout << "Debugger is on!" << endl;
		else
			cout << "Debugger is off!" << endl;
		cout << "Turn debugger [on/off/quit]: ";
		string input;
		cin >> input;
		if (input == "on")
			debug = true;
		else if (input == "off")
			debug = false;
		else if (input == "quit")
			break;
		else
			cout << "Only enter 'on', 'off', or 'quit'." << endl;
	}	
	}

	ifstream read("Question2Read.txt");
	string line, input;
	cout << "This program will read Question2Read.txt one line at \n"
		 << "a time, press enter to read the next line. Otherwise, \n"
		 << "enter q to exit the program." << endl;
	while (true) { //Run until user exits or file is read.
		cout << endl; // New line for readability
		getline(std::cin, input); //Get user input
		if (input == "") { //User has only hit "enter"
			if (getline(read, line)) 
				cout << line; 
			else {
				cout << "End of the file has been reached." << endl;
				break; //Exit the program
			}
		}
		else if (input == "q" || input == "Q") //User wishes to exit.
			break;// Exit the program.
		else //To handle any input outside of "q", "Q", and enter.
			cout << "Use only the enter key to continue "
				 << "or enter q to exit the program.";
	}
	cout << "Exiting the program 'TMA1Question2'." << endl; 
}