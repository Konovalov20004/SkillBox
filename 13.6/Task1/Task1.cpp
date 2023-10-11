#include <iostream>
#include <vector>

using namespace std;

void showVec(const vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void fillVec(vector<int> &a) {
    int value{};
    for (int i = 0; i < a.size(); i++) {
        cin >> value;
        a[i] = value;
    }
}

int main()
{
    int value{}, size{};

    cin >> size;
    vector<int> vec(size);

    fillVec(vec);
    showVec(vec);

    cin >> value;
    for (vector<int>::iterator it = vec.begin(); it != vec.end();) {
        if (*it == value) {
            it = vec.erase(it);
        }
        else {
            ++it;
        }
    }
    showVec(vec);
}
