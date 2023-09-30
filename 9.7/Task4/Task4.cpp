#include <iostream>
#include <limits>
#include <numeric>
#include <string>

using namespace std;

void check(string& var) {
	while(true)
	{
		cin >> var;
		if (cin.fail() || cin.peek() != '\n' || var.length() > 4) {
			cerr << "error"<< endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else {
			break;
		}
	}
}

int main() {
	string value{}, var{};
	int countBull = 0, countCow = 0;
	check(value);
	while (true) {
		check(var);
		for (int i = 0, x = 0; i < value.length() * value.length(); x++) {
			if (i == x && value[i] == var[i]) {
				countBull++;
			}
			if (value[i] == var[x]) {
				countCow++;
			}
			if (x == var.length() - 1 && i == value.length() - 1) {
				break;
			}
			else if (x == var.length() - 1) {
				i++;
				x = 0;
			}
		} cout << "Bull\t" << countBull << endl << "Cow\t" << countCow << endl;
		countBull = 0;
		countCow = 0;
	} 
}
