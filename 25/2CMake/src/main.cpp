#include "cpu.h"

using namespace std;

int main()
{
	string command;
	while (true) {
		cin >> command;
		if (command == "input") {
			write();
			continue;
		}
		if (command == "display") {
			display();
			continue;
		}
		if (command == "sum") {
			compute();
			continue;
		}
		if (command == "save") {
			save();
			continue;
		}
		if (command == "load") {
			load();
			continue;
		}
		if (command == "exit")
			exit(0);
		cout << "Unknow command. Try one " << endl;
	}
}
