#include <iostream>

using namespace std;

struct buildings {
    int s{};
    bool furnance{};
};

struct room {
    int h{};
    int s{};
};

struct stage {
    int coutn_room{};
    room livin_room;
    room bedroom;
    room kidsroom;
    room bath;
    room kithen;
};

struct house_in {
    int s{};
    int coutn_stage{};
    bool furnance{};

    stage one;
    stage two;
    stage three;
};

struct ground {
    int s{};
    
    house_in home;
    buildings bathhouse;
    buildings barn;
    buildings garage;
};

int main()
{
    ground first;
    first.s = 100;
    first.barn.s = 10;
    first.bathhouse.furnance = true;
    first.bathhouse.s = 15;
    first.garage.s = 20;
    first.home.furnance = true;
    first.home.coutn_stage = 2;
    first.home.one.kithen.h = 2;
    first.home.one.kithen.s = 12;
    
}
