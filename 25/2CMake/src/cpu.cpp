#include "ram.h"


void compute() {
	vector<int> buf = read();
	int summ{};
	for (int i = 0; i < 8; i++) {
		summ += buf[i];
	}
	cout << summ << endl;
	summ = {};
}