#include "CMakeProject3.h"

using namespace std;

struct SIZE_OBJ {
	int wide{};
	int high{};
};

struct coordinate {
	int x{};
	int y{};
};

struct COORD {
	coordinate left_up_angle{};
	coordinate left_down_angle{};
	coordinate right_up_angle{};
	coordinate right_down_angle{};
};

class Display {
private:
	SIZE_OBJ size_max{};
	SIZE_OBJ size_min{};

	void set_size(int w = 80, int h = 50) {
		size_min.high = 0;
		size_min.wide = 0;
		size_max.high = h;
		size_max.wide = w;
	}

public:
	Display() {
		set_size();
	}

	int get_wide() {
		return size_max.wide;
	}

	int get_high() {
		return size_max.high;
	}

	int get_min_wide() {
		return size_min.wide;
	}

	int get_min_high() {
		return size_min.high;
	}

};

class Window {
private:
	Display display{};
	COORD coord{};
	void set_coord(int wide = 10, int high = 10) {
		if (wide != 0 || high != 0) {
			coord.left_up_angle.x = 0;
			coord.left_up_angle.y = 0;
			coord.right_down_angle.x = wide;
			coord.right_down_angle.y = high;
		}
		coord.left_down_angle.x = coord.left_up_angle.x;
		coord.left_down_angle.y = coord.right_down_angle.y;
		coord.right_up_angle.x = coord.right_down_angle.x;
		coord.right_up_angle.y = coord.left_up_angle.y;
	}

	coordinate get_coord(string ind) {
		coordinate tmp;
		if (ind == "size") {
			tmp.x = coord.right_down_angle.x;
			tmp.y = coord.right_down_angle.y;
			return tmp;
	}
		if (ind == "locate") {
			tmp.x = coord.left_up_angle.x;
			tmp.y = coord.left_up_angle.y;
			return tmp;
		}
	}
	
	void check_borders(int x, int y) {
		if ((coord.left_up_angle.x + x) <= display.get_min_wide() ||
			coord.left_up_angle.y + y <= display.get_min_high() ||
			coord.right_down_angle.x + x >= display.get_high() ||
			coord.right_down_angle.y + y >= display.get_wide()) 
		{
			cerr << "out of borders" << endl;
			exit(3);
		}
	}

	void check_borders(int x, int y, int a) {
		if (x > display.get_wide() ||
			y > display.get_high())
		{
			cerr << "out of borders" << endl;
			exit(3);
		}
	}

public:
	Window() {
		set_coord();
	}

	void move(string direction, int x = 0, int y = 0) {
		if (direction.find("left") != direction.npos)
			x = -x;
		if (direction.find("up") != direction.npos)
			y = -y;

		check_borders(x, y);
		coord.left_up_angle.x += x;
		coord.left_up_angle.y += y;
		coord.right_down_angle.x += x;
		coord.right_down_angle.y += y;
		set_coord(0,0);

		cout << "New coord: a(" << coord.left_up_angle.x << ", " << coord.left_up_angle.y << "), \n" <<
			"b(" << coord.right_up_angle.x << ", " << coord.right_up_angle.y << "), \n" <<
			"c(" << coord.right_down_angle.x << ", " << coord.right_down_angle.y << "), \n" <<
			"d(" << coord.left_down_angle.x << ", " << coord.left_down_angle.y << "), \n" << endl;
	}

	void resize(int wide = 0, int high = 0) {
		check_borders(wide, high, 0);
		coord.right_down_angle.x = wide;
		coord.right_down_angle.y = high;
		set_coord(0, 0);

		cout << "New size: wide = " << wide << ", high = " << high << endl;
	}

	void out_window() {
		string str_window, str_display;
		int index{ coord.left_up_angle.x };
		int count{ coord.right_up_angle.x - coord.left_up_angle.x };
		str_window.insert(0, display.get_wide() - count, '0');
		str_window.insert(index, count, '1');
		str_display.insert(0, display.get_wide(), '0');
		for (int i = 0; i < display.get_high(); i++) {
			if (i >= coord.left_up_angle.y && i < coord.right_down_angle.y) {
				cout << str_window << endl;
			}
			else
				cout << str_display << endl;
		}
	}

	void close() {
		string str_display;
		str_display.insert(0, display.get_wide(), '0');
		for (int i = 0; i < display.get_high(); i++) {
			cout << str_display << endl;
		}
		exit(0);
	}
};