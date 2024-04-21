#include "ram.h"

void save(int const SIZE) {
	vector<int> a = read();
	string path{ "C:/Users/Sergey/Desktop/C++/Learn/SkillBox/25/2CMake/data.bin" };
	ifstream test(path);
	if (!test.is_open()) {
		ofstream test1(path);
		if (!test1.is_open())
			cerr << "Error" << endl;
		test1.close();
	}
	test.close();
	ofstream file(path, ios::binary);
	for (int i = 0; i < SIZE; i++) {
		file << a[i] << ' ';
	}
	file.close();
	cout << "Save complite" << endl;
}

void load(int const SIZE) {
	vector<int> a{};
	string path{ "C:/Users/Sergey/Desktop/C++/Learn/SkillBox/25/2CMake/data.bin" };
	ifstream file(path, ios::binary);
	if (!file.is_open()) {
		cout << "File not found" << endl;
		return;
	}
	for (int i = 0; i < SIZE; i++) {
		int tmp;
		file >> tmp;
		a.push_back(tmp);
	}
	write(a);
	cout << "Buf load" << endl;
}