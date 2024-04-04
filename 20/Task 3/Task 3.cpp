#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string enter() {
    string fish{};
    while(true) {
        cin >> fish;
        if (cin.fail() || cin.peek() != '\n') {
            cerr << "Error" << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return fish;
    }
}

int main()
{
    string patch_fish{ "fish.txt" };
    string patch_basket{ "basket.txt" };

    ifstream fish_list(patch_fish);
    ofstream basket(patch_basket, ios::app);

    if (!fish_list.is_open() && !basket.is_open()) {
        return 1;
    }

    string fish{};
    fish = enter();

    while (!fish_list.eof()) {
        string temp{};
        fish_list >> temp;
        if (temp == fish) {
            basket << fish << endl;
            break;
        }
    }

    fish_list.close();
    basket.close();

}


