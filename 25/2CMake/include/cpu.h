#pragma once

#include "ram.h"
#include "disk.h"
#include "gpu.h"


void compute() {
	vector<int> buf = read();
	int summ{};
	for (int i = 0; i < SIZE; i++) {
		summ += buf[i];
	}
	cout << summ << endl;
	summ = {};
}