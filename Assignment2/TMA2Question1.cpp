/* 
 Title: TMA2Question1.cpp
 Description: DVD rental store program.
 Date: December 30, 2019
 Author: Braiden Little
 Version: 1.0
 Copyright: 2019 Braiden Little
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	To manage DVD rental in a video rental store. 
	The DVDs contain private variables to contain
	name, ID#, rental status, and price. The class
	also contains public functions to modify each
	of the private variables as well as a print()
	function print out all information about 
	the dvd to the user. All variables and 
	functions are defined in the 
	TMA2Question1.h file.

	The program will read from the TMA2Question1Read.txt
	file and use the information to create 10 DVD 
	instances stored in an array. The program will then
	print all information regarding each DVD in the array.
	Afterwards, the dvd functions will be called for 
	various dvds in the array to test functionality
	and print() will be called again. 

 Compile: (assuming mingw compiler and opened command prompt): g++ -o TMA2Question1 TMA2Question1.cpp
 Execution: (in a Command Prompt window): TMA2Question1.exe (or just TMA2Question1)

 Classes: DVD

 Variables:
		name(string): Name of the movie/dvd
		idnumber(int): ID# of the dvd
		rented(bool): True if the movie is rented to a customer, false otherwise.
		price(float): The price for renting the movie.
		linecount(int): To track the line being read
		dvdcount(int): To track the index the new dvd is being added to.
*/

/*
 TEST PLAN

	Normal case 1: TMA1Question1Read.txt file is open and read properly.
	 
	 Expected output: All dvds and their information listed as they appear in TMA2Question.
					  
					  The DVD is already in the store.
					  This DVD is now rented out to a customer.
					  This DVD is already rented out to a customer.
					  The DVD has now been returned to the store.

					  Print all dvds with their information again which will now have
					  the following changes:

					  Original:							New:

					  Movie: Avengers: Endgame			Movie: Avengers
					  ID#: 123456						ID#: 123456
					  Rental status: Rented 			Rental status: Rented
					  Price: $3.99 						Price: $3.99

					  Movie: The Lion King				Movie: The Lion King
					  ID#: 456879						ID#: 456879	
					  Rental status: Rented 			Rental status: Not Rented
					  Price: $3.99						Price: $3.99

					  Movie: Spider-Man: Far From Home	Movie: Spider-Man: Far From Home
					  ID#: 784518						ID#: 784518	
					  Rental status: Rented 			Rental status: Rented
					  Price: $3.99 						Price: $4.99

					  Movie: Joker						Movie: Joker
					  ID#: 458523						ID#: 998966
					  Rental status: Rented 			Rental status: Rented
					  Price: $3.99 						Price: $3.99

	 Actual Output: As expected.

	Failing Case 1: TMA1Question1Read.txt is not found and cannot be read.

	 Expected Output: Data file 'TMA2Question1Read.txt' could not be found.
					  Exiting Program...

	 Actual Output: As expected.
*/

#include "TMA2Question1.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

DVD::DVD(){}//default constructor

DVD::DVD(string name, int id, bool rented, float price) {
	this->name = name;
	this->idnumber = id;
	this->rented = rented;
	this->price = price;
}

/*
Will set the DVD's rental status to true if 
the DVD has not been rented out. If the DVD
is already rented, a message will output
informing the user that the DVD is already 
rented and exit the function.
*/
void DVD::rent() {
	if (rented == true) {
		cout << "This DVD is already rented "
		<< "out to a customer." << endl;
	}
	else {
		rented = true;
		cout << "This DVD is now rented "
		<< "out to a customer." << endl;
	}
}

/*
Will set the DVD's rental status to false if
the DVD is currently rented out. If the DVD
is still in the store, a message will output
informing the user that the DVD is still in
the store and exit the function.
*/
void DVD::turnin() {
	if (rented == true) {
		rented = false;
		cout << "The DVD has now been "
		<< "returned to the store." << endl;
	}
	else {
		cout << "The DVD is already "
		<< "in the store." << endl;
	}
}

void DVD::changeid(int newid) {
	this->idnumber = newid;
}

void DVD::changename(string newname) {
	this->name = newname;
}

void DVD::setprice(float newprice) {
	this->price = newprice;
}

void DVD::print() {
	cout << "Movie: " << this->name << endl;
	cout << "ID#: " << this->idnumber << endl;
	if (rented == true) 
		cout << "Rental status: Rented " << endl;
	else
		cout << "Rental status: Not Rented" << endl;
	cout << "Price: $" << this->price << endl;
}

int main() {
	DVD *dvds = new DVD[10];
	ifstream in("TMA2Question1Read.txt");
	if (!in.is_open()) {
	cout << "Data file 'TMA2Question1Read.txt' "
		 << "could not be found.\n"
		 << "Exiting Program..." << endl;
		 exit (EXIT_FAILURE);
	}
	string line;
	string lines[40]; //stores lines from file
	int j = 0; //counter for array
	while (getline(in, line))
		lines[j++] = line;
	int linecount = 0; //used to track line in file
	int dvdcount = 0; //counter for DVD array
	string name; //movie name
	int id;
	bool rented;
	float price;
	stringstream ss; /*stringstream to convert from 
					   a string to an int or float*/
	for (int i = 0; i < sizeof(lines) / sizeof(lines[0]); i++) {	
		if (linecount > 3) //New movie being entered.
			linecount = 0;
		if (linecount == 0) //Name being read
			name = lines[i];
		else if(linecount == 1) {//ID# being read
			ss << lines[i];
			if (!(ss >> id)){ //String did not convert to int
				cout << "Error converting to integer...\n"
				     << "Exiting Program..." << endl;
				exit (EXIT_FAILURE);
			}
			std::stringstream().swap(ss); //Clear the Stringstream
		}
		else if(linecount == 2) {//Rental status being read
			if (lines[i] == "Rented")
				rented = true;
			else 
				rented = false;
		}
		else if(linecount == 3) { //Price being read
			ss << lines[i];
			if (!(ss >> price)){ //String did not convert to float
				cout << "Error converting to float...\n"
				     << "Exiting Program..." << endl;
				exit (EXIT_FAILURE);
			}
			std::stringstream().swap(ss); //Clear the Stringstream
			dvds[dvdcount] = DVD(name, id, rented, price);
			dvdcount++; //New dvd being added
		}
		linecount++;
	}
	for (int i = 0; i < 10; i++){
		cout << endl;
		dvds[i].print();
	}
	//To test the other functions of the DVD class.
	cout << "\n";
	dvds[4].turnin();
	dvds[4].rent();
	dvds[1].rent();
	dvds[1].turnin();
	dvds[8].changeid(998966);
	dvds[0].changename("Avengers");
	dvds[5].setprice(4.99);
	for (int i = 0; i < 10; i++){
		cout << endl;
		dvds[i].print();
	}
}