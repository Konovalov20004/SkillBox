#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> numbers = { -2,1,-3,4,-1,2,1,-5,4 };
	int max{ numbers[0] + numbers[0] }, pos[2]{}, tmp{};
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i; j < numbers.size(); j++) {
			tmp += numbers[j];
			if (tmp > max) {
				max = tmp;
				pos[0] = i;
				pos[1] = j;
			}
		} tmp = 0;
	
	}
	cout << max << ' ' << pos[0] << ' ' << pos[1] << endl;
	return 0;
}