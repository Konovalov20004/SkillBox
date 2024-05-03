#include "CMakeProject2.h"
#include "CMakeProject2.cpp"

using namespace std;

string enter() {
	string data;
	while (true) {
		cin >> data;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error enter" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			continue;
		}
		return data;
	}
}

double enter_size() {
	double data;
	while (true) {
		cin >> data;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error enter" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			continue;
		}
		return data;
	}
}

int main()
{
	Size size{};
	string command;
	cout << "Enter name figure:" << endl;
	command = enter();
	if (command == "triangle") {
		cout << "Enter size triangle" << endl;
		size.high = enter_size();
		Triangle triangle(size.high);
	}
	if (command == "square") {
		cout << "Enter size side square" << endl;
		size.high = enter_size();
		Square square(size.high);
	}
	if (command == "circle") {
		cout << "Enter radius circle" << endl;
		size.high = enter_size();
		Circle circle(size.high);
	}
	if (command == "rectangle") {
		cout << "Enter size rectangle" << endl;
		size.high = enter_size();
		size.wide = enter_size();
		Rectangle rectangle(size.high, size.wide);
	}
	return 0;
}
 