#include <iostream>
#include <cmath>
#include <string>

using namespace std;

enum Switches {
        HOME_POWER = 1,
        SOCKETS = 2,
        LIGHTS_INSIDE = 4,
        LIGHTS_OUTSIDE = 8,
        HEATERS = 16,
        WATER_PIPE_HEATING = 32,
        CONDITIONER = 64
};
bool* cond = new bool{ 0 };
bool* heating = new bool{ 0 };
bool* heaters = new bool{ 0 };
bool* move_out = new bool{ 0 };
bool* switch_light = new bool{ 0 };
int color_ligth = 5000;

template <typename T>
void enter(T& tmp, string& status) {
    string temp;
    for (int i = 0;  i <= status.length(); i++) {
        if (status[i] != ' ') {
            temp = temp + status[i];
        }
        else {
            if (temp == "yes" || temp == "on") {
                tmp = true;
                status.erase(0, ++i);
                break;
            }
            else if (temp == "" || temp == "no") {
                tmp = false;
                status.erase(0, ++i);
                break;
            }
            else {
                tmp = stoi(temp);
                status.erase(0, ++i);
                break;
            }
        }
    }
}


void core(int& temp_outside, int& temp_inside, bool& movement, bool& light, int& time) {

    if (temp_outside < 0 && !*heating) {
        string message = "Water pipe heating on";
        cout << message << endl;
        *heating = true;
    }
    if (temp_outside > 5 && *heating) {
        *heating = false;
        cout << "Water pipe heating off" << endl;
    }
    if (temp_inside < 22 && !*heaters) {
        string message = "Heaters on";
        cout << message << endl;
        *heaters = true;
    }
    if (temp_inside >= 25 && *heaters) {
        *heaters = false;
        cout << "Heaters off" << endl;
    }
    if (temp_inside >= 30 && !*cond) {
        string message = "Conditioner on";
        cout << message << endl;
        *cond = true;
    }
    if (temp_inside <= 25 && *cond) {
        *cond = false;
        string message = "Conditioner off";
        cout << message << endl;
    }
    if (time > 16 && time < 5 && movement && !*move_out) {
        *move_out = true;
        string message = "Light outside on";
        cout << message << endl;
    }
    if (time > 16 && time < 5 && !movement && *move_out) {
        string message = "Light outside off";
        *move_out = false;
    }
    if (light && !*switch_light){
        *switch_light = true;
        cout << "Light on" << endl;
        cout << "Color temperature: " << color_ligth << endl;
    } else if (light) {
        cout << "Color temperature: " << color_ligth << endl;
    }
    if (!light && *switch_light) {
        *switch_light = false;
        cout << "Light off" << endl;
    }
    if (time > 16 && time < 20 && light) {
        color_ligth -= 575;
    }
    if (time == 24) {
        time = 0;
        color_ligth = 5000;
    }

}

bool check(int& temp_outside, int& temp_inside) {
    bool result = true;
    if (temp_outside > 50 || temp_outside < -50)
        result = false;
    if (temp_inside > 50 || temp_inside < -50)
        result = false;
    return result;
}

int main() {
    string message;
    int time = 0;
    int temp_outside{}, temp_inside{};
    bool movment{}, light{};
    int count = 0;
    while (count < 48) {
        cout << "Temperature inside, temperature outside, movement, lights:" << endl;
        getline(cin, message);
        enter(temp_inside, message);
        enter(temp_outside, message);
        enter(movment, message);
        enter(light, message += ' ');
        if (!check(temp_outside, temp_inside))
            continue;
        core(temp_outside, temp_inside, movment, light, time);
        count++;
    }
    return 0;
}
