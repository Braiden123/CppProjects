//: Simple.cpp

#include "Simple.h"
#include <iostream>

using namespace std;

Simple::Simple(int x) {
	cout << "Constructor has been called." << endl;
}

Simple::~Simple() {
	cout << "Destructor has been called." << endl;
}

int main(int argc, char const *argv[]) {
	{
		Simple object;
	}
}