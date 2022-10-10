#include <iostream>
#include <string>
using namespace std;

class Rodent {
public:
	virtual ~Rodent() = 0;
	virtual void speak() = 0;
	virtual void eat() = 0;
	virtual void sleep() = 0;
};

inline Rodent::~Rodent() {}

class Mouse : public Rodent {
public:
	~Mouse() {};
	void speak() {cout << "Mouse::speak()" << endl;}
	void eat() {cout << "Mouse::eat()" << endl;}
	void sleep() {cout << "Mouse::sleep()" << endl;}
};

class Gerbil : public Rodent {
public:
	~Gerbil() {};
	void speak() {cout << "Gerbil::speak()" << endl;}
	void eat() {cout << "Gerbil::eat()" << endl;}
	void sleep() {cout << "Gerbil::sleep()" << endl;}
};

class Hamster : public Rodent {
public:
	~Hamster() {};
	void speak() {cout << "Hamster::speak()" << endl;}
	void eat() {cout << "Hamster::eat()" << endl;}
	void sleep() {cout << "Hamster::sleep()" << endl;}
};

int main() {
	Rodent* rodArray[] = {new Hamster(), new Hamster(), 
					new Hamster(), new Gerbil(),
					new Gerbil(), new Gerbil(),
					new Gerbil(), new Mouse(),
					new Mouse(), new Mouse()};
	for (int i = 0; i < sizeof(rodArray) / sizeof(rodArray[0]); i++) {
		rodArray[i]->speak();
		rodArray[i]->eat();
		rodArray[i]->sleep();
		cout << endl;
	}
	//Cleanup
	for (int i = 0; i < sizeof(rodArray) / sizeof(rodArray[0]); i++)
		delete rodArray[i];
}