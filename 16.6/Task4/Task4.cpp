#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum note {DO = 1, RE = 2, MI = 4, FA = 8, SOL = 16, LA = 32, SI = 64};

int enter_note(string result) {
	char note[12];
	int notei, count;
	while (true) {
		cin >> note;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else {
			for (int i = 0; i < sizeof(note) && sizeof(note) <= 12 && sizeof(note) > 0; i++) {
				if (note[i] > 7 || note[i] < 1) { return 1; }
				string tmp += " " + note[i];
				notei = atoi(tmp);
				count++;
				convert(notei, result);
			}
		}
		return 0;
	}
}

void convert(int note, string result) {
	note--;
	switch (note) {
	case 0:
		result += "DO ";
		break;
	case 1:
		result += "RE ";
		break;
	case 2:
		result += "MI ";
		break;
	case 3:
		result += "FA ";
		break;
	case 4:
		result += "SOL ";
		break;
	case 5:
		result += "LA ";
		break;
	case 6:
		result += "SI ";
		break;
	}
}

int main() {
	string result;
	while (result)
	return 0;
}