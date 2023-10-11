#include <iostream>

using namespace std;

int main()
{
    int number[15]{114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int min{number[0]}, sum{};
    for (int i = 0; i < 15; i++) {
        if (min > number[i]){
            min = number[i];
        } sum += number[i];
    }
    cout << sum - ((min + (min + 13)) * 14) / 2 << endl;
}
