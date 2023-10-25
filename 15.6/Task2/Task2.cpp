#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
using namespace std;

int number() {
    int value;
    while (true) {
        cout << "Enter value" << endl;
        cin >> value;
        if (cin.fail() || cin.peek() != '\n') {
            cerr << "Error" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max() || '\n');
        }
        else if (value < 3) {
            cout << "Value small" << endl;
        } else { break; }
    }
    return value;
}

void numbers(vector<int>& values, const int value) {
    for (int i = 1; i < value; i++) {
        values.push_back(i);
    }
}

int search(vector<int> numbers,int& valueFirst, int& valueSecond) {
    bool findFirst = false;
    bool findSecond = false;
    vector<int>::iterator x;
    for(vector<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++)
        if (*itr == valueFirst) {
            findFirst = true;
            x = itr;
            break;
        }
    if (!findFirst) { return 1; }
    for (vector<int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++)
        if (*itr == valueSecond && itr != x) {
            findSecond = true;
            break;
        }
    if (findFirst && findSecond) {
        return 0;
    }
    else { return -1; }
}

int main()
{
    vector<int> values;
    vector<int> arr = { 2, 7, 11, 15, 8, 5, 3 };
    int value = number();
    int x{}, y{};
    numbers(values, value);
    for (int i = 0; i < value / 2; i++) {
        if (!search(arr, values[i], values[values.back() - 1 - i])) {
            x = values[i];
            y = values[values.back() - 1 - i];
            cout << x << " " << y << endl;
            exit(0);
        }
    } 
    cout << "No value" << endl;
    return 0;
}

