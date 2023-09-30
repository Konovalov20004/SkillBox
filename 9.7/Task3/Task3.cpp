#include <iostream>
#include <limits>
#include <numeric>
#include <string>

using namespace std;

int main() {
	string str;
	bool beggin = false, end = false;
	int count = 0;
	getline(cin, str);

	for (int i = 0; i <= str.length() - 1; i++) {
		if (i < str.length() - 1 && str[i] == ' ' && str[i + 1] == ' ') {
			continue;
		}
		if (str[i] != ' ' || (str[i] == ' ' && str[i + 1] != ' ')) {
			beggin = true;
		}
		if ((i == str.length() - 1 && str[i] != ' ') || (str[i] != ' ' && str[i + 1] == ' ')) {
			end = true;
		}
		if (end && beggin) {
			count++;
			beggin = false;
			end = false;
		}
	}
	cout << count;
}