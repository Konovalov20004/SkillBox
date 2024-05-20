#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    cpr::Response r = cpr::Get(cpr::Url{ "https://httpbin.org/html" },
                      cpr::Header{{"accept", "text/html"}});
    std::string head  = r.text.substr(r.text.find("<h1>") + 4, r.text.find("</h1>") - r.text.find("<h1>") - 4);
    std::cout << head << std::endl;
    return 0;
}