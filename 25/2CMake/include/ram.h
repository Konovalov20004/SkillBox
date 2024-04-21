#pragma once

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void write();

void write(vector<int> a);

vector<int> read();

void display(int const SIZE = 8);

void save(int const SIZE = 8);

void load(int const SIZE = 8);

void compute();