#include <iostream>
using namespace std;

void increment(int*& i) { i++;}

int main(int argc, char const *argv[]) {
	int* i;
	*i = 47;
	cout << "i = " << i << endl;

    increment(i);
    cout << "i = " << i << endl;
}