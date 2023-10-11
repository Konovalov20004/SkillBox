#include <iostream>
#include <vector>

using namespace std;

void showVec(const vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void showVec(const vector<float>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void fillVec(vector<int>& a) {
    int value{};
    for (int i = 0; i < a.size(); i++) {
        cin >> value;
        a[i] = value;
    }
}

void fillVec(vector<float>& a) {
    int value{};
    for (int i = 0; i < a.size(); i++) {
        cin >> value;
        a[i] = value;
    }
}

int main()
{
    vector<float> prices{ 2.5, 4.25, 3.0, 10.0 };
    vector<int> items{ 1, 1, 0, 3 };
    float sum{};

    for (vector<int>::iterator it = items.begin(); it != items.end();) {
        sum += prices[*it];
        it++;
    }
    cout << sum;
}

