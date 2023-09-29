#include <iostream>
#include <limits>
#include <numeric>
#include <string>

using namespace std;

void check(string &a, bool& b) {
	int point = 0;
	while (true) {
		cin >> a;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else { break; }
	}
	for (int i = 0; i < a.length(); i++) {
		if ((a[i] == '.' || a[i] == '-' || (a[i] >= '0' && a[i] <= '9')) 
			&& a[a.length() - 1] >= '0' && a[a.length() - 1] <= '9') {
			break;
		}
		else { b = false; }
	}
	for (int i = 0; i < a.length() && b; i++) {
		if ((a[i] < '-' && i > 0) || a[i] > '9' || (a[i] < '.' && i != 0) || a[i] == '/') {
			b = false;
			break;
		}
		if (a[i] == '.') { 
			point++;
		}
		else if (point > 1) {
			b = false;
			break;
		} 
	}
}

void main() {
	string value{};
	bool good = true;
	while (true) {
		good = true;
		check(value, good);
		cout << good << endl;
	}
}