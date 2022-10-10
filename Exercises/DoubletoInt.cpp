// DoubletoInt.cpp
// Takes a valid double value from the user
// and converts to an integer value as output.

#include <iostream>

using namespace std;

int Doubletoint(double num) {
	int x = (int)num;
	return x;
}

int main() {
	double x;
	int (*y)(double) = Doubletoint;
	cout << "Please enter a number with no decimals "
		 << "and the program will return it as an integer output:";
	cin >> x;
	cout << "The number is: " << (*y)(x);;
}