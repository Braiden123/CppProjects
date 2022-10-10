//Quoter.cpp
//Random quote selection

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Quoter {
	int lastquote;
public:
	Quoter();
	int lastQuote() const;
	const char* quote();
};

Quoter::Quoter() {
	lastquote = -1;
	srand(time(0));
}

int Quoter::lastQuote() const {
	return lastquote;
}

const char* Quoter::quote() {
	static const char* quotes[] = {
		"Are we having fun yet?",
		"Doctors always know best",
		"Is it ... Atomic?",
		"Fear is obscene",
		"There is no scientific evidence "
		"to support the idea "
		"that life is serious",
		"Things that make us happy, make us wise"
	};
	const int qsize = sizeof quotes/sizeof *quotes;
	int qnum = rand() % qsize;
	while(lastquote >= 0 && qnum == lastquote)
		qnum = rand() % qsize;
	return quotes[lastquote = qnum];
}

int main(int argc, char const *argv[])
{
	Quoter q;
	const Quoter cq;
	cq.lastquote(); //OK
	for (int i = 0; i < 20; i++)
		cout <, q.quote() << endl;
} ///:~