#include <iostream>
#include <string>
using namespace std;

class PartiallySortedString {
private:
	string s;
public:
	PartiallySortedString(string value) { //O(1)
		s = value;
	}

	PartiallySortedString() { //O(1)
		s = "";
	}

	bool operator==(const PartiallySortedString& other) { //O(1)
		return (other.s == s);
	}

	bool operator|=(const PartiallySortedString& other) { //O(1)
		//Evaluates true if strings are the same length and not equal, evaluates false otherwise
		return ((s.length() == other.s.length()) && (other.s != s));
	}

	bool operator<(const PartiallySortedString& other) { //O(1)
		return (s.length() < other.s.length());
	}

	bool operator>(const PartiallySortedString& other) { //O(1)
		return (s.length() > other.s.length());
	}

	string getVal() { //O(1)
		return s;
	}
};

class PartiallySortedList {
private:
	PartiallySortedString* data;
	int size{ 0 };
	int capacity{ 10 };
public:
	//Creates an empty array of PartiallySortedStrings of size capacity
	PartiallySortedList() { //O(1)
		data = new PartiallySortedString[capacity]; //1
	}

	void add(string value) { //O(N)
		PartiallySortedString temp;

		//Expands the list if more space is needed
		if (size == capacity) { //1
			this->expand();
		}

		//Appends the given value to the end of the list
		data[size] = PartiallySortedString(value); //6N
		//Starting at the back of the list, this loop sorts the recently appended element into its corrent place using insertion sort
		for (int i = size; i > 0; i--) { //N
			//This if statement evaluates to true if the left element is bigger than the right, or if the 
			//two elements are the same length but not equal
			if ((data[i-1] > data[i]) || (data[i-1] |= data[i])) { //2
				temp = data[i-1]; //1
				data[i-1] = data[i]; //1
				data[i] = temp; //1
			}
			//This else if statement evaulates true if the two elements being compared are equal, and breaks the loop
			else if ((data[i-1] == data[i])) { //1
				break;
			}
			//As a result of this if-elseif block, new elements are pushed back into the list until they reach an element
			//smaller than themselves, or until they hit an element they're equal to.
			//This means that new elements of a given length (and with a unique string) will appear before older elements
			//of the same length. This is done to ensure that equal strings are clumped together.	
		}
		size++;
	}

	PartiallySortedString get(int index) { //O(1)
		//Returns the PartiallySortedString at the given index, and throws an exception if the index is out of bounds
		if ((index < size) && (index >= 0)) { //1
			return data[index];
		}
		throw "Out of bounds";
	}

	//Returns size
	int getSize() { //O(1)
		return size;
	}

	//This is the code used in the CustomArrayList we made in class, it copies the data array to a new array double
	//the size and deletes the smaller array
	void expand() { //O(N)
		PartiallySortedString* tmp = new PartiallySortedString[capacity * 2];
		for (int i = 0; i < capacity; i++) { //N
			tmp[i] = data[i]; //1
		}
		delete[] data;
		data = tmp; //1
		tmp = nullptr; //1
		capacity *= 2; //1
	}

	//This method starts at the begining of the list and compares adjacent elements, and increases the number of 
	//permutations if they are different. Because the add method insures indentical strings are always next to each
	//other, this is relatively simple 
	int countPermutations() { //O(N)
		int perms = 0;

		for (int i = 0; i < size; i++) { //2N
			if (!(data[i]==data[i+1]) || (data[i]|=data[i+1])) { //2
				perms++;
			}
		}
		return perms;
	}

	//Prints the number of permutations in the list and a formatted representation of the list
	//Used during debugging
	void printList() { //O(N)
		cout << "   Permutations: " <<  countPermutations() << "   [";
		for (int i = 0; i < size; i++) {//N
			cout << data[i].getVal() << ",";//1
		}
		cout << "]" << endl;
	}
};

void runTests() {
	PartiallySortedList list1;
	list1.add("1");
	list1.add("2");
	list1.add("3");
	if (list1.getSize() != 3) {
		cout << "Size is incorrect" << endl;
	}

	PartiallySortedList list2;
	list2.add("a");
	list2.add("bb");
	list2.add("ccc");
	if ((list2.get(0).getVal() != "a") || (list2.get(1).getVal() != "bb") || (list2.get(2).getVal() != "ccc")) {
		cout << "Added string is incorrect" << endl;
	}

	PartiallySortedList list3;
	list3.add("*******");
	list3.add("1");
	list3.add("#####");
	if ((list3.get(0).getVal() != "1") || (list3.get(1).getVal() != "#####") || (list3.get(2).getVal() != "*******")) {
		cout << "List is not sorted" << endl;
	}

	PartiallySortedList list4;
	list4.add("1");
	list4.add("2");
	list4.add("3");
	list4.add("4");
	list4.add("5");
	list4.add("6");
	if (list4.countPermutations() != 6) {
		cout << "Number of permuations is wrong" << endl;
	}

	PartiallySortedList list5;
	list5.add("333");
	list5.add("22");
	list5.add("1");
	list5.add("bb");
	list5.add("22");
	list5.add("bb");
	list5.add("22");
	list5.add("bb");
	list5.add("22");
	list5.add("1");
	list5.add("a");
	list5.add("!");
	list5.add("@@");
	list5.add("###");
	list5.add("1");
	list5.add("ccc");
	cout << "Expected Output:" << endl << "   Permutations: 9   [!,a,1,1,1,@@,bb,bb,bb,22,22,22,22,ccc,###,333,]" << endl;
	cout << "Actual Output:" << endl;
	list5.printList();
}

int main() {
	runTests();
}