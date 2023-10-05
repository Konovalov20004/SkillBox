#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <cmath>
#include <numeric>
#include <limits>
#include <type_traits>

using namespace std;
using namespace std::literals;

string check() {
	string str{};
	bool punkt = NULL;
	while (true) {
		getline(cin, str, '\n');
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else { break; }
	}
	if (str[0] == '.' || str[str.length() - 1] == '.') {
		cout << "No" << endl;
		exit(0);
	}
	for (int i = 0; i < str.length() - 1; i++) {
		if (str[i] == '.' && str[i + 1] == '.') {
			cout << "No" << endl;
			exit(0);
		}
	} if (str.length() > 128 || str.length() < 3) {
		cout << "No" << endl;
		exit(0);
	}
	return str;
}

bool checkA(string a) {
	string dictionary{ " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghihklmnopqrstuvwxyz0123456789-." };
	bool check;
	for (int i = 0; i < a.length(); i++) {
		if (dictionary.find(a[i], 1) < dictionary.length() && a.length() <= 63) {
			check = true;
		}
		else {
			check = false;
			cout << "No" << endl;
			exit(0);
		}
	}
	return check;
}

bool checkB(string a) {
	bool check;
	string dictionary{ " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghihklmnopqrstuvwxyz0123456789-.!#$%&'*+-/=?^_`{|}~" };
	for (int i = 0; i < a.length(); i++) {
		if (dictionary.find(a[i], 1) < dictionary.length() && a.length() <= 64) {
			check = true;
		} else {
			check = false;
			cout << "No" << endl;
			exit(0);
		}
	}
	return check;
}

void separation(string str, string& before, string& after) {
	int key = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '@')
		{
			key += i; break;
		}
	}
	if (key <= 0) {
		cout << "No" << endl;
		exit(0);
	}
	before = str.substr(0, key);
	after = str.substr(key + 1, str.length() - key);
}

void good() {
	string email{}, after{}, before{};
	email = check();
	separation(email, before, after);
	if (checkA(after) && checkB(before)) {
		cout << "Yes" << endl;
	}
}

int main()
{
	good();
}
