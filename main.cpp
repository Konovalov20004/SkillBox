#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <memory>
#include <filesystem>
#include <list>
#include <string>

void task1() {

    std::vector<int> a{ 1,2,3,4,5 };
    for (auto v : a)
        std::cout << v << " ";

}

auto task2 {[] (std::vector<int> arr) {
    std::unordered_set<int> a;
    for(auto el:arr) {
        a.insert(el);
    }
    std::vector<int> result;
    for(auto el:a)
        result.push_back(el);
    return std::make_unique<std::vector<int>>(result);
}};

namespace fs = std::filesystem;
auto workFile{ [] (fs::path somePath, std::string const  someExtension) {
    std::list<fs::path> listExtension;
    for(auto& entry_dir: fs::recursive_directory_iterator(somePath)){
        if(!entry_dir.path().extension().compare(someExtension))
            listExtension.emplace_back(entry_dir.path().filename());
    }
    return listExtension;
}};

int main()
{

    for(auto v:workFile("C:/Users/Sergey/Desktop/C++/Learn/SkillBox/Qt/untitled", ".cpp"))
        std::cout << v<<std::endl;

    return 0;
}
