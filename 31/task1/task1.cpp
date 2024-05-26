#include <iostream>
#include <string>

class Toy {
public:
    std::string name;

    Toy(std::string _name) : name(_name) {};
    Toy():name("Ball") {};
    ~Toy() {
        std::cout << "Toy " << name << " was dropped " << std::endl;
    }
};

class Dog {
private:
    std::shared_ptr<Toy> toy;
    std::string name;
    int age;
public:

    Dog(std::string _name, std::shared_ptr<Toy> _toy, int _age) :name(_name),toy(_toy), age(_age) {};
    Dog() : Dog("Pushok", nullptr , 4) {};

    void getToy(std::shared_ptr<Toy> nameToy) {
        if (toy == nameToy)
            std::cout << "I already have this toy" << std::endl;
        else if (nameToy.use_count() > 2)
            std::cout << "Another dog is playing with this toy" << std::endl;
        else
            toy = nameToy;
    }

    void dropToy() {
        if (toy)
            toy.reset();
        else
            std::cout << "Nothing to drop" << std::endl;
    }
};

int main()
{
    std::shared_ptr<Toy> ball = std::make_shared<Toy>("ball");
    std::shared_ptr<Toy> bone = std::make_shared<Toy>("bone");
    std::cout << bone.use_count() << std::endl;
    std::cout << ball.use_count() << std::endl;

    Dog a;
    Dog b("Pushok", ball, 10);

    b.dropToy();
    std::cout << "========" << std::endl;
    a.getToy(ball);
    b.getToy(bone);
    std::cout << bone.use_count() << std::endl;
    std::cout << ball.use_count() << std::endl;

}

