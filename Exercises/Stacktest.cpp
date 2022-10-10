//: C04:StackTest.cpp
//{L} Stack
//{T} StackTest.cpp
// Test of nested linked list
#include "Stack.h"
#include "require.h"
#include <iostream>
#include <string>
using namespace std;

void
Stack::Link::initialize(void* dat, Link* nxt) {
	data = dat;
	next = nxt;
}

void Stack::initialize() {
	head = 0;
}

void Stack::push(void* dat) {
	Link* newLink = new Link;
	newLink->initialize(dat, head);
	head = newLink;
}

void* Stack::peek() {
	require(head !=0, "Stack empty:");
	return head->data;
}

void* Stack::pop() {
	if (head ==0)
		return 0;
	void* result = head->data;
	Link* oldHead = head;
	head = head->next;
	delete oldHead;
	return result;
}

void Stack::cleanup() {
	require(head == 0, "Stack not empty");
}

int main(int argc, char const *argv[])
{
	Stack numbers;
	numbers.initialize();
	double x = 1;
	for (int i = 0; i <= 25; i++) {
		numbers.push(new double(x));
		x++;
	}		
	for (int i = 0; i <= 25; i++) {
		double y = *(double*)numbers.pop();
		cout << y << endl;
	}
}