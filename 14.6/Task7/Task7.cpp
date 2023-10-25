#include <iostream>

using namespace std;
void landscape_construction(bool matrix[5][5][10], const int x, const int y, const int z);

void enter_height(bool matrix[5][5][10]) {
    int height{};
    cout << "Enter height into view matrix:\n"
        << "a b c d e\n" << "a b c d e\n" << "a b c d e\n" << "a b c d e\n" << "a b c d e\n" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            onemore:
            cin >> height;
            if (height > 10 || height < 0) { 
                cout << "height cannot be more than 10 or less that 0"; 
                goto onemore; }
            landscape_construction(matrix, i, j, height);
        }
    }
}

void landscape_construction(bool matrix[5][5][10], const int x, const int y, const int z) {
    for (int i = 0; i < z; i++) {
        matrix[x][y][i] = 1;
    }
}

void show_layer(bool matrix[5][5][10]) {
    int layer_number{};
    cout << "Enter layer number (less 10 and more 0): " << endl;
    while (true) {
        cin >> layer_number;
        if (layer_number < 0 || layer_number > 10) {
            cout << "Try another value" << endl;
        } else {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j][layer_number - 1] << ' ';
        } cout << endl;
    }
}

int main()
{
    bool matrix[5][5][10]{};
    enter_height(matrix);
    while(true) { 
        show_layer(matrix);
    }
}
