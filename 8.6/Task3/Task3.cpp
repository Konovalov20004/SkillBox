#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    float width = 5, height = 35.76, length = 35.05;
    int a = 2, countCube;
    bool c = true;
    do {
        cout << "Введите размеры бруска: " << endl;
        cout << "X: ";
        cin >> length;
        cout << "Y: ";
        cin >> width;
        cout << "Z: ";
        cin >> height;
        if (length <= 0 || width <= 0 || height <= 0) {
            cout << "Величины не могут быть отрицательными!" << endl;
        }
    } while (length <= 0 || width <= 0 || height <= 0);
    countCube = ((int)width * (int)height * (int)length) / 125;
    for (;; a++) {
        if (!((int)countCube - pow(a + 1, 3) > 0)) { break; }
    }
    cout << "Из этого бруска можно изготовить " << (int)countCube << " кубиков." << endl;
    cout << "Из них можно составить набор из " << pow(a, 3) << " кубиков.";
}