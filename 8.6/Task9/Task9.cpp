#include <iostream>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;
void check(float& a) {
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

int main() {
	float a = 0.732, g;
	cout << " Введите максимально допустимый уровень опасности : ";
	check(g);
	cout << "Приблизительная глубина безопасной кладки : " << a <<" метраa";
}