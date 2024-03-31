#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string Patch{ "C:/Word.txt" };
	fstream File;
	File.open(Patch);
	if (File.is_open()) {
		while (!File.eof()) {
			string tmp;
			File >> tmp;
			cout << tmp + " ";
			if (File.peek() == '\n') {
				cout << endl;
			};

		}
	}
	else {
		cout << "File not support" << endl;
	}
	File.close();
}