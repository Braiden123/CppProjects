//:Constpoint.cpp

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int d = 1;
	int e = 5;
	const int* const x = &d;
	cout << *x << endl;
	*x = 2;
	x = 5;
	cout *x << " " << x << endl;
}