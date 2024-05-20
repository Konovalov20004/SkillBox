#include <iostream>
#include <string>
#include <limits>
#include <cpr/cpr.h>

enum command {
    Get,Delete,Post,Put,Patch,Exit
};

command get_command() {
    std::string com;
    while (true) {
        std::cin >> com;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cerr << "Error" << std::endl;

            std::cin.clear();
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (com == "get")
            return Get;
        if (com == "patch")
            return Patch;
        if (com == "put")
            return Put;
        if (com == "post")
            return Post;
        if (com == "delete")
            return Delete;
        if (com == "exit")
            return Exit;
    }
}

int main(int argc, char** argv) {
    command result{};
    cpr::Response d{};

    while (true) {
        result = get_command();
        switch (result) {
        case Get:
            d = cpr::Get(cpr::Url{ "https://httpbin.org/get" });
            break;
        case Patch:
            d = cpr::Patch(cpr::Url{ "https://httpbin.org/patch" });
            break;
        case Put:
            d = cpr::Put(cpr::Url{ "https://httpbin.org/put" });
            break;
        case Post:
            d = cpr::Post(cpr::Url{ "https://httpbin.org/post" });
            break;
        case Delete:
            d = cpr::Delete(cpr::Url{ "https://httpbin.org/delete" });
            break;
        case Exit:
            std::exit(0);
        }
       std::cout << d.text << std::endl;
    }
    return 0;
}