#pragma once

#include <vector>
#include "kbd.h"

using namespace std;

vector<int> buf{ 0,0,0,0,0,0,0,0 };
const int SIZE = 8;

void write() {
	int x{};
	for (int i = 0; i < SIZE; i++) {
		cout << "Enter " << i + 1 << " number: ";
		cin >> x;
		buf[i] = x;
	}
}

void write(vector<int> a) {
	buf = a;
}

vector<int> read() {
	return buf;
}
