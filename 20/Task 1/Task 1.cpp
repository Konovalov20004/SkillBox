#include <iostream>
#include <fstream>

using namespace std;

string enter() {
    string data{};
    while (true) {
        cin >> data;
        if (cin.fail() || cin.peek() != '\n') {
            cerr << "Bad data" << endl;
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return data;
    }
}

int main()
{
    string patch{"D:/file.txt"};
    ofstream file(patch, ios::app);
    if (!file.is_open())
        return 1;
    string data = enter();
    
    while (data != "stop") {
        file << data;
        if (data.find('.') != data.npos)
            file << "\n";
        else
            file << ' ';
        data = enter();
    }
    file.close();
}
