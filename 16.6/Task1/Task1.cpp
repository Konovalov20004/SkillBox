#include <iostream>
#include <string>

using namespace std;

bool compare(double value, double reference, double epsilon) {
	return ((value >= reference - epsilon) && (value <= reference + epsilon));
}

float enter_delta() {
	float delta{};
	while (true) {
		cin >> delta;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max() || '\n');
		}
		else { return delta; }
	}
}

int main() {
	float speed{ 0 }, delta{};
	char speedsum[5];
	do {
		cout << "Speed delta >> ";
		delta = enter_delta();
		if (speed + delta > 150.0f) {
			cout << "Value too high" << endl;
		}
		else {
			speed += delta;
			speed < 0 ? speed = 0 : speed;
			sprintf_s(speedsum, "%.1f", speed);
			cout <<"Speed: " << speedsum << endl;
		}
	} while (!compare(speed, 0 ,0.01));
	return 0;
}