#include <iostream>

using namespace std;

int result{};

void enter_coord(int coord[]) {
	int value{};
	cout << "Enter coordinate x y - start, x y - end" << endl;
	for (int i = 0; i < 4; i++) {
	onemore:
		cin >> value;
		if (cin.fail() || value > 16 || value < 0) {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
			goto onemore;
		}
		else {
			coord[i] = value;
		}
	}
}

void pop(bool a[][16], int coord[]) {
	for (int i = coord[0]; i < coord[2]; i++) {
		for (int j = coord[1]; j < coord[3]; j++) {
			if (a[i][j]) {
				cout << "pop" << ' ';
				a[i][j] = false;
				result++;
			}
			else {
				cout << "    ";
			}
		} cout << endl;
	} 
}

void main() {
	bool matrix[16][16];
	int coord[4]{};
	while (result < 16 * 16) {
		enter_coord(coord);
		while (coord[0] > coord[2] || coord[1] > coord[3]) {
			cout << "Invalid coord. Try one more. The start coordinates must be less than the end coordinates " << endl;
			enter_coord(coord);
		}
		if (coord[0] == coord[2]) coord[2]++;
		if (coord[1] == coord[3]) coord[3]++;
		pop(matrix, coord);
	}
	cout << '\n' << result;
}
