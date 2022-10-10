/* 
 Title: TMA2Question4.h
 Description: Header file for TMA2Question4.cpp
 Date: Jan. 14 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
*/

/*
 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA2Question4 TMA2Question4.h
*/

#ifndef TMA2QUESTION4_H
#define TMA2QUESTION4_H

#include <string>
using namespace std;

class Text {
	string filetext;
	string filename;
public:
	Text();
	Text(string filename);
	~Text();
	void contents();
};

#endif //TMA2QUESTION4_H ///:~