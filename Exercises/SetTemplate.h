//:Set.cpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class Set {
	vector<T> data;
public:
	Set() : data() {}
	size_t size() const { return data.size(); }
	bool insert(T datapiece);
	void erase(T datapiece);
	T find(const T& datapiece);
	void clear();
	class iterator;
	friend class iterator;
	class iterator {
		Set& s;
		int index;
	public:
		iterator(Set& is) : s(is), index (0) {}
		iterator(Set& is, bool) : s(is), index(s.size()) {}
		iterator(const iterator& copy) : s(copy.s), index(copy.index) {}
		int current() const {return s.data.at(index);}
		iterator operator++() { //Prefix
			return s.data.at(++index);
		}
		iterator operator++(int) {
			return s.data.at(index++);
		}
		iterator& operator+=(int amount) {
			index += amount;
			return *this;
		}
		//Check if at the end.
		bool operator==(const iterator& rv) const {
			return index == rv.index;
		}
		bool operator!=(const iterator& rv) const {
			return index != rv.index;
		}
		friend ostream&
		operator<<(ostream& os, const iterator& it) {
			return os << it.current();
		}
	};
	iterator begin() {return iterator(*this);}
	//Create the end sentinel
	iterator end() {return it(*this, true);}
	void erase(Set<T>::iterator posit) {data.erase(index);
};

template<class T>
T Set<T>::find(const T& datapiece) {
	for (size_t i = 0; i < data.size(); i++)
		if (datapiece == data.at(i))
			return data.at(i);
	cout << "Requested data not found." << endl;
	return NULL;
}

//Add the data and sort the vector.
template<class T>
T Set<T>::insert (T datapiece) {
	data.push_back(datapiece);
	sort(data.begin(), data.end());
	return datapiece;
}

//Clear all data in the Set.
template<class T>
void Set<T>::clear() {
	Set<T>::iterator it = this.begin();
	while (it != this.end()) {
		data.pop_back;
	}
}

template <class T>
void Set<T>::erase(T datapiece) {
	for (size_t i = 0; i < data.size(); i++)
		if (data.at(i) == datapiece)
			data.erase(data.begin + i);
}