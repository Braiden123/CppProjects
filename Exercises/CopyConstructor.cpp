//: CopyConstructor.cpp

#include <iostream> 
using namespace std;

class MyClass {
public:
	MyClass() {};
	MyClass(const MyClass& obj) {cout << "MyClass copy constructor." << endl;}
};

void foo1(MyClass m) {
	cout << "foo1(MyClass) call." << endl;
}

MyClass foo2() {
	cout << "foo2() call." << endl;
	static MyClass obj;
	return obj;
}

int main(int argc, char const *argv[])
{
	MyClass m;
	foo1(m);
	foo2();
	return 0;
}

