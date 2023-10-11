#include <iostream>
#include <string>

using namespace std;

void enter(string& a) {
	while (true) {
		cin >> a;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else {
			break;
		}
	}
}

void enter(int& a) {
	while (true) {
		cin >> a;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else {
			if (a > 10 || a < 0) {
				cout << "Number not found" << endl;
			}
			else {
				break;
			}
		}
	}
}

int main() {
	const int SIZE{ 10 };
	string name[SIZE]{};
	int number{};
	for (int i = 0; i < SIZE; i++) {
		enter(name[i]);
	}
	for (int i = 0; i < 3; i++) {
		enter(number);
		cout << name[number - 1] << endl;
	}
}