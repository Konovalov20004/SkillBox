#include "ram.h"

void display(int const SIZE) {
	vector<int> buf = read();
	for (int i = 0; i < SIZE; i++) {
		cout << buf[i] << ' ';
	}
	cout << endl;
}