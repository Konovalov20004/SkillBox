#include <iostream>
#include <map>
#include <string>

using namespace std;

string enter() {
    string data;
    while (true) {
        cin >> data;
        if (cin.fail() || cin.peek() != '\n') {
            cerr << "Error" << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        return data;
    }
}

int main()
{
    map<char, int> word;
    string example;
    bool result{ true };

    while(true){
        example = enter();
        for (int i = 0; i < example.length(); i++) {
            pair<char, int> tmp(example[i], i);
            word.insert(tmp);
        }

        example = enter();
        for (int i = 0; i < example.length(); i++) {
            if (word.find(example[i]) != word.end())
                continue;
            else {
                result = false;
                break;
            }
        }
        cout << boolalpha << result << endl;
    }
}
