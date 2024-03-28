#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swapvector(vector<int> &a, int* b) {
    int i{};
    for (vector<int>::iterator el = a.begin(); el != a.end(); el++, i++) {
        int temp = b[i];
        b[i] = *el;
        *el = temp;
    }
}

int main()
{
    vector<int> a{ 2,4,5,6,3 };
    int b[]{ 1,2,3,4,5 };

    for (vector<int>::iterator i = a.begin(); i != a.end(); i++) {
        cout << *i << " ";
    }

    cout << endl;

    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
        cout << b[i] << " ";
    }

    cout << "\n" << "Swap" << endl;
    swapvector(a, b);

    for (vector<int>::iterator i = a.begin(); i != a.end(); i++) {
        cout << *i << " ";
    }

    cout << endl;

    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
        cout << b[i] << " ";
    }
    
}
