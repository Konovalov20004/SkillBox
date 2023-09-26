#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    float distance, tempo = 0;
    cout << "Привет, Сэм! Сколько километров ты сегодня пробежал? ";
    do {
        cin >> distance;
        if (distance <= 0) {
            cout << "Так не получится вычислить средний темп" << endl;
        }
    } while (distance <= 0);
    for (int c = 1, a = 0; c < distance + 1; c++) {
        cout << "Какой у тебя был темп на километре" << c << " ?";
        cin >> a;
        if (a <= 0) {
            cout << "Ошибся, перепроверь";
            c--;
            continue;
        }
        tempo += a;
    }
    tempo /= distance;
    distance = (int)tempo / 60;
    tempo -= distance * 60;
    cout << "Твой средний темп за тренировку: " << distance << " минуты " << round(tempo) << " секунд.";
}