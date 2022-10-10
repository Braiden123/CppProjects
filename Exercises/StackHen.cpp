//: StackHen.cpp
#include "Stack.h"
#include "require.h"
#include "HenNestEgg.h"
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

void Hen::display() {
	cout << "Hen" << endl;
}

string Hen::print() {
	return name;
}

void Hen::Nest::display() {
	cout << "Nest" << endl;
}

void Hen::Nest::Egg::display() {
	cout << "Egg" << endl;
}

int main(int argc, char const *argv[])
{
	Stack hens;
	hens.initialize();
	for (int i = 0; i < 20; i++) 
		hens.push(new Hen());
	cout << hens.pop() << endl;
	return 0;
}