/* 
 Title: TMA2Question1.h
 Description: Header file for TMA2Question1.cpp
 Date: December 30, 2019
 Author: Braiden Little
 Version: 1.0
 Copyright: 2019 Braiden Little
*/

/*
	Variables:
		name(string): Name of the movie/dvd
		idnumber(int): ID# of the dvd
		rented(bool): True if the movie is rented to a customer, false otherwise.
		price(float): The price for renting the movie.
*/

/*
 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA2Question1 TMA2Question1.h
*/

#ifndef TMA2QUESTION_H
#define TMA2QUESTION_H
#include <string>
#include <iostream>

using namespace std;

class DVD {
	string name;
	int idnumber;
	bool rented;
	float price;
public:
	DVD();
	DVD(string name, int id, bool rented, float price);
	void rent();
	void turnin();
	void changeid(int newid);
	void changename(string newname);
	void setprice(float newprice);
	void print();
};
#endif // TMA2QUESTION_H ///:~