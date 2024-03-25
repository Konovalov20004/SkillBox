#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int result(int &number, int &len) {
    int a = pow(10, len-1);
    int result = number/a;
    number %= a;
    len--;
    return result;
}

int length(int a) {
    for (int i = 0;; i++) {
        if (a % 10 == 0) 
            return i;
        else
            a /= 10;
    }
}

int main() {
    int a;
    cin >> a; 
    int len = length(a);
    int res = 0;
    for (int i = len; i > 0; i--) {
        int tmp = result(a, len);
        int note = 1 << (tmp - 1);
        res = res | note;
    }
    if (res & note::DO)
        cout << "DO ";
    if (res & note::FA)
        cout << "FA ";
 if (res & note::RE)
        cout << "RE ";
  if (res & note::LA)
        cout << "LA ";
    if (res & note::MI)
        cout << "MI ";
   if (res & note::SOL)
        cout << "SOL ";
     if (res & note::SI)
        cout << "SI ";

}