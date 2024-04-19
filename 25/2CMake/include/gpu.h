#pragma once

#include "ram.h"
#include <iostream>

void display(int const SIZE = 8) {
	vector<int> buf = read();
	for (int i = 0; i < SIZE; i++) {
		cout << buf[i] << ' ';
	}
	cout << endl;
}