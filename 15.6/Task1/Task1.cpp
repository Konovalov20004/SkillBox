#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
	const int size = 9;
	int arr[size]{ -2, 1, 3, 4, -1 ,2 ,1 ,-5 ,4 };
	int sum = 0, maxSum = 0, a = 0, b = 0, bi = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
		if (sum > maxSum) {
			maxSum = sum;
			b = i;
		}
		if (sum < 0) {
			sum = 0;
			a = i + 1;
		}
		if (a < b)
			bi = a;
	}
	cout << bi << "\t" << b;
}