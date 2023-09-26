#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    float healt, resist, power, damage;
    do {
        cout << "Введите уровень здоровья: ";
        cin >> healt;
        cout << "Введите уровень сопротивления: ";
        cin >> resist;
        if ((healt >= 1 || healt <= 0) && (resist <= 0 || resist >= 1)) {
            cout << "Введите характеристики не более 1 и не менее 0." << endl;
        }
    } while ((healt >= 1 || healt <= 0) && (resist <= 0 || resist >= 1));
    cout << "Начнем сражение." << endl;
    while (true) {
        cout << "Введите силу заклинания: ";
        cin >> power;
        if (power >= 1 || power <= 0) {
            cout << "Укажите значение от 0 до 1" << endl;
            continue;
        }
        damage = power - power * resist;
        healt -= damage;
        cout << "Нанесённый урон: " << damage << ". Осталось очков здоровья " << healt << endl;
    }
}