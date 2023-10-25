#include <iostream>

using namespace std;

void enter(int &x, int &y) {
	while (true) {
		cin >> x >> y;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else {
			if (x < 0 || x > 2 || y < 0 || y > 2) {
				cout << "Invalid coordinates" << endl;
				continue;
			}
			break;
		}
	}
}

bool whoWin(char** const sqare, const int SIZE, char sym) {
	if ((sqare[0][0] != ' ' && sqare[0][0] == sqare[0][1] && sqare[0][1] == sqare[0][2])
		|| (sqare[1][0] != ' ' && sqare[1][0] == sqare[1][1] && sqare[1][1] == sqare[1][2])
		|| (sqare[2][0] != ' ' && sqare[2][0] == sqare[2][1] && sqare[2][1] == sqare[2][2])) {
		cout << "Win who game " << sym << endl;
		return true;
	}
	else if ((sqare[0][0] != ' ' && sqare[0][0] == sqare[1][0] && sqare[1][0] == sqare[2][0])
		|| (sqare[0][1] != ' ' && sqare[0][1] == sqare[1][1] && sqare[1][1] == sqare[2][1])
		|| (sqare[0][2] != ' ' && sqare[0][2] == sqare[1][2] && sqare[1][2] == sqare[2][2])) {
		cout << "Win who game " << sym << endl;
		return true;
	}
	else if ((sqare[0][0] != ' ' && sqare[0][0] == sqare[1][1] && sqare[1][1] == sqare[2][2])
		|| (sqare[0][2] != ' ' && sqare[0][2] == sqare[1][1] && sqare[1][1] == sqare[2][0])) {
		cout << "Win who game " << sym << endl;
		return true;
	} return false;
}

void showSqare(char **a, int SIZE) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

void initSqare(char **a, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		a[i] = new char[SIZE];
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			a[i][j] = ' ';
		}
	}
}

void delSqare(char** a, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		delete a[i];
	}
}

int main()
{
	int SIZE = 3;
	int x{}, y{};
	char sym{};
	char **sqare = new char* [SIZE];
	initSqare(sqare, SIZE);
	for (int i = 0; i < 9; i++) {
		i % 2 == 0 ? sym = 'x' : sym = 'o';
		begin:
		cout << "Step " << sym << endl;
		enter(x, y);
		if (sqare[x][y] == ' ') {
			sqare[x][y] = sym;
		}
		else {
			cout << "Choose anoter place" << endl;
			goto begin;
		}
		showSqare(sqare, SIZE);
		if (whoWin(sqare, SIZE, sym)) { break; }
	}
	delSqare(sqare, SIZE);
	delete[] sqare;
}

