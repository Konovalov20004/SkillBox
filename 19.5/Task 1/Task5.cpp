#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	
	string patch = "C:/Word.txt";

	ifstream Word;
	Word.open(patch);

	int count{};
	string searchWord{"cat"};

	while (!Word.eof())
	{
		string tmp;
		Word >> tmp;
		if (tmp == searchWord) {
			count++;
		}
	}
	cout << count;
	Word.close();
	
}