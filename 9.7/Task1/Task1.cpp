#include <iostream>
#include <numeric>
#include <limits>

using namespace std;

void check(string &a) {
	while (true) {
		cin >> a;
		if (cin.fail() || cin.peek() != '\n')
		{
			cerr << "Eror" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() != '\n');
		}
		else if (a.length() > 5 || a.length() < 4 || a[3] > '6' || (a[2] != ':' && a[1] != ':' && a[0] > '2')) {
			cout << "Enter the correct time" << endl;
		}
		else if (a[1] == ':') {
			a = '0' + a;
			break;
		}
		else {
			break;
		}
	}
}

void hour(string a, string b, int &r) {
	int i = 0;
	for (; a != b;) {
		if (a[1] == '9') {
			a[0] += 1;
			a[1] = '0';
		}
		else if (a == "23") {
			a = "00";
		}
		else {
			a[1] += 1;
		} i++;
	} r += i;
}

void minut (string a , string b, int &r) {
	int i = 0;
	for (; a != b;) {
		if (a == "59") {
			a = "00";
		} else if (a[1] == '9') {
			a[0] += 1;
			a[1] = '0';
		}
		else {
			a[1] += 1;
		} i++;
	} r += i;
}

int main() {
	string timeBeg{}, timeEnd{}, H{}, h{}, M{}, m{};
	int resulth = 0, resultm = 0;
	check(timeBeg);
	check(timeEnd);
	for (int i = 0; i < 2; i++) {
		H += timeBeg[i];
		h += timeEnd[i];
		M += timeBeg[3 + i];
		m += timeEnd[3 + i];
	}
	if (H == h || H[1] == h[1] || (h[0] - 1 == H[0] && h[1] - 1 == H[1])) {
		minut(M, m, resultm);
	}
	else if (M == m) {
		hour(H, h, resulth);
	}
	else if (h < H && m < M) {
		if (H == "20") {
			H = "19";
		} 
		else if (M == "10") {
			M = "09";
		} 
		else {
			h[1] -= 1;
		}
		hour(H, h, resulth);
		minut(M, m, resultm);
	} 
	else {
		hour(H, h, resulth);
		minut(M, m, resultm);
	} 
	cout << "Travel time:" << endl;
	cout << "Hour\t" << resulth << "\nMinut\t" << resultm;
}