//: TMA1Question1.cpp

/* 
 Title: TMA1Question1.cpp
 Description: Count number of whitespace-seperated words
 			  in a seperate file.
 Date: Nov. 1 2019
 Author: Braiden Little
 Student ID# 3364064
 Version: 1.0
 Copyright: 2019 Braiden Little
 Based on GetWords.cpp by Bruce Eckel, chapter 2.
*/

/*
DOCUMENTATION

Program Purpose:
	To open the Question1Read.txt file and count the
	number of whitespace seperated words in that file.

 Compile: (assuming mingw compiler and opened command prompt): 
 g++ -o TMA1Question1 TMA1Question1.cpp 
 Alternatively, use the included make file to compile all questions for TMA1.
 Make file execution(assuming mingw compiler): mingw32-make -f makefile.txt
 Execution: (in a Command Prompt window): TMA1Question1.exe (or just TMA1Question1)

 Classes: None

 Variables:
 	words (vector<string) = Vector to hold the words read from Question1Read.txt.
 	in (ifstream) = To read from Question1Read.txt.
 	word (string) = Used to hold the next word in the file and add it to the words variable.
*/

/*
TEST PLAN
	
	Normal Case 1: Open Question1Read.txt and display the number of
	white-space seperated words in the file. Should output 35 words.

	Expected Output: The number of whitespace-seperated words in Question1Read.txt is: 35

	Actual Output: As expected

Discussion: Assuming that Question1Read.txt is not altered, Normal Case 1 is 
			the only case for this program since it will not have any user input 
			and will only read one file.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	vector<string> words; 
	ifstream in("Question1Read.txt");
	string word;
	while (in >> word) //Read until we reach the end of the file.
		words.push_back(word); //Add the next word to words.
	cout << "The number of whitespace-seperated words in "
		 << "Question1Read.txt is: " << words.size() << endl;
}