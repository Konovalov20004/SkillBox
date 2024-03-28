#include <iostream>

using namespace std;

void count_even(long long a, int& answ) {
	while (a != 0) {
		if ((a/10)% 2 == 0)
			answ++;
		a /= 10;
	}
}

int main()
{
	int answ{};
	count_even(8223372036854775806, answ);
	cout << answ;

}