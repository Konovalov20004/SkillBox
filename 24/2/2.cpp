#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	multimap<string, string> list;
	string id, name;
	time_t now = time(nullptr);
	tm* lnow = localtime(&now);

	while (true) {
		cin >> name;
		if (name == "end")
			break;
		cin >> get_time(lnow, "%Y/%m/%d");
		if (lnow->tm_mon < 10)
			id += "0" + to_string(lnow->tm_mon) + '.';
		else
			id += to_string(lnow->tm_mon) + '.';
		if (lnow->tm_mday < 10)
			id += "0" + to_string(lnow->tm_mday);
		else
			id += to_string(lnow->tm_mday);
		pair<string, string> p{ id, name };
		list.insert(p);
		id = "";
	}

	tm* nowl = localtime(&now);
	id = "";
	if (nowl->tm_mon < 10)
		id += "0" + to_string(nowl->tm_mon) + '.';
	else
		id += to_string(nowl->tm_mon) + '.';
	if (nowl->tm_mday < 10)
		id += "0" + to_string(nowl->tm_mday);
	else
		id += to_string(nowl->tm_mday);

	if (list.find(id) != list.end()) {
		string date_br = list.find(id)->first;
		int month = stoi(date_br.substr(0, 2));
		int day = stoi(date_br.substr(3, 2));
		cout << "today birthday!!!" << " " << list.find(id)->second << endl;
	}
	else {
		pair<string, string> today{ id,"today" };
		list.insert(today);
		multimap<string, string>::iterator it = list.lower_bound(id);
		if (it == list.end()) {
			cout << "This year not birthday" << endl;
		}
		it++;
		string date_br = it->first;
		int month = stoi(date_br.substr(0, 2));
		int day = stoi(date_br.substr(3, 2));
		cout << month << '/' << day << " " << it->second << endl;
	}
}
