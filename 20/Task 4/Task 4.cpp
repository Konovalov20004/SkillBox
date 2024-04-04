#include <iostream>
#include <fstream>
#include <string>


using namespace std;

string enter() {
	string data;
	while (true) {
		cin >> data;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Fail" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		return data;
	}
}

int enter_int() {
	int data;
	while (true) {
		cin >> data;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Fail" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		return data;
	}
}

void out(int** arr) {
	for (int i = 0, j = 0; j < 2; i++) {
		cout << arr[j][i] << '\t';
		if (i == 5) {
			i = -1;
			j++;
			cout << endl;
		}
	}
}

void add_money(int** arr) {
	for (int i = 0; i < 6; i++) {
		if (arr[1][i] == 0) {
			if (arr[0][i] == 1000) {
				arr[1][i] = 170;
				continue;
			}
			arr[1][i] = 166;
		}
	}
}


void get_money(int** arr) {
	int summ{}, max_summ{};
	for (int i = 0; i < 6; i++) {
		max_summ += arr[1][i] * arr[0][i];
	}
	if (max_summ == 0) {
		cout << "No money" << endl;
		return;
	}
	cout << "Enter summ" << endl;
	summ = enter_int();
	for (int i = 5; i >= 0; i--) {
		for (int i = 0; i < 6; i++) {
			max_summ += arr[1][i] * arr[0][i];
		}
		if (max_summ == 0) {
			cout << "No money" << endl;
			return;
		}
		if (!(summ % 100 == 0) || summ > max_summ) {
			cout << "Is not values" << "\nMax: " << max_summ << endl;
			return;
		}
		if (arr[1][i] > 0) {
			if (summ < arr[1][i] * arr[0][i]) {
				arr[1][i] -= summ / arr[0][i];
				summ %= arr[0][i];
			}
			else {
				summ -= (arr[1][i] * arr[0][i]);
				arr[1][i] = 0;
			}
		}
		if (arr[1][i] == 0)
			continue;
		if (summ <= 0)
			break;
	}
}

void EXIT(int** arr) {
	string patch{ "money.bin" };
	ofstream ofile(patch, ios::binary);

	for (int i = 0, j = 0; j < 2; i++) {
		ofile << arr[j][i];
		if (i == 5) {
			ofile << endl;
			i = -1;
			j++;
		}
		else
			ofile << " ";
	}

	ofile.close();
}

int main()
{
	string patch{"money.bin"};
	ifstream ifile(patch, ios::binary);

	int** arr = new int* [2];
	for (int i = 0; i < 2; i++) {
		arr[i] = new int[6] {};
	}

	char sym{};

	if (!ifile.is_open()) {
		cout << "No money" << endl;
		int tmp[6] = { 100, 200, 500, 1000, 2000, 5000 };
		for (int i = 0; i < 6; i++) {
			arr[0][i] = tmp[i];
		}
		add_money(arr);
	}
	else {
		for (int row = 0, col = 0; !ifile.eof(); col++) {
			ifile >> arr[row][col];
			if (ifile.peek() == '\r' || ifile.peek() == '\n') {
				row = 1;
				col = -1;
			}
		}
	}

	ifile.close();

	while (true) {
		out(arr);
		sym = enter()[0];
		if (sym == 'x') {
			cout << "Exit" << endl;
			EXIT(arr);
			exit(0);
		}
		if (sym == '+') {
			add_money(arr);
		}
		if (sym == '-') {
			get_money(arr);
		}
	}
	
	for (int i = 0; i < 2; i++) {
		delete arr[i];
	}
	delete[] arr;

}
