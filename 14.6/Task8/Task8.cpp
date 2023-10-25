#include <iostream>
#include <string>
#include <numeric>
#include <limits>
#include <assert.h>

int deployment(bool field[10][10], int* coord, int* area);
using namespace std;

void enter_coord(bool a[10][10], int* coord, int& SIZEcoord) {
	int value{};
begin:
	cout << "Enter coordinate: " << endl;
	for (int i = 0; i < SIZEcoord; i++) {
		cin >> value;
		if (value < 0 || value > sizeof(a[0])) {
			cout << "Values are out of bounds. Max values - " << sizeof(a[0]) - 1 << " \nMin values - 0." << endl;
			goto begin;
		}
		else {
			coord[i] = value;
		}
	}
}

int single_deck(bool a[10][10]) {
	int coord[2]{}, area[4]{}, size = 2;
	enter_coord(a, coord, size);
	for (int i = 0; i < sizeof(coord) / sizeof(coord[0]); i++) {
		if (coord[i] == 0) {
			area[i] = coord[i];
			area[i + 2] = coord[i] + 1;
			continue;
		}
		if (coord[i] == 9) {
			area[i] = coord[i] - 1;
			area[i + 2] = coord[i];
			continue;
		}
		area[i] = coord[i] - 1;
		area[i + 2] = coord[i] + 1;
	} 
	return deployment(a, coord, area);
}

int  any_deck(bool a[10][10], int numberDeck) {
	int coord[4]{}, area[4]{}, size = 4;
	--numberDeck;
	cout << "Coordinate view: x x x x." << endl;
	enter_coord(a, coord, size);
	while (true) {
		if (coord[2] > coord[0] && coord[3] > coord[1]) {
			cout << "The ship must occupy either a horizontal or a vertical." << endl;
			enter_coord(a, coord, size);
		}
		if ((coord[2] - coord[0] == numberDeck && coord[3] - coord[1] != numberDeck) &&
			(coord[2] - coord[0] != numberDeck && coord[3] - coord[1] == numberDeck)) {
			cout << "The number of decks does not match" << endl;
			enter_coord(a, coord, size);
		}
		else { break; }
	}
	for (int i = 0; i < sizeof(coord) / sizeof(coord[0]); i++) {
		if (coord[i] == 0 && i < 2) {
			area[i] = coord[i];
			continue;
		}
		if (coord[i] == 9 && i > 1) {
			area[i] = coord[i] - 1;
			continue;
		}
		i < 2? area[i] = coord[i] - 1 : area[i] = coord[i] + 1;
	}
	return deployment(a, coord, area);
}

int deployment(bool field[10][10], int* coord, int* area) {
	for (int i = area[0]; i < area[2]; i++) {
		for (int j = area[1]; j < area[3]; j++) {
			if (!field[i][j]) return 1;
		}
	}
	if (sizeof(coord) / sizeof(coord[0]) == 2) {
		field[coord[0]][coord[1]] = false;
		return 0;
	}
	for (int i = coord[0]; i < coord[2]; i++) {
		for (int j = coord[1]; j < coord[3]; j++) {
			field[i][j] = false;
		}
	} return 0;
}

int ship(bool a[10][10]) {
	int choice{1}, count_ship[4]{4, 3, 2, 1};
	for (int i = 10; ; i--) {
		cout << "Left to position: " << count_ship[0] << " - single-deck, " << count_ship[1]<< " - dooble-deck, "
			<< count_ship[2] << " - three-deck, " << count_ship[3] << " - four - deck." << endl;
		cout << "Choose which ships to deploy: 1 - single-deck, 2 - dooble-deck," <<
			" 3 - three-deck, 4 - four-deck:" << endl;
		while (true) {
			cin >> choice; 
			if (choice < 1 || choice > 4) {
				cout << "Incorrect value. Try one more." << endl;
			}
			else if (choice == 1 && count_ship[0] == 0 || choice == 2 && count_ship[1] == 0 ||
				choice == 3 && count_ship[2] == 0 || choice == 4 && count_ship[3] == 0) {
				cout << "Ships of this type are located" << endl;
			}
			else { break; }
		}
		begin_ship:
		if (choice == 1) {
			if (single_deck(a)) { 
				cout << "Place not a free. Enter another coordinates" << endl;
				goto begin_ship; 
			}
		}
		else {
			if (any_deck(a, choice)) {
				cout << "Place not a free. Enter another coordinates" << endl;
				goto begin_ship;
			}
		}
		count_ship[choice - 1]--;
	}
	cout << "Ships on the ground." << endl;
	return 0;
}

int shot(bool field[10][10]) {
	int coord[2]{}, size = 2;
	enter_coord(field, coord, size);
	if (!field[coord[0]][coord[1]]) {
		return 1;
	}
	else {
		return 0;
	}

}

int core() {
	bool fieldFirstPlayer[10][10];
	bool fieldSecondPlayer[10][10];
	int countShot[2]{10, 10};
	cout << "Ship deploy First player: " << endl;
	ship(fieldFirstPlayer);
	cout << "Ship deploy Second player: " << endl;
	ship(fieldSecondPlayer);
	while (true) {
		cout << "The first player shoots" << endl;
		if (shot(fieldSecondPlayer)) {
			cout << "Got it!" << endl;
			countShot[1]--;
		}
		else {
			cout << "Miss!" << endl;
		}
		if (!countShot[1]) { return 1; }
		cout << "The second player shoots" << endl;
		if (shot(fieldFirstPlayer)) {
			cout << "Got it!" << endl;
			countShot[0]--;
		}
		else {
			cout << "Miss!" << endl;
		}
		if (!countShot[1]) { return 2; }
	}
}

int main()
{
	cout << "Game start" << endl;
	cout << "Won " << core() << " player" << endl;
}
