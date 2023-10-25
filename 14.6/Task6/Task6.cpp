#include <iostream>

using namespace std;

int main() {
	int matrix[5][5]{};
	int multiple{1}, count{}, j{};
	for (int i = 0; i < 5; i++) {
		for (; j < 5 && j >= 0; count++, j += multiple) {
			matrix[i][j] = count;
		}
	multiple *= -1;
	j += multiple;
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << matrix[i][j] << ' ';
		} cout << endl;
	}
}