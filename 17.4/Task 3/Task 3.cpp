#include <iostream>

using namespace std;

bool substr(const char* fullstr, char* substring) {
	for (int i = 0, j = 0; i < strlen(fullstr); i++) {
		if (substring[j] == fullstr[i]) {
			j++;
		}
		if (j == strlen(substring)) {
			return true;
		}
	}
	return false;
}

int main()
{
	const char* string{ "Hello world" };
	char sub[]{ "wor" };
	char sub2[]{ "banana"};
	cout << substr(string, sub) << endl;
	cout << substr(string, sub2) << endl;
	
}