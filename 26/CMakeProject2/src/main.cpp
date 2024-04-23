#include "CMakeProject2.h"
#include "CMakeProject2.cpp"

using namespace std;

string check() {
	string tmp;
	while (true) {
		cin >> tmp;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			continue;
		}
		return tmp;
	}
}

int main()
{
	cout << (char)255 << endl;
	Phone phone;
	string command;
	while (true) {
		cout << "Enter command" << endl;
		command = check();
		if (command == "add")
			phone.add();
		else if (command == "sms")
			phone.sms();
		else if (command == "call")
			phone.call();
		else if (command == "exit")
			phone.ex();
		else
			cout << "Unknown command" << endl;
	}
	return 0;
}