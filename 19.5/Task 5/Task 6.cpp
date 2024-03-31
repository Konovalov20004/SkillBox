#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool numer_quest[13] = {};
int marker = 0;
int score[2]{};

int check_numer() {
    int tmp;
    while (true) {
        cin >> tmp;
        if (cin.fail() || cin.peek() != '\n') {
            cerr << "Ошибка данных" << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    marker += tmp;
    while (numer_quest[marker]) {
            marker++;
    }
    numer_quest[marker] = true;
    return marker + 1;
}

string check_ans() {
    string data{};
    while (true) {
        cin >> data;
        if (cin.fail() || cin.peek() != '\n') {
            cerr << "Ошибка данных" << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    return data;
}

void quest(int choice) {
    string patch_q = "D:/" + to_string(choice) + "/quest.txt" ;
    fstream question;
    question.open(patch_q);

    string patch_a = "D:/" + to_string(choice) + "/answer.txt";
    fstream answer;
    answer.open(patch_a);
    string _answer;
    answer >> _answer;

    while (!question.eof()) {
        string tmp;
        question >> tmp;
        cout << tmp + " ";
    }
   
    cout << "Enter answer" << endl;
    if (_answer == check_ans())
        score[0]++;
    else
        score[1]++;

    question.close();
    answer.close();

}

int main()
{
    while (true) {
        cout << "Peek number" << endl;
        int choice = check_numer();
        quest(choice);
        if (score[0] == 6) {
            cout << "Win znatoki" << endl;
            break;
        }
        if (score[1] == 6) {
            cout << "Win zriteli" << endl;
            break;
        }
    }
    cout << "Thanks for games" << endl;
}