#include <iostream>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;

void chek(int &a) {
	for (;;) {
		cin >> a;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Eror" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else { break; }
	}
}

void chek(float &a) {
	for (;;) {
		cin >> a;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Eror" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else { break; }
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	float W, D, Nold, Nnew;
	cout << "Введите число капель воды" << endl;
	chek(W);
	cout << "Введите число антибиотика" << endl;
	chek(D);
	cout << "Введите число бактерий" << endl;
	chek(Nold);
	for (int i = 0; i < 20; i++) {
		Nnew = Nold * 2 - Nold * D / W;
		D -= D * 0.2;
		if (Nnew <= 0) {
			Nnew = 0;
			cout << "Количество бактерий: " << Nnew << endl;
			break;
		}
		else if (D <= 0) {
			D = 0;
			cout << "Антибиотик закончился" << endl;
			break;
		}
		cout << "Количество бактерий: " << Nnew << endl;
	}
}