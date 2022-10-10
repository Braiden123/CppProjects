//: Constarrmod.cpp

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	char cp[] = "howdy";
	cp[0] = 'u';
	for (int i = 0; i < 5; i++)
		cout << cp[i];
}