#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string patch{ "D:/cyber.png" };
	ifstream File;
	File.open(patch, ios::binary);

	char temp[4]{};
	File.read(temp, sizeof(temp));

	bool result{true};
	char ans[] {-119,'P', 'N', 'G'};
	for (int i = 0; i < sizeof(temp) / sizeof(temp[0]); i++) {
		if (!(temp[i] == ans[i])){
			result = false;
		break;
	}
	}
	if (result)
		cout << "This png" << endl;
	else
		cout << "Not png" << endl;
	File.close();
}