#include <iostream>
#include <exception>
#include <random>
#include <ctime>

enum value{none,fish,boot};

class FishingDone :public std::exception {
    const char* what() const noexcept override {
        return "Caught a fish";
    }
};

class FishingFail :public std::exception {
    const char* what() const noexcept override {
        return "Caught a boot";
    }
};

class Field {
private:
public:
    value sectors[9]{none};

    Field() {
        srand(time(nullptr));
        sectors[rand() % 9] = fish;
        for (int i = 0,s=0; i < 3; i++) {
            s = rand() % 9;
            if (sectors[s] != fish)
                sectors[s] = boot;
            else
                i--;
        }
    }

    void cast(int s){
        if (sectors[s] == none)
            return;
        if (sectors[s] == fish)
            throw FishingDone();
        if (sectors[s] == boot)
            throw FishingFail();
    }
};



int main()
{
    int enter{}, count_cast{};
    Field See;
    while (true) {
        std::cin >> enter;
        count_cast++;
        try {
            See.cast(enter);
        }
        catch (const std::exception& x) {
            std::cout << x.what() << "\nCount: " << count_cast << std::endl;
            if (x.what() == "Caught a fish")
                exit(0);
        }
    }
    
}


