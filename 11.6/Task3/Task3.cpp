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
bool good(string a);

string check() {
	string str{}, dictionary{ ".0123456789" };
	while (true) {
		getline(cin, str);
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else {
			break;
		}
	}
	if (str.length() > 15 || str.length() < 7 || str[0] == '.' || str[str.length() - 1] == '.') {
		cout << "invalid" << endl;
		exit(0);
	}
	for (int i = 0; i < str.length() - 1; i++) {
		if (((str[i] == '.' && str[i + 1] == '.') || (str[i] == '0' && str[i + 1] == '0')) || !(iswdigit(str[i]) || str[i] == '.')) {
			cout << "invalid" << endl;
			exit(0);
		}
	} return str;
}

void split(string a) {
	string octed{};
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '.') { 
			if (!(good(octed))) {
				cout << "invalid" << endl;
				exit(0);
			}
			octed.clear();
			continue;
		}
		else {
			octed += a[i];
		}
	}
	cout << "Valid" << endl;
}

bool good(string a) {
	if ((a[0] == '0' && a.length() > 1) || a.length() > 3) {
		return 0;
	} 
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= '3' && i == 0 && a.length() == 3) {
			return 0;
		}
		else if (a.length() == 3 && (a[0] == '2' || a[1] == '5') && a.back() > '5') {
			return 0;
		}
		else {
			return 1;
		}
	}
}


int main() {
	split(check());
}