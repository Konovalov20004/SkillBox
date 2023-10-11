#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

void showArr(float* a, const int &SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << a[i] << ' ';
	} cout << endl;
}

float selection(float* a, const int &SIZE) {
	clock_t start = clock();
	for (int i = 0; i < SIZE; i++) {
		int max{ i };
		float temp{};
		for (int j = i + 1; j < SIZE; j++) {
			if (a[max] < a[j]) {
				max = j;
			}
		}
		temp = a[i];
		a[i] = a[max];
		a[max] = temp;
	}
	clock_t end = clock();
	clock_t speed = (end - start) / CLOCKS_PER_SEC;
	return speed;
}

float insert(float *a, const int &SIZE) {
	clock_t start = clock();
	for (int i = 1; i < SIZE; i++) {
		for (int j = i; j > 0 && a[j - 1] < a[j]; j--) {
			swap(a[j], a[j - 1]);
		}
	}
	clock_t end = clock();
	clock_t speed = (end - start) / CLOCKS_PER_SEC;
	return speed;
}

float ShellHib(float* a, const int &SIZE) {
	clock_t start = clock();
	int step{8};
	link:
	for (int i = step; i < SIZE; i+=step) {
		for (int j = i; j > 0 && a[j - step] < a[j]; j-=step) {
			swap(a[j], a[j - step]);
		}
	}
	if (step % 2 == 0) {
		step /= 2;
		goto link;
	}
	else {
		goto exit;
	}
	exit:
	clock_t end = clock();
	clock_t speed = (end - start) / CLOCKS_PER_SEC;
	return speed;
}

float lsd(float* a, const int SIZE) {
	clock_t start = clock();
	int *arr = new int[SIZE];
	delete arr;
	clock_t end = clock();
	clock_t speed = (end - start) / CLOCKS_PER_SEC;
	return speed;
}

void main() {
	const int SIZE = 15;
	float arr[SIZE]{ 1.2, 2.3, 1.11, 3.4, 5.5, 5.4, 5.3, 5.1, 1.5, 1.25, 5.41, 5.31, 5.11, 1.51, 1.251 };
	showArr(arr, SIZE);
	cout << "Time: " << ShellHib(arr, SIZE) << endl;
	showArr(arr, SIZE);
	
}