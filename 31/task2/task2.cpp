#include <iostream>

class Toy {
private:
public:
    std::string name;
    Toy(std::string _name): name(_name){}
    Toy() : name("Sometoy") {};

    ~Toy() {
        std::cout << "Toy " << name << " was dropped" << std::endl;
    }
};

class shared_ptr_toy {
private:
    Toy* toy;
    int count{};
    int* countPtr = &count;
public:
    shared_ptr_toy(std::string _name) {
        (*countPtr)++;
        toy = new Toy(_name);
    }

    shared_ptr_toy(const shared_ptr_toy& other) {
        toy = other.toy;
        countPtr = other.countPtr;
        (*countPtr)++;
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other) {
        if (this == &other)
            return *this;
        toy = other.toy;
        (*countPtr)--;
        countPtr = other.countPtr;
        (*countPtr)++;
        return *this;
    }

    std::string getToyName() const {
        if (toy != nullptr)
            return toy->name;
        return "Noting";
    }

    int use_count() const {
        return *countPtr;
    }

    void reset() {
        toy = nullptr;
        (*countPtr)--;
    }

    Toy* get() const {
        return toy;
    }

    ~shared_ptr_toy() {
        (*countPtr)--;
        if(*countPtr <= 0)
            delete toy;
    }
};

shared_ptr_toy make_shared_toy(std::string _name) {
    shared_ptr_toy a(_name);
    return a;
}

int main() {
    shared_ptr_toy toy_01 = make_shared_toy("ball");
    shared_ptr_toy toy_02(toy_01);
    shared_ptr_toy toy_03("duck");
    std::cout << "=================================================" << std::endl;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
        << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
        << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
    toy_02 = toy_03;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
        << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
        << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
    toy_01.reset();
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
        << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
      << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
    return 0;
}
