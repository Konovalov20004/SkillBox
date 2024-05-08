#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

enum Dish{pizza,soup,steak,salad = 4,sushi = 8};

int count_delivery{8};
vector<Dish> list;
vector<Dish> line;
mutex line_access;
mutex list_access;

void courierf() {
	while (true) {
		while (list.size() == 0) {}
		list_access.lock();
		list.clear();
		list_access.unlock();
		cout << "Delivery has started" << endl;
		this_thread::sleep_for(chrono::seconds(30));
		cout << "Delivery has end" << endl;
		count_delivery++;
	}
}

void kitchenf() {
	while (true) {
	while(line.size() == 0) {}
	line_access.lock();
	int count = line.size();
	Dish dish = line[0];
	line.insert(line.begin(), line.begin()+1, line.end());
	line.resize(count);
	line_access.unlock();
	srand(time(nullptr));
	cout << "Cooking has started" << endl;
	this_thread::sleep_for(chrono::seconds((rand() % 10) + 5));
	cout << "Cooking has end" << endl;
	list_access.lock();
	list.push_back(dish);
	list_access.unlock();
	}
}

void waiter(Dish dish) {
	line_access.lock();
	line.push_back(dish);
	line_access.unlock();
	cout << "Order is accepted" << endl;
}

void generic_order() {
	while (true) {
		Dish dish = (Dish)(rand() % 5);
		waiter(dish);
		this_thread::sleep_for(chrono::seconds((rand() % 5) + 5));
	}
}

int main()
{
	srand(time(nullptr));

	thread kitchen(kitchenf);
	kitchen.detach();
	thread courier(courierf);
	courier.detach();
	thread order(generic_order);
	order.detach();

	while (count_delivery < 10) {
	}
	return 0;
}
