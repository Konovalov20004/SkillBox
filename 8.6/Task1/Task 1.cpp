#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int f, m, t;
	float distance, a;
	cout << "Введите массу корабля: ";
	cin >> m;
	cout << "Введите силу тяги двигателя корабля: ";
	cin >> f;
	cout << "Введите время, на которое включитcя двигатель: ";
	cin >> t;
	a = (float)f / (float)m;
	distance = a * pow(t, 2) / 2;
	cout << "Корабль переместиться на " << distance;
}