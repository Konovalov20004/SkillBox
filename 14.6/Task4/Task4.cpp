#include <iostream>
#include <vector>

using namespace std;

void multiple(const int const SIZE,static float a[][4],static vector<float> &b, vector<float> &c) {
	float result{};
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			c[i] += a[i][j] * b[j];
		}
	}
}

void enter_matrix(float a[][4], const int SIZE) {
	float value;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> value;
			if (cin.fail() || cin.peek() != '\n') {
				cerr << "Error" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max() || '\n');
			}
			else { 
				a[i][j] = value;
			}
		}
	}
}

void enter_vec(vector<float>& a, const int SIZE) {
	float value;
	for (int i = 0; i < SIZE; i++) {
		cin >> value;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');			}
		else {
			a[i] = value;
		}
	}
}

void show(const vector<float>& a, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << a[i] << ' ';
	}
}

int main() {
	const int SIZE = 4;
	float matrix[4][4];
	enter_matrix(matrix, SIZE);
	vector<float> vec(4);
	enter_vec(vec, SIZE);
	vector<float> res{0,0,0,0};
	multiple(SIZE, matrix, vec, res);
	show(res, SIZE);
}