#include "CMakeProject3.cpp"

using namespace std;

string enter() {
	string a;
	while (true) {
		cin >> a;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Fail" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		return a;
	}
}

int main()
{
	string command;
	Window window;

	while (true) {
		cout << "Enter command" << endl;
		command = enter();
		if (command == "move") {
			cout << "Enter directinon: left or upleft" << endl;
			string direction;
			direction = enter();
			cout << "Entet number pixel" << endl;
			int x, y;
			x = stoi(enter());
			y = stoi(enter());
			window.move(direction,x,y);
		}
		if (command == "resize") {
			cout << "Enter new size window" << endl;
			int wide, high;
			cout << "Enter wide:" << endl;
			wide = stoi(enter());
			cout << "Enter high:" << endl;
			high = stoi(enter());
			window.resize(wide, high);
		}
		if (command == "display") {
			window.out_window();
		}
		if (command == "exit") {
			window.close();
		}
	}

	return 0;
}
