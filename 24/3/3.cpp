#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main()
{
	time_t tim = time(nullptr);
	tm* timl = localtime(&tim);
	cin >> get_time(timl, "%M:%S");
	int sec = timl->tm_min * 60 + timl->tm_sec;
  	for (; sec > 0; sec--) {
		time_t tmp = sec;
		tm* tmpl = localtime(&tmp);
		cout << put_time(tmpl, "%M:%S\n");
		Sleep(990);
	}
	cout << "DING! DING! DING!";
}
