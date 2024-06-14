#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>

struct InfoFilm {
	std::string name = "DeadPool";
	std::string country{"USA"};
	std::string date{"2018"};
	std::string studio{"20 Century Fox"};
	std::string scriptwriter{"Rett Riz"};
	std::string director{"Tim Miller"};
	std::string producer{"Ryan Reynolds"};
	std::multimap<std::string, std::string> actors{ {"DeadPool", "Ryan Reynolds"},{"Vanessa","Morena Baccarin"},{"Gina Carano", "Angel Dust"}};
};

int main() {
	InfoFilm DeadPool;

	nlohmann::json film{ {"nameFilm", DeadPool.name},
		{"country", DeadPool.country},
		{"date", DeadPool.date},
		{"studio", DeadPool.studio},
		{"scriptwriter", DeadPool.scriptwriter},
		{"director", DeadPool.director},
		{"producer", DeadPool.producer},
		{"actors", DeadPool.actors}
	};

	std::ofstream file("DeadPool.json");
	file << film;

	return 0;
}