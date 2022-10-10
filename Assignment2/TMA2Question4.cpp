/* 
 Title: TMA2Question4.cpp
 Description: Text class that holds
 			  the text of a file and
 			  displays to the user.
 Date: Jan. 14 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
*/

/*
 DOCUMENTATION

  Program Purpose:
  	To create a Text class that has a string (called filename) 
  	for holding the text from a file. The Text class will have
  	two constructors, a default constructor, and a
  	constructor that takes a string parameter. The string
  	parameter is the name of the file to be read. This 
  	constructor will give an error and exit the program if 
  	the given file cannot be read. Otherwise the filename
  	string will be filled with the contents of the given
  	file. Text also includes a contents() function that 
  	will display the contents of the given file to the user. 

 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA2Question4 TMA2Question4.cpp
 Execution: (in a Command Prompt window): TMA2Question4.exe (or just TMA2Question4)

 Classes: Text

 Variables: filename(string): To store the filename given for display later.
 			filetext(string): To store the contents of the given file.
*/

/*
 TEST PLAN

 	Normal case 1: "TMA2Question4Read.txt" is entered when prompted.

		Expected Output:

			TMA2Question4Read.txt contents:
			This file's purpose is for
			testing the Text class from 
			TMA2Question4.cpp.

		Actual Output: As expected

	Normal case 2: "TMA2Question4.cpp" is entered when prompted.

		Expected Output:

			TMA2Question4.cpp contents:
			(All contents of this file.)

		Actual Output: As expected

	Abnormal case 1: "-1234567890" is entered when prompted.

		Expected Output:
			-1234567890
			-1234567890 cannot be found.
			Please ensure file name is typed correctly and is stored in the directory this program is located.
			Exiting Program...

	Limiting case 1: "Doesnotexist" is entered when prompted.

		Expected Output:
				
			Doesnotexist
			Doesnotexist cannot be found.
			Please ensure file name is typed correctly and is stored in the directory this program is located.
			Exiting Program...

		Actual Output: As expected
*/

#include <iostream>
#include <string>
#include <fstream>
#include "TMA2Question4.h"

Text::Text() {
	cout << "Default constructor called." << endl;
}

Text::Text(string filename) {
	string line;
	this->filename = filename;
	ifstream read(filename);
	if (!read.is_open()) { //File cannot be found, exit program.
		cout << filename << " cannot be found. \n"
			 << "Please ensure file name is typed "
			 << "correctly and is stored in the "
			 << "directory this program is located. \n"
			 << "Exiting Program..." << endl;
		exit (EXIT_FAILURE);
	}
	else {
		while (getline(read, line))
			this->filetext += line + "\n";	
	}
}

Text::~Text() {
	cout << "Destructor for Text called." << endl;
}

void Text::contents() {
	cout << filename << " contents:\n" << filetext << endl;
}

int main() {
	string input;
	cout << "Enter the name of the file to read, including "
		 << "its extension. The file will be read and its contents" 
		 << " displayed here." << endl;
	cin >> input;
	Text* text = new Text(input);
	text->contents();
	delete text;
}