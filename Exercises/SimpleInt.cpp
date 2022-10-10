#include <iostream>
#include "SimpleInt.h"

using namespace std;


int main() {

    SimpleInt a(3), b(2), c(4);

    SimpleInt d = a + b - c;

    d.print(cout);

return 0;
}