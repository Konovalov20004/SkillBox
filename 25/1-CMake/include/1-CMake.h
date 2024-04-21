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

void scalpel(point a, point b);
void hemostat(point a);
void tweezers(point a);
void suture(point a, point b) ;
point enter();