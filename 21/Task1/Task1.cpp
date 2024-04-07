#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct person {
    string name{};
    string lastname{};
    int money{};
    string date{};
};

string enter() {
    string tmp{};
    while (true) {
        cin >> tmp;
        if (cin.fail() || cin.peek() != '\n') {
            cerr << "Error" << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        return tmp;
    }
}

void add_person(string patch) {
    ofstream file(patch,ios::app);

    person tmp;

    tmp.name = enter();
    file << tmp.name << ' ';
    tmp.lastname = enter();;
    file << tmp.lastname << ' ';
    tmp.money = stoi(enter());
    file << tmp.money << ' ';
    tmp.date = enter();;
    file << tmp.date << '\n';
    
    file.close();
}

void read_list_person(string patch) {
    ifstream file(patch, ios::binary);
   
    while (!file.eof()) {
        string tmp;
        file >> tmp;
        cout << tmp;
        if (file.get() == ' ')
            cout << " ";
        else
            cout << '\n';
    }

    file.close();

}

int main()
{
    string patch{};
    fstream file(patch);
    if (!file.is_open())
        patch = "file.bin";

    while (true) {
        string move{};
        move = enter();
        if (move == "list")
            read_list_person(patch);
        if (move == "add")
            add_person(patch);
        else {
            cout << "Exit" << endl;
            exit(0);
        }
    }
}
