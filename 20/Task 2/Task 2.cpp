#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

int enter() {
    int result;
    while (true) {
        cin >> result;
        if (cin.fail() || cin.peek() != '\n') {
            cerr << "Fail";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return result;
    }
}

int main()
{
    srand(time(NULL));
    string patch{ "pics.txt" };
    ofstream file(patch);

    int row = enter();
    int column = enter();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            file << rand() % 2;
        }
        file << '\n';
    }

    file.close();
}
