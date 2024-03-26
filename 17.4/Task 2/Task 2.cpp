#include <iostream>

using namespace std;

void reverse(int* a, const int SIZE) {
    int* temp = new int[SIZE] {};
    for (int i = SIZE-1, j = 0; i >= 0; i--, j++) {
        temp[j] = a[i];
    }
    for (int i = 0; i < SIZE; i++) {
        a[i] = temp[i];
    }
}

int main()
{
    const int SIZE = 10;
    int arr[SIZE]{ 1,2,3,4,5,6,7,8,9,10 };
    cout << arr << "\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    reverse(arr, SIZE);
    cout << "Done" << endl;
    cout << arr << "\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << "\t";
    }
}

