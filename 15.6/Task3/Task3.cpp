#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

int enter_value() {
	int value;
	while (true) {
		cin >> value;
		if (cin.fail()) {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else {
			break;
		}
	} return value;
}

void fill_arr(vector<int>& arr,int value) {
	if (arr.empty()) {
		arr.push_back(value);
	}
	else {
		arr.resize(arr.size() + 1);
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] > value) {
				int tmp = arr[i];
				arr[i] = value;
				value = tmp;
			}
			else {
				if (arr[i] == arr.back()) {
					arr.back() = value;
					break;
				}
				else {
					continue;
				}
			}
		}
	}
}

void search_value(vector<int>& arr) {
	cout << arr[4] << endl;
}

int main() {
	int value{};
	vector<int> arr;
	cout << "Enter numbers, -1 if you want to see the 5th number in ascending order, -2 if you want to end the program" << endl;
	while (true) {
		value = enter_value();
		if (value == -1) {
			search_value(arr);
		}
		else if (value == -2) {
			break;
		}
		else {
			fill_arr(arr, value);
		}

	}

	return 0;
}