#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void check(string &s) {
	while (true) {
		getline(cin, s, '\n');
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else { 
			break;
		}
	}
}

void encrypt_caesar(string &str, int &s) {
	char beg{}, end{};

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			continue;
		}
		isupper(str[i]) ? beg = 64, end = 'Z' : beg = 96, end = 'z';
		if (str[i] + s > end) {
			str[i] = beg + (((str[i] + s) - beg) % 26);
			continue;
		}
		else if (str[i] + s <= beg) {
			str[i] = end - abs((str[i] - beg) + s);
			continue;
		}
		else {
			str[i] += s;
		}
	}
}

void decrypt_caesar(string &str, int &s) {
	s *= -1;
	encrypt_caesar(str, s);
}

void main() {
	string str{};
	check(str);
	int shift = -1;
	encrypt_caesar(str, shift);
	cout << str << endl;
	decrypt_caesar(str, shift);
	cout << str << endl;
}