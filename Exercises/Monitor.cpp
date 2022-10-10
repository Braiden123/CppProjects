#include <iostream>
using namespace std;

class Monitor {
	static int inccount;
	Monitor(const &Monitor);
public:
	Monitor() {};
	void incident() {inccount++;}
	void print() {cout << "Incidents: " << inccount << endl;}
};

int Monitor::inccount = 0;

void globalFunc() {
	static Monitor mon;
	mon.incident();
	mon.print();
}

int main() {
	for (int i = 0; i < 10; i++)
		globalFunc();
}