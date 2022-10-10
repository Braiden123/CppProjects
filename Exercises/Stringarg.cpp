//: Stringarg.cpp

#include <string>
#include <iostream>
using namespace std;

#define DEBUG(x) cout << #x " = " << x << endl

int main() {
	string input;
	cout << "Enter the string." << endl;
	cin >> input;
	int strsize = input.length();
	for (int i = 0; i < strsize; i++) {
		DEBUG(input);
		input.erase(input.end() - 1, input.end());
	}
}