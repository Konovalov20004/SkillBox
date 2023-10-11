#include <iostream>
#include <vector>

using namespace std;

void showVec(const vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> db(20);
	int value{}, i{};
	while (value != -2) {
		cin >> value;
		if (value == -1) {
			showVec(db);
		} else if (db.back() != 0) {
			db.erase(db.begin());
			db.push_back(value);
		}
		else {
			db[i] = value;
			++i;
		}
	}
}
