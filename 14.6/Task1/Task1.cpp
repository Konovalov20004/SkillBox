#include <iostream>

using namespace std;

int main()
{
    int cutlery[2][6]{ {4, 3, 3, 3 ,3, 3}, 
                       {4, 3, 3, 3 ,3, 3} };
    int dishes[2][6]{ {3, 2, 2, 2, 2, 2},
                      {3, 2, 2, 2, 2, 2} };
    int chair[2][6]{ {1, 1, 1, 1, 1, 1}, 
                     {1, 1, 1, 1, 1, 1} };
    
    chair[0][4]++;
    cutlery[1][2]--;
    cutlery[0][0]--;
    cutlery[1][2]++;
    dishes[0][0]--;
}
