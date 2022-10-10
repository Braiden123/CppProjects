//:Spaceship.cpp

#include <iostream>
using namespace std;

class Spaceship {
public:
	void fly() { cout << "Flying..." << endl;}
};

class Shuttle : public Spaceship {
public:
	void land() { cout << "Landing..." << endl;}
};

int main(int argc, char const *argv[])
{
	Shuttle sh;
	Spaceship* ss = &sh;
	sh.land();
	sh.fly();
	ss->fly();
	//ss->land() does not work. Does not have info about shuttle
	return 0;
}