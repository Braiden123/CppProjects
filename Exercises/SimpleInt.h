#include <iostream>
using namespace std;

class SimpleInt {
public:
    SimpleInt() : i(0) {}
    SimpleInt(int iii) : i(iii) {}

    const SimpleInt operator+(const SimpleInt& right) const { return SimpleInt(i + right.i); }
    const SimpleInt operator-(const SimpleInt& right) const { return SimpleInt(i - right.i); }

    void print(ostream& out) { out << i << endl; }
private:
    int i;
};