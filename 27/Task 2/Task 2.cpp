#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

enum Task_type { none, A, B, C };
string Task_name[]{ "none","A", "B", "C" };

class Employee {
public:
	string name;
	Employee(string inName) :name(inName) {
	}
};

class Manager;

class Head :public Employee {
public:
	vector<Manager*> teams;

	Head(string inName) :Employee(inName) {
	}

	void create_team(Manager* team) {
		teams.push_back(team);
	}
};

class Team;
class Worker;

class Manager :public Employee {
public:
	Team* team = nullptr;
	Manager(string inName, Team* inTeam) :Employee(inName) {
		team = inTeam;
	}

	void assign_task(int task);
};

class Worker : public Employee {
public:
	Task_type task = none;
	bool status{ false };
	Worker(string inName) :Employee(inName) {
	}

	void change_status(int inType) {
		if (!status) {
			status = true;
			task = (Task_type)inType;
			cout << name << " type task: " << Task_name[(int)task] << endl;;
		}
	}
};


class Team {
public:
	int id, size;
	Manager* manager = nullptr;
	vector<Worker*> workers;

	Team(int inSize_team, int inId) {
		size = inSize_team;
		id = inId;
		for (int i = 0; i < size; i++) {
			string name;
			cout << "Enter name worker" << endl;
			cin >> name;
			workers.push_back(new Worker(name));
		}
	}

	int index_free() {
		for (int i = 0; i < workers.size(); i++) {
			if (!workers[i]->status)
				return i;
		}
		return size;
	}

};

void Manager::assign_task(int task) {
	srand(team->id + task);
	for (int i = team->index_free(), c = rand() % team->size; i < team->size; i++) {
		if (team->size == 1)
			c = rand() % 2;
		if (c != 0) {
			team->workers[i]->change_status((rand() % 4) + 1);
			c--;
		}
		else
			return;
	}
}


int main() {
	int count_team, size_team;
	cout << "Count team" << endl;
	cin >> count_team;
	cout << "Size team" << endl;
	cin >> size_team;

	cout << "Enter name head" << endl;
	string name{};
	cin >> name;
	Head* head = new Head(name);

	for (int i = 0; i < count_team; i++) {
		Team* team = new Team(size_team, i);
		cout << "enter name manager" << endl;
		cin >> name;
		team->manager = new Manager(name, team);
		head->create_team(team->manager);
	}
	int count_busy_team{};
	 do {
		 int command;
		 cout << "Enter command" << endl;
		 cin >> command;
		 for (int i = 0; i < head->teams.size(); i++) {
			 Manager* manager = head->teams[i];
			 manager->assign_task(command);
		 }

		 count_busy_team = count_team;
		 for (int i = 0; i < head->teams.size(); i++) {
			 Manager* manager = head->teams[i];
			 count_busy_team -= manager->team->index_free();
		 }
	 } while (count_busy_team != 0);

	return 0;
}