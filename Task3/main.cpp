#include <iostream>
#include <string>
#include <cpr/cpr.h>


int main() {
    std::string arg, name,value;
    std::multimap<std::string, std::string> arguments;
    std::vector<cpr::Pair> arr;

    while (true) {
        std::getline(std::cin, arg);
        std::cin.clear();

        name = arg.substr(0, arg.find(' '));
        value = arg.substr(arg.find(' ') + 1, arg.size() - arg.find(' ') - 1);
        if (name == "post" || name == "get" || value == "post" || value == "get") {
            (name == "post" || value == "post") ? (arg = "post") : (arg = "get");
            break;
        }
        cpr::Pair p(name, value);
        arr.emplace_back(p);
    }

    if (arg == "get") {
        arg = "?";
        for (auto v : arr) {
            arg += v.key + "=" + v.value + "&";
        }
        cpr::Response r = cpr::Get(cpr::Url("https://httpbin.org/get" + arg));
        std::cout << r.text << std::endl;
    }
    else {
        arg = "";
        std::vector<cpr::Pair>::iterator begin = arr.begin();
        std::vector<cpr::Pair>::iterator end = arr.end();
        cpr::Response r = cpr::Post(cpr::Url("https://httpbin.org/post"),
            cpr::Payload(begin, end));
        std::cout << r.text << std::endl;
    }
    
    return 0;
}