#include <iostream>
#include <string>
#include "HenNestEgg.h"

using namespace std;

Hen::Hen() {
	cout << "Hen constructor called." << endl;
}

Hen::~Hen() {
	cout << "Hen destructor called." << endl;
}
void Hen::display() {
	cout << "Hen" << endl;
}

Hen::Nest::Nest() {
	cout << "Nest constructor called." << endl;
}

Hen::Nest::~Nest() {
	cout << "Nest destructor called." << endl;
}

void Hen::Nest::display() {
	cout << "Nest" << endl;
}

Hen::Nest::Egg::Egg() {
	cout << "Egg constructor called." << endl;
}

Hen::Nest::Egg::~Egg() {
	cout << "Egg destructor called." << endl;
}

void Hen::Nest::Egg::display() {
	cout << "Egg" << endl;
}

int main() {
	Hen* hen = new Hen();
	Hen::Nest* nest = new Hen::Nest();
	Hen::Nest::Egg* egg = new Hen::Nest::Egg();
	hen->display();
	nest->display();
	egg->display();
	delete hen;
	delete nest;
	delete egg;
}