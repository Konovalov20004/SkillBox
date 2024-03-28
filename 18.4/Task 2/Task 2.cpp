#include <iostream>

using namespace std;

int bannyhope(int n, int k = 3) {
    if (k > 0 && n >= k) {
        return bannyhope(n, k - 1) + bannyhope(n - k, k);
    }
    if (k > n)
        return bannyhope(n, n);
    if (n == 0 && k == 0)
        return 1;
    if (n != 0 && k == 0)
        return 0;
}

int main()
{
    int n{5}, k{3};
    cout << bannyhope(n, k);

}
