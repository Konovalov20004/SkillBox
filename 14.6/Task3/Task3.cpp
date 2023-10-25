#include <iostream>

using namespace std;

int enter() {
	int value;
	while (true) {
		cin >> value;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else {
			return value;
		}
	}
}

void fillMatrix(int** a, int ** b ,const int SIZE) {
	cout << "Fill first matrix" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << "Fill " << i + 1 << " row :" << endl;
		for (int j = 0; j < SIZE; j++) {
			a[i][j] = enter();
		} 
	}
	cout << "Fill second matrix" << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << "Fill " << i + 1 << "row :" << endl;
		for (int j = 0; j < SIZE; j++) {
			b[i][j] = enter();
			if (a[i][j] != b[i][j]) { 
				cout << "Matrix are not eqal" << endl;
				exit(0); }
		}
	}
}

void diagMatrix(int **a, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i == j) { continue;}
			a[i][j] = 0;
		}
	}
}

void initMatrix(int** a, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		a[i] = new int[SIZE];
	}	
}


void remMatrix(int** a, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		delete a[i];
	}
}

void showMatrix(int** a, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << a[i][j] << ' ';
		} cout << endl;
	}
}

int main() {
	int SIZE = 4;
	int** matrixFirst = new int* [SIZE];
	initMatrix(matrixFirst, SIZE);
	int** matrixSecond = new int* [SIZE];
	initMatrix(matrixSecond, SIZE);
	fillMatrix(matrixFirst, matrixSecond, SIZE);
	showMatrix(matrixFirst, SIZE);
	diagMatrix(matrixFirst, SIZE);
	showMatrix(matrixFirst, SIZE);
	remMatrix(matrixFirst, SIZE);
	remMatrix(matrixSecond, SIZE);
	delete[]  matrixFirst;
	delete[]  matrixSecond;
}