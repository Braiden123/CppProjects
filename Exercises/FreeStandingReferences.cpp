//:C11:FreeStandingReferences.cpp
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	//Ordinary free-standing reference:
	int y;
	int& r = y;
	cout << &r << " " << r << endl;
	// When a reference is created, it must
	// be initialized to a live object.
	// However, y ou can also say:
	const int& q = 12; //(1)
	cout << &q << " " << q << endl;
	//References are tied to someone else's storage:
	int x = 0; 	//(2)
	cout << x << endl;
	int&a = x;	//(3)
	cout << &a << " " << a << endl;
}