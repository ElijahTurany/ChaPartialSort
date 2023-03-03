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
	PartiallySortedList() { //O(1)
		data = new PartiallySortedString[capacity]; //1
	}

	void add(string value) { //O(N)
		PartiallySortedString temp;

		if (size == capacity) { //1
			this->expand();
		}

		data[size] = PartiallySortedString(value); //6N
		for (int i = size; i > 0; i--) { //N
			if ((data[i-1] > data[i]) || (data[i-1] |= data[i])) { //2
				temp = data[i-1]; //1
				data[i-1] = data[i]; //1
				data[i] = temp; //1
			}
			if ((data[i-1] == data[i])) { //1
				break;
			}
			
		}
		size++;
	}

	PartiallySortedString get(int index) { //O(1)
		if ((index < size) && (index >= 0)) { //1
			return data[index];
		}
		throw "Out of bounds";
	}

	int getSize() { //O(1)
		return size;
	}

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

	int countPermutations() { //O(N)
		int perms = 0;

		for (int i = 0; i < size; i++) { //2N
			if (!(data[i]==data[i+1]) || (data[i]|=data[i+1])) { //2
				perms++;
			}
		}
		return perms;
	}

	void printList() { //O(N)
		cout << countPermutations() << "   [";
		for (int i = 0; i < size; i++) {//N
			cout << data[i].getVal() << ",";//1
		}
		cout << "]" << endl;
	}
};

int main() {
	PartiallySortedList list;
	// PartiallySortedString s1{"a"};
	// PartiallySortedString s2{"b"};
	// PartiallySortedString s3{"a"};

	// cout << (s1==s2);
	// cout << (s1==s3);
	// cout << (s1|=s2);
	// cout << (s1|=s3);

	list.printList();

	list.add("333");
	list.printList();

	list.add("22");
	list.printList();

	list.add("1");
	list.printList();

	list.add("bb");
	list.printList();

	list.add("22");
	list.printList();

	list.add("bb");
	list.printList();

	list.add("22");
	list.printList();

	list.add("bb");
	list.printList();

	list.add("22");
	list.printList();

	list.add("1");
	list.printList();

	list.add("a");
	list.printList();

	list.add("!");
	list.printList();

	list.add("@@");
	list.printList();

	list.add("###");
	list.printList();

	list.add("1");
	list.printList();
}