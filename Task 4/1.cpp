#include <iostream>
#include <execution>
#include <map>

std::map<std::string, int> bd;
std::map<std::string, int> basket;

void aded(std::string art, int c) {
    if (bd.find(art) == bd.end())
        throw std::invalid_argument("invalid argument");
    if (bd.find(art)->second < c)
        throw std::runtime_error("not match");
    std::pair<std::string, int> result(art, c);
    bd.find(art)->second -= c;
    if (basket.find(art) == basket.end())
        basket.emplace(result);
    else
        basket.find(art)->second += c;
}

void rem(std::string art, int c) {
    if (basket.find(art) == basket.end())
        throw std::invalid_argument("invalid argument");
    if (basket.find(art)->second < c)
        throw std::runtime_error("not match");
    std::pair<std::string, int> result(art, c);
    bd.find(art)->second += c;
    if (bd.find(art)->second == c)
        basket.erase(art);
    else
        basket.find(art)->second -= c;
}

int main()
{
    std::string data;
    int count{}; 

    for (int i = 0; i < 3; i++) {
        std::cin >> data;
        std::cin >> count;
        std::pair<std::string, int> a(data,count);
        bd.emplace(a);
    }

    while (true) {
        std::cin >> data;
        if (data == "add") {
            std::cin >> data;
            std::cin >> count;
            try {
                aded(data, count);
            }
            catch (const std::exception& c) {
                std::cerr << c.what() << std::endl;
            }
        }
        else if (data == "remove") {
            std::cin >> data;
            std::cin >> count;
            try {
                rem(data, count);
            }
            catch (const std::exception& c) {
                std::cerr << c.what() << std::endl;
            }
        }
        else
            std::cerr << "Command not found" << std::endl;

    }
}
