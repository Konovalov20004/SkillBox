#include "1-CMake.h"

using namespace std;

int main()
{
	string command{};
	point a,b;
	step beg;
	step en;
	while (true) {
		cin >> command;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (command == "scalpel") {
			a = enter();
			b = enter();
			scalpel(a, b);
			beg.a = a;
			beg.b = b;
			continue;
		}

		if (command == "hemostat") {
			a = enter();
			hemostat(a);
			continue;
		}

		if (command == "tweezers") {
			a = enter();
			tweezers(a);
			continue;
		}

		if (command == "suture") {
			a = enter();
			b = enter();
			suture(a, b);
			en.a = a;
			en.b = b;
			if (en.a.a == beg.a.a && en.a.b == beg.a.b
				&& en.b.a == beg.b.a && en.b.b == beg.b.b)
				cout << "Surgency done";
			else
				cout << "Cut not wired";
		}
		
	}
}
//hemostat tweezers suture