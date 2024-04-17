#define _CRT_SECURE_NO_WARNINGS 1
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string enter() {
	string data;
	while (true) {
		cin >> data;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		return data; 
	}
}

int main()
{
	string status, command, name_task;
	time_t beg, end;
	
	while (true) {
		cout << "Enter command: begin, end, status, exit" << endl;
		command = enter();
		if (command == "begin" && name_task.empty()) {
			cout << "Enter name task" << endl;
			name_task = enter();
			beg = time(nullptr);
			continue;
		}
		else if (command == "begin" && !name_task.empty()) {
			end = time(nullptr);
			status += name_task + ' ' + to_string(difftime(end, beg)) + " sec.\n";
			cout << "Enter name task" << endl;
			name_task = enter();
			beg = time(nullptr);
			continue;
		}
		else if (command == "end" && !name_task.empty()) {
			end = time(nullptr);
			status += name_task + ' ' + to_string(difftime(end, beg)) + " sec.\n";
			name_task = "";
			continue;
		}
		else if (command == "status") {
			cout << name_task + '\n' << status;
			continue;
		}
		else if (command == "exit")
			exit(0);
		cout << "Command not found" << endl;
	}
}

