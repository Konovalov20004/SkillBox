#include <iostream>
#include <thread>
#include <string>
#include <map>
#include <mutex>
#include <ctime>
#include <vector>

using namespace std;

map<double, string> list;
mutex list_access;


class Swimmer {
public:
	string name;
	int speed;
	double time;

	Swimmer() {
		cin >> name;
		cin >> speed;
		time = 100 / (double)speed;
	}

	void start() const {
		for (int i = 0; i <= 100; i += speed) {
			cout << this->name << ": " << i << endl;
			this_thread::sleep_for(chrono::seconds(1));
		}
		cout << this->name << ": " << 100 << endl;
		pair<double, string> swim{time,name};
		list_access.lock();
		list.insert(swim);
		list_access.unlock();
	}
};

void Start(Swimmer* a) {
	a->start();
}

void place() {
	for (map<double, string>::iterator it = list.begin(); it != list.end(); it++) {
		cout << "Time: " << it->first << "\nName: " << it->second << endl;
	}
}

int main()
{
	vector<Swimmer*> tmp;
	for (int i = 0; i < 6; i++) {
		Swimmer* a = new Swimmer;
		tmp.push_back(a);
	}

	thread first(Start, tmp[0]);
	first.detach();
	this_thread::sleep_for(5ms);
	thread second(Start, tmp[1]);
	second.detach();
	this_thread::sleep_for(5ms);
	thread three(Start, tmp[2]);
	three.detach();
	this_thread::sleep_for(5ms);
	thread fourth(Start, tmp[3]);
	fourth.detach();
	this_thread::sleep_for(5ms);
	thread fifth(Start, tmp[4]);
	fifth.detach();
	this_thread::sleep_for(5ms);
	thread sixth(Start, tmp[5]);
	sixth.detach();

	while (list.size() != 6)
		this_thread::sleep_for(1000ms);

	place();
	return 0;
}

