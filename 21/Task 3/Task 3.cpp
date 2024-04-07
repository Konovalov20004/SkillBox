#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct vec {
    double x;
    double y;
};

string enter() {
    string tmp;
    while (true) {
        cin >> tmp;
        if (cin.fail() || cin.peek() != '\n') {
            cerr << "Error";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        return tmp;
    }
}

void enter(vec& A, vec& B) {
    cout << "Enter coord x vectora A ";
    A.x = stod(enter());
    cout << "Enter coord y vectora A ";
    A.y = stod(enter());
    cout << "Enter coord x vectora B ";
    B.x = stod(enter());
    cout << "Enter coord y vectora B ";
    B.y = stod(enter());
}

void enter(vec& A) {
    cout << "Enter coord x vectora A ";
    A.x = stod(enter());
    cout << "Enter coord y vectora A ";
    A.y = stod(enter());
}

int main()
{
    string command;
    vec A, B;
 
    cout << "Enter command: normalize add subtract scalar length" << endl;
    string commands = " normalizeaddsubtractscalarlength";
    command = enter();
    if (!commands.find(command)) {
        cout << "Command not found";
        exit(0);
    }

    if (command == "normalize") {
        enter(A);
        B.x = A.x / abs(sqrt(pow(A.x, 2) + pow(A.y, 2)));
        B.y = A.y / abs(sqrt(pow(A.x, 2) + pow(A.y, 2)));
        cout << "Normalize vector A (" << A.x << ", " << A.y << ")" <<" = B(" << B.x << ", " << B.y << ")" << endl;
    }

    if (command == "add") {
        enter(A, B);
        A.x += B.x;
        A.y += B.y;
        cout << "A + B = C (" << A.x << ", " << A.y << ")" << endl;
    }

    if (command == "subtract") {
        enter(A, B);
        A.x -= B.x;
        A.y -= B.y;
        cout << "A - B = C (" << A.x << ", " << A.y << ")" << endl;
    }

    if (command == "scalar") {
        enter(A);
        double tmp{};
        cout << "Enter scalar: ";
        tmp = stod(enter());
        A.x *= tmp;
        A.y *= tmp;
        cout << "A * scalar b = C (" << A.x << ", " << A.y << ")" << endl;
    }

    if (command == "length") {
        enter(A);
        int length = abs(sqrt(pow(A.x, 2) + pow(A.y, 2)));
        cout << "Length A = " << length << endl;
    }
}
