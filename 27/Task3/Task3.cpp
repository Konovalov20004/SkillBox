#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Branch {
private:
	pair<int, int> count{3,5};
	pair<int, int> branch_on_branch{ 2,3 };
	string name_elf;
	vector<Branch*> branches;

public:
	Branch() {
	}

	void create_tree() {
		for (int i = 0; i < (rand() % (count.second - count.first + 1) + count.first); i++) {
			Branch* branch = new Branch();
			branch->check_in();
			branch->create_branch();
			branches.push_back(branch);
		}
	}

	int search_elf(string search_name) {
		for (auto el : branches) {
			if (el->name_elf == search_name) return count_neighbours();
			for(auto v : el->branches)
				if (v->name_elf == search_name) return count_neighbours();
		}
	}

	int count_neighbours() {
		int count{};
		for (auto v : branches) {
			if (v->name_elf != "none")
				count++;
		}
		return count;
	}

	void check_in() {
		string name;
		cout << "Enter name elf" << endl;
		cin >> name;
		name_elf = name;
	}

	void create_branch() {
		for (int i = 0; i < rand() % (branch_on_branch.second - branch_on_branch.first + 1) + branch_on_branch.first; i++) {
			Branch* branch = new Branch();
			branch->check_in();
			if(branch->name_elf != "none")
				branches.push_back(branch);
		}
	}
};

class BranchS : public Branch {
};

int main()
{
	string name;

	vector<Branch*> trees;

	for (int i = 0; i < 1; i++) {
		Branch* branch = new Branch();
		branch->create_tree();
		trees.push_back(branch);
	}

	cin >> name;
	int search{};
	for (auto v : trees) {
		search = v->search_elf(name);
	}

	cout << "Elf have " << search << " neighbours" << endl;

	return 0;
}
