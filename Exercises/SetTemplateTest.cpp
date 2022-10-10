#include <iostream>
#include <vector>
#include <set>
#include "SetTemplate.h"
using namespace std;
int main() {
	Set<int> a;
	a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(4);
    a.insert(3);
    a.insert(2);
    a.insert(6);
}