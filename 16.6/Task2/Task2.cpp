#include <iostream>
#include <string>

using namespace std;

string enter() {
	string value;
	while (true){
		cin >> value;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else { return value; }
	}
}

int main() {
	string result;
	cout << "Enter the whole part and the fractional part" << endl;
	for (int i = 0; i < 2; i++) {
		if (i > 0) { result += '.'; }
		result += enter();
	}
	double out = stof(result);
	cout << out << endl;
	return 0;
}