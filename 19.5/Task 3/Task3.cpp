#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string Patch = "C:/Word.txt";
    fstream File;
    File.open(Patch);

    string name{};
    int summ{}, max_money{};
    while (!File.eof()) {
        string tmp_name, tmp_lastname, date;
        int tmp;
        File >> tmp_name;
        File >> tmp_lastname;
        File >> tmp;
        summ += tmp;
        if (tmp > max_money) {
            max_money = tmp;
            name = tmp_name + " " + tmp_lastname;
        }
        File >> date;
    }

    cout << name << " " << max_money << " " << summ;

    File.close();
}
