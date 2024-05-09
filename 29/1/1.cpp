#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Talent {
public:
	virtual void talent() = 0;
};

class Swimming : virtual public Talent {
public:
	virtual void talent() {
		cout << "Smimm" << endl;
	}
};

class Dancing : virtual public Talent {
public:
	virtual void talent() {
		cout << "Dancing" << endl;
	}
};

class Counting : virtual public Talent {
public:
	virtual void talent() {
		cout << "Counting" << endl;
	}
};

class Animal {
public:
	virtual void Voice() = 0;
};

class Dog: virtual public Animal {
public:
	virtual void Voice() {
		cout << "Bark" << endl;
	}

	virtual void ShowTalent() = 0;
};

class BritDog: virtual public Dog {
public:
	virtual void ShowTalent() {
		const int countTalants{ 3 };
		Talent* talents[countTalants];
		talents[0] = new Swimming;
		talents[0]->talent();
	}
};

int main()
{
	Dog* Brit = new BritDog();
	Brit->ShowTalent();
}

