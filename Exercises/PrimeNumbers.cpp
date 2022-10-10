//PrimeNumbers.cpp
//Uses two for loops to find all
//prime numbers and prints the results.
#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 100; i++) {
		int x = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)
				x++;
		}
		if (x == 2)
			cout << i << " is a prime number.\n";
	}
}