/* 
 Title: TMA4Question3.h
 Description: Header file for TMA4Question3.cpp
 Date: Feb. 26 2020
 Author: Braiden Little
 Version: 1.0
 Copyright: 2020 Braiden Little
 Based on TPStash2.h and TStack2.h by Bruce Eckel, Chapter 16
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class Set {
	vector<T> data;
	int index;
public:
	Set() : data() {};
	~Set() {data.clear();}
	bool find(const T& finddata);
	bool insert(T newdata);
	void clear() {data.clear();}
	class iterator;
	friend class iterator;
	class iterator {
		Set& s;
		int index;
	public:
		iterator(Set& se) : s(se), index(0){}
		iterator(Set& se, bool) : s(se), index(s.data.size()) {}
		T operator*() const {return s.data.at(index);}
		T operator++() {return s.data.at(++index);} //Prefix
		T operator++(int) {return s.data.at(index++);} //Postfix
		T operator--() {return s.data.at(--index);}//Prefix
		T operator--(int) {return s.data.at(index--);}//Postfix
		iterator& operator+=(int amount) {
			if (index + amount >= data.size()) {
				cout << "Set::iterator::operator+=() "
					 << "tried to move out of bounds." << endl;
				return NULL;
			}
			index += amount;
			return *this;
		}
		iterator& operator-=(int amount) {
			if (index - amount < 0) {
				cout << "Set::iterator::operator+=() "
					 << "tried to move out of bounds." << endl;
			}
			index -= amount;
			return *this;
		}
		bool operator==(const iterator& rv) const {
			return index == rv.index;
		}
		bool operator!=(const iterator& rv) const {
			return index != rv.index;
		}
		friend ostream& operator<<(ostream os, const iterator& it) {
			return os << *it;
		}
		int getindex() {return index;}
	};
	void erase(Set<T>::iterator position);
	iterator begin() {return iterator(*this);}
	iterator end() {return iterator(*this, true);}
};

template<class T>
bool Set<T>::find(const T& finddata) {
	for (int i = 0; i < data.size(); i++)
		if (finddata == data.at(i))
			return true;
	return false;
}

template<class T>
bool Set<T>::insert(T newdata) {
	if (!find(newdata)) {
		cout << "Adding: " << newdata << endl;
		data.push_back(newdata);
		sort(data.begin(), data.end());
		return true;
	}
	cout << "Data already exists in this set." << endl;
	return false;
}

template<class T>
void Set<T>::erase(Set<T>::iterator position) {
	if (position.getindex() < 0 || position.getindex() >= data.size()){
		cout << "Iterator out of bounds." << endl;
		return;
	}
	for (int i = 0; i < data.size(); i++)
		if (data.at(i) == *position) {
			cout << "Deleting: " << data.at(i) << endl;
			data.erase(data.begin() + i);
		}
}