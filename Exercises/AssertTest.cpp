#include <iostream>
#include <cassert>
#define DEBUG

using namespace std;

int main() {
	#ifdef DEBUG
	bool truth = true;
	assert(truth != true);
	#endif
}
