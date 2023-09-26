#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    float size = 0, speed, Size, con;
    do {
        cout << "Укажите размер файла для скачивания: ";
        cin >> size;
        cout << "Какова скорость вашего соединения? ";
        cin >> speed;
        if (size <= 0 || speed <= 0) {
            cout << "Так файл не скачается никогда" << endl;
        }
    } while (size <= 0 || speed <= 0);
    Size = size;
    for (int c = 1;; c++) {
        cout << "Прошло " << c << " сек.";
        size -= speed;
        con = (100.f / Size) * (speed * c);
        if (size <= 0) {
            size = 0;
            con = 100;
        }
        cout << " Скачано ";
        if (size == 0) {
            cout << Size;
        }
        else {
            cout << speed * c;
        }
        cout << " из " << Size << " МБ (" << (int)con << "%)." << endl;
        if (size == 0) { break; }
    }
}