#include "CMakeProject1.h"

using namespace std;

class Track {
public:
	string name{};
	tm* date{};
	tm length{};

	void createNew() {
		cout << "Enter name song" << endl;
		cin >> name;
		time_t now = time(nullptr);
		date = localtime(&now);
		srand(time(nullptr));
		int timeTrack = rand() % 300;
		if (timeTrack < 110)
			timeTrack += 110;
		length.tm_sec = timeTrack % 60;
		length.tm_min = timeTrack / 60;
	}

	bool check() {
		if (name.empty())
			return 0;
		return 1;
	}
	friend string enter();
};

class Pleer {
private:
	vector<Track> list;
	Track nowPlay;
	string status{ "Pause" };
	int max_number_song{3};
public:
	void command(string com) {
		if (com == "play" && status == "Pause")
			Play();
		if (com == "pause" && status == "Play")
			status = "Pause";
		if (com == "next")
			Next();
		if (com == "exit")
			exit(0);
		Playing();
	}
	void Play() {
		Track input;
		input.createNew();
		nowPlay = input;
		list.push_back(input);
		status = "Play";
	}

	void Next() {
		srand(time(nullptr));
		int count_song = list.size();
		int next = rand() % max_number_song;
		if (next >= count_song)
			Play();
		else
			nowPlay = list[next];
	}

	void Playing() {
		cout << status << " now: " << nowPlay.name << " " << get_time(&nowPlay.length, "%M:%S") << endl;
		cout << "Track created " << get_time(nowPlay.date, "%c") << endl;
	}
};

string enter() {
	string data;
	while (true) {
		cin >> data;
		if (cin.fail() || cin.peek() != '\n') {
			cerr << "Error" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			continue;
		}
		return data;
	}
}

int main()
{
	Pleer pleer;
	string command;
	while (true) {
		cout << "Enter command" << endl;
		cin >> command;
		pleer.command(command);
	}
	return 0;
}
