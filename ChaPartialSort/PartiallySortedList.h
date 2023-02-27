#pragma once
#include <iostream>

template <typename Type>
class PartiallySortedList {
private:
	Type* data;
	int size{ 0 };
	int capacity{ 10 };
public:
	PartiallySortedList() { //O(1)
		data = new Type[capacity];
	}

	void add(Type value) {
		if (size == capacity) {
			this->expand();
		}	
		data[size++] = value;
	}

	Type get(int index) { //O(1)
		if ((index < size) && (index >= 0)) {
			return data[index];
		}
		throw "Out of bounds";
	}

	int getSize() { //O(1)
		return size;
	}

	void expand() { //O(N)
		Type* tmp = new Type[capacity * 2];
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