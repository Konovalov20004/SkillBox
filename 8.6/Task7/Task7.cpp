#include <iostream>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;

void chek(int &a) {
	while (true) {
		cin >> a;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Eror"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
}

void chek(float &a) {
	while (true) {
		cin >> a;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Eror" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
}

int main() 
{
	setlocale(LC_ALL, "ru");
	int a, b;
	float t;
	cout << "Введите количество крутящихся ручек." << endl;
	chek(a);
	cout << "Введите количество значений на ручке." << endl;
	chek(b);
	cout << "Введите время затрачиваемое на введение комбинаций." << endl;
	chek(t);
	a = pow(b, a);
	t *= a;
	cout << t;

}