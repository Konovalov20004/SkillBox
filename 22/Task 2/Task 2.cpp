#include <iostream>
#include <string>
#include <map>

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
	multimap<string, int> tail;
	auto save_ptr = tail.begin();

	while (true) {
		string name{ enter() };
		if (name != "next") {
			pair<string, int> tmp(name, 1);
			tail.insert(tmp);
		}
		else {
			multimap<string, int>::iterator it = tail.begin();
			cout << it->first << endl;
			tail.erase(it);
		}
	}
}
