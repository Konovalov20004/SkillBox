#include <limits>
#include <numeric>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    while (true) {
        string value{}, result{}, values{ 'M', 'C', 'X', 'I', 'D', 'L', 'V' };
        while (true) {
            cin >> value;
            if (cin.fail() || cin.peek() != '\n')
            {
                cerr << "error";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max() || '\n');
            }
            else
            {
                break;
            }
            if (value > "3999" || value < "1") {
                cout << "Switch number";
            }
            else {
                break;
            }
        }
        for (; value.length() < 4;) {
            switch (value.length()) {
            case 1: value = "000" + value;
                break;
            case 2: value = "00" + value;
                break;
            case 3: value = '0' + value;
            }
        }
        for (int i = 0; i < value.length(); i++) {
            if (value[i] == '0') {
                continue;
            }
            if (value[i] < '4') {
                switch (value[i]) {
                case '1': result += values[i];
                    break;
                case '2': result += values[i];
                    result += values[i];
                    break;
                case '3': result += values[i];
                    result += values[i];
                    result += values[i];
                    break;
                }
            }
            else if (value[i] == '4' || value[i] == '9') {
                switch (value[i]) {
                case '4': result += values[i];
                    result += values[i + 3];
                    break;
                case '9': result += values[i];
                    result += values[i - 1];
                    break;
                }
            }
            else if (value[i] >= '5') {
                switch (value[i]) {
                case '5': result += values[i + 3];
                    break;
                case '6': result += values[i + 3];
                    result += values[i];
                    break;
                case '7': result += values[i + 3];
                    result += values[i];
                    result += values[i];
                    break;
                case '8': result += values[i + 3];
                    result += values[i];
                    result += values[i];
                    result += values[i];
                    break;
                }
            }
        }cout << result << endl;

    }
}

