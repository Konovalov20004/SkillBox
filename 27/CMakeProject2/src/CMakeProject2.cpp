#include "CMakeProject2.h"

using namespace std;

struct Coord_center {
	double x;
	double y;
};

struct Size {
	double wide;
	double high;
};

struct Size_figure {
	double a;
	double b;
};

class Describe_Figure {
private:
	Size size{};
public:
	Describe_Figure(double inWide, double inHigh = 0) {
		if (inHigh != 0)
			size.high = inHigh + inHigh * 0.1;
		else
			size.high = inWide + inWide * 0.1;
		size.wide = inWide + inWide * 0.1;
	}

	Size get_size() {
		return size;
	}
};

class Figure {
protected:
	Coord_center center{};
	Size_figure size{};
	double square{};


public:
	Figure() {

	}
};

class Circle :public Figure {
private: 
	void set_square() {
		square = pow(size.a, 2) * size.b;
	}

	Describe_Figure set_borders() {
		Describe_Figure borders(2*size.a);
		return borders;
	}
public:
	Circle(double inA) {
		if (inA <= 0)
			assert(1);
		size.a = inA;
		size.b = atan(1) * 4;
		set_square();
		Describe_Figure borders = set_borders();
		cout << "Square figure = " << square << "\nDescribe figure (" 
			<< borders.get_size().high << ", " << borders.get_size().wide << ")" << endl;
	}
};

class Triangle :public Figure {
private:
	void set_square() {
		square = size.a * size.b;
	}

	Describe_Figure set_borders() {
		Describe_Figure borders(size.a);
		return borders;
	}
public:
	Triangle(double inA) {
		if (inA <= 0)
			assert(1);
		size.a = inA;
		size.b = size.a * sqrt(3)/4;
		set_square();
		Describe_Figure borders = set_borders();
		cout << "Square figure = " << square << "\nDescribe figure ("
			<< borders.get_size().high << ", " << borders.get_size().wide << ")" << endl;
	}
};

class Square :public Figure {
private:
	void set_square() {
		square = size.a * size.b;
	}

	Describe_Figure set_borders() {
		Describe_Figure borders(size.a);
		return borders;
	}
public:
	Square(double inA) {
		if (inA <= 0)
			assert(1);
		size.a = inA;
		size.b = size.a;
		set_square();
		Describe_Figure borders = set_borders();
		cout << "Square figure = " << square << "\nDescribe figure ("
			<< borders.get_size().high << ", " << borders.get_size().wide << ")" << endl;
	}
};

class Rectangle :public Figure {
private:
	void set_square() {
		square = size.a * size.b;
	}

	Describe_Figure set_borders() {
		Describe_Figure borders(size.a,size.b);
		return borders;
	}
public:
	Rectangle(double inA, double inB) {
		if (inA <= 0)
			assert(1);
		size.a = inA;
		size.b = inB;
		set_square();
		Describe_Figure borders = set_borders();
		cout << "Square figure = " << square << "\nDescribe figure ("
			<< borders.get_size().high << ", " << borders.get_size().wide << ")" << endl;
	}
};