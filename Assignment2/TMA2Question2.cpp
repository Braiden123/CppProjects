/* 
 Title: TMA2Question2.cpp
 Description: Storage creation and address printing
 Date: Jan. 10 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
*/

/*
 DOCUMENTATION

 Program Purpose:
 	To create an integer variable, long variable, 
 	an array of 100 char's(letters a-z,A-Z), and 
 	an array of 100 floats(101-200) using new. 
 	Then print the addresses of each of these 
 	variables then free the storage from the 
 	heap using delete or delete[].

 Compile (assuming mingw compiler and opened command prompt): g++ -o TMA2Question2 TMA2Question2.cpp
 Execution (in a Command Prompt window): TMA2Question2.exe (or just TMA2Question2)

 Classes: None

 Variables:
	*x(int): new integer to hold the number 25
	*y(long): new long to hold the number 1234567890
	*characters(char[]): array of 100 to hold characters a-z, and A-Z
	*floats(float[]): array of 100 to hold sequential numbers starting with 101.
	alphabet(char[]): array of 52 to hold the letters a-z, and A-Z for random
					  choosing for the characters array.
*/

/*
 TEST PLAN
 	Normal case 1:

 		Expected output: (Address) will be different for each machine.
 						 Int @(Address) = 25
						 Long @(Address) = 1234567890
						 Char @(Address for index i) = char at index i
						 Continue until all chars and addresses are printed.
						 Float @(Adress for index i) = float at index i
						 Continue until all floats and addresses are printed.

		Actual output: As expected.

	Due to the static nature of this program Normal case 1 is the only test case.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[]) {
	int *x = new int(); 
	long *y = new long();
	*x = 25;
	*y = 1234567890;
	char *characters = new char[100];
	float *floats = new float[100];
	char alphabet[52] = {'a','b','c','d','e','f','g','h', //To fill char array
						 'i','j','k','l','m','n','o','p',
						 'q','r','s','t','u','v','w','x',
						 'y','z','A','B','C','D','E','F',
						 'G','H','I','J','K','L','M','N',
						 'O','P','Q','R','S','T','U','V',
						 'W','X','Y','Z'}; 
	srand((unsigned int)time(NULL));// To select random chars
	// Fill the characters array with random letters.
	for (int i = 0; i < 100; i++) {
		int random = rand() % 52;
		characters[i] = alphabet[random];
	}
	// Fill the floats array with floats from 101-200.
	for (int i = 0; i < 100; i++) 
		floats[i] = 101 + i;
	cout << "Int @" << &x << " = " << *x << endl;
	delete x;
	cout << "Long @" << &y << " = " << *y << endl;
	delete y;
	for (int i = 0; i < 100; i++) 
		cout << "Char @" << (void*)&characters[i] << " = " << characters[i] << endl;
	delete []characters;
	for (int i = 0; i < 100; i++)
		cout << "Float @" << &floats[i] << " = " << floats[i] << endl;
	delete []floats;
}