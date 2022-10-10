//: CO3:Menu.cpp
// Simple menu program demonstrating 
// the use of "break" and "continue"
#include <iostream>
using namespace std;

int main() {
	char c; //To hold response
	while (true) {
		cout << "MAIN MENU:" << endl;
		cout << "l: left, r: right, q: quit -> ";
		cin >> c;
		if (c == 'q')
			break;
		switch(c) {
			case 'l' : cout << "LEFT MENU:" << endl;
					   cout << "select a or b: ";
					   cin >> c;
					   switch(c) {
						   case 'a' : cout << "you chose 'a'" << endl;
							   		  continue; //Back to main menu
						   case 'b' : cout << "you chose 'b'" << endl;
							   		  continue; //Back to main menu
						   default : cout << "you didn't choose a or b!"
								   		  << endl;
							   	 	 continue;
				}
			case 'r' : cout << "RIGHT MENU:" << endl;
					   cout << "select c or d: ";
					   cin >> c;
					   switch(c) {
					   	case 'c' : cout << "you chose 'c'" << endl;
					   			   continue;
					   	case 'd' : cout << "you chose 'd'" << endl;
					   			   continue;
					   	default : cout << "you didn't choose c or d!"
					   				   << endl;
					   			  continue; 
					   }
			default : cout << "you must type l or r or q!" << endl;
		}
	}
	cout << "quitting menu..." << endl;
}