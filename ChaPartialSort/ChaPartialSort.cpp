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

	bool operator==(const PartiallySortedString& other) {
		return (other.s == s);
	}

	bool operator!=(const PartiallySortedString& other) {
		return (s.length() == other.s.length());
	}

	bool operator<(const PartiallySortedString& other) {
		return (s.length() < other.s.length());
	}

	bool operator>(const PartiallySortedString& other) {
		return (s.length() > other.s.length());
	}
};

int main() {
	PartiallySortedString s1("abd");
	PartiallySortedString s2("abc");

    cout << (s1 != s2);
	cout << (s1 == s2);
}