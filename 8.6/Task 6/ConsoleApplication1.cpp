#include <iostream>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;

template <class T, class T1>
T ug(T a, T b, T1 *pc) {
	if (a <= b)
		return NULL;
	(*pc)++;
	a -= a * 0.084;
	return ug(a, b, pc);
}

int main() {
	setlocale(LC_ALL, "ru");
	float amp, nol, c = 0;
	cout << "Введите амплитуду колебания." << endl;
	while (true) {
		cin >> amp;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else { 
			break;
		}
	}
	cout << "Введите условный ноль амплитуды." << endl;
	while (true) {
		cin >> nol;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	ug(amp, nol, &c);
	cout << c;
}