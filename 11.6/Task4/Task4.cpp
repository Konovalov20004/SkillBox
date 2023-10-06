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
void count(string str, int& o, int& x, bool &good);
void error();
void check(string& str, int &x, int &o);

void enter() {
	string line{}, row{};
	bool goodChar = 1;
	int x{}, o{};
	for (int i = 0; i < 3 && goodChar; i++) {
		cin >> row;
		if (cin.fail() || cin.peek() != '\n' || row.length() != 3) {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
			i--;
		}
		else {
			line += row;
			count(row, o, x, goodChar);
			if (!goodChar) error();
			continue;
		}
	}
	(x >= o) ? check(line, x, o) : error();
}

void error() {
	cout << "Incorrect" << endl;
	exit(0);
}

void count(const string str, int& o, int& x, bool &good) {
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case 'x':
			x++;
			break;
		case 'o':
			o++;
			break;
		case '.':
			continue;
		default:
			good = false;
			error();
		}
	}
}

bool analyz(string &str, char &c) {
	bool winner = false;
	if (str[0] != '.' && str[0] == str[1] && str[1] == str[2]) {
		c = str[0];
		return winner = true;
	} else if (str[0] != '.' && str[0] == str[4] && str[4] == str[8]) {
		c = str[0];
		return winner = true;
	} else if (str[0] != '.' && str[0] == str[3] && str[3] == str[6]) {
		c = str[0];
		return winner = true;
	}
	if (str[1] != '.' && str[1] == str[4] && str[4] == str[7]){
		c = str[0];
		return winner = true;
	}
	if (str[2] != '.' && str[2] == str[4] && str[4] == str[6]) {
		c = str[2];
		return winner = true;
	} else if (str[2] != '.' && str[2] == str[5] && str[5] == str[8]) {
		c = str[2];
		return winner = true;
	}
	if (str[3] != '.' && str[3] == str[4] && str[4] == str[5]) {
		c = str[3];
		return winner = true;
	} else if (str[6] != '.' && str[6] == str[7] && str[7] == str[8]) {
		c = str[6];
		return winner = true;
	}
	return false;
}

void check(string& str, int &x, int &o) {
	char who{};
	if (analyz(str, who)) {
		if ((who == 'x' && x + 1 == o) || (who == 'o' && x == o)) {
			who == 'x' ? cout << "Petya won" << endl : cout << "Vasya won" << endl;
		}
		else {
			error();
		}
	}
	else {
		cout << "Nobody" << endl;
	}
}

int main() {
	enter();
}