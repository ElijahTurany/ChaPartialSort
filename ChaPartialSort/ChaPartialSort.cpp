#include <iostream>
#include <string>
#include "PartiallySortedList.h"
using namespace std;

class PartiallySortedString {
private:
	string s;
public:
	PartiallySortedString(string value) {
		s = value;
	}

	PartiallySortedString() {
		s = "";
	}

	bool operator==(const PartiallySortedString& other) {
		return (other.s == s);
	}

	bool operator|=(const PartiallySortedString& other) {
		return (s.length() == other.s.length());
	}

	bool operator<(const PartiallySortedString& other) {
		return (s.length() < other.s.length());
	}

	bool operator>(const PartiallySortedString& other) {
		return (s.length() > other.s.length());
	}

	string getVal() {
		return s;
	}
};

class PartiallySortedList {
private:
	PartiallySortedString* data;
	int size{ 0 };
	int capacity{ 10 };
public:
	PartiallySortedList() {
		data = new PartiallySortedString[capacity];
	}

	void add( string value) {
		if (size == capacity) {
			this->expand();
		}	
		data[size++] = PartiallySortedString(value);
	}

	PartiallySortedString get(int index) {
		if ((index < size) && (index >= 0)) {
			return data[index];
		}
		throw "Out of bounds";
	}

	int getSize() {
		return size;
	}

	void expand() {
		PartiallySortedString* tmp = new PartiallySortedString[capacity * 2];
		for (int i = 0; i < capacity; i++) {
			tmp[i] = data[i];
		}
		delete[] data;
		data = tmp;
		tmp = nullptr;
		capacity *= 2;
	}

	int countPermutations() {

	}
};

int main() {
	PartiallySortedList list;

	list.add("k");
	list.add("j");
	list.add("i");
	list.add("h");
	list.add("g");
	list.add("f");
	list.add("e");
	list.add("d");
	list.add("c");
	list.add("b");
	list.add("a");

	cout << list.get(10).getVal();
}