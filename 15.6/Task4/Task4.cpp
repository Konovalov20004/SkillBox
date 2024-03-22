#include <vector>
#include <iostream>
#include <cmath>

using namespace std;



int main() {
	int arr[] = { -100,-50, -6, -5, 0, 1, 10, 12, 15, 16, 99 };
	int n{};
	bool ind = false;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] < 0) {
			n = i;
		}
		else { break; }
	}
	for (int i = n, c = 1; i >= 0; i--) {
		begin:
		if (abs(arr[i]) > arr[n + c] && c + n < sizeof(arr)/sizeof(arr[0])) {
			cout << arr[n + c] << ' ';
			++c;
			goto begin;
		}
		else {
			cout << arr[i] << ' ';
		}
	}
	return 0;
}