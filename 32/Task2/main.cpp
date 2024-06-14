#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>

int main() {
	std::string search_actor, film_name{}, role{};
	std::cin >> search_actor;
	nlohmann::json films;
	nlohmann::json actors;

	std::ifstream file;
	file.open("films.json");
	if (!file.is_open())
		std::cout << "File not open" << std::endl;
	file >> films;
	
	for (nlohmann::json::iterator v = films.begin(); v != films.end() ;v++) {
		if ((*v)["actors"].find(search_actor) != (*v)["actors"].end()) {
			film_name += v.key();
			role += *(*v)["actors"].find(search_actor);
		}
		film_name += ",";
		role += ",";
	}

	std::cout << "Film: " << film_name << "\nRole: " << role << std::endl;

	return 0;
}