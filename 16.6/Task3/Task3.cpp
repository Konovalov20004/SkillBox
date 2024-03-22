#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

string enter() {
	string str;
	while (true) {
		cin >> str;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else { return str; }
	}
}

double separation(string str) {
	double a, b;
	string::iterator count;
	char tmp;
	for (string::iterator itr = str.begin(); itr != str.end(); itr++) {
 		if (*itr == '*' || *itr == '-'|| *itr == '+'|| *itr == '/') {
			tmp = *itr;
			count = ++itr;
		}
	}
	a = stof(str);
	str.erase(str.begin(), count);
	b = stof(str);
	switch (tmp) {
	case '+':
		a += b;
		return a;
	case '-':
		a -= b;
		return a;
	case '*':
		a *= b;
		return a;
	case '/':
		a /= b;
		return a;
	}
}

int main() {	
	string buffer{};
	buffer = enter();
	cout << separation(buffer) << endl;

	return 0;
} 