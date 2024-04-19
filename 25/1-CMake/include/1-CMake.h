#pragma once

#include <iostream>

struct point {
	double a{};
	double b{};
};
struct step {
	point a;
	point b;
};

void scalpel(point a, point b) {
	std::cout << "Cut between: a(" << a.a << ", " << a.b << "), b(" << b.a<< ", " << b.b << ")" << std::endl;
}

void hemostat(point a) {
	std::cout << "Hemostat apiled to (" << a.a << ", " << a.b << ") " << std::endl;
}

void tweezers(point a) {
	std::cout << "tweezers apiled to (" << a.a << ", " << a.b << ") " << std::endl;
}

void suture(point a, point b) {
	std::cout << "Wired between: a(" << a.a << ", " << a.b << "), b(" << b.a << ", " << b.b << ")" << std::endl;
}

point enter() {
	point a;
	double coordX, coordY;
	while (true) {
		std::cin >> coordX;
		std::cin >> coordY;
		if (std::cin.fail() || std::cin.peek() != '\n') {
			std::cerr << "Error" << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}
		break;
	}
	a.a = coordX;
	a.b = coordY;
	return a;
}