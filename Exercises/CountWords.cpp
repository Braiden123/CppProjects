//: CO2:CountWords.cpp
// Break a file into whitespace-seperated words
// sample the sample is the sample
// Then output the number of whitepspaces.
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
static libgcc
static libstdc++

int main() {
	vector<string> words;
	ifstream in("CountWords.cpp");
	string word;
	int samplecount = 0;
	while (in >> word)
		words.push_back(word);
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == "sample") {
			cout << "Test2";
			samplecount++;
		}
	}
	cout << "The number of times the word sample appears is "
		 << samplecount << ". ";

}