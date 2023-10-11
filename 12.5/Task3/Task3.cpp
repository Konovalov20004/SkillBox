#include <iostream>
#include <cassert>

using namespace std;

float travelTime(float &distance, float &speed) {
    assert(speed > 0);
    float time = distance / speed;
    return time;
}

int main()
{
    float speed{}, distance{};
    cin >> distance >> speed;
    cout << travelTime(distance, speed);
}

