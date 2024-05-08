#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
class Train;
vector<Train*> terminal;
mutex terminal_status;

enum Status {
    arrival,
    wait,
    departure
};

class Train {

public:
    Status status;
    char name;
    int time;

    Train(int time, char sym): time(time), name(sym) {
        status = arrival;
    }

    void on_terminal() {
        this_thread::sleep_for(chrono::seconds(this->time));
        string command;
        if (terminal_status.try_lock()) {
            cout << "Train " << name << " arrived on terminal" << endl;
            while (command != "depart") {
                cout << "Enter command train " << name << endl;
                cin >> command;
            }
            terminal_status.unlock();
            cout << "Train " << name << " departure on terminal" << endl;
            status = departure;
        }
        else if (status == wait)
            return;
        else {
            status = wait;
            this_thread::sleep_for(1ms);
            cout << "Train " << name << " wait on terminal" << endl;
        }
    }
};

void Start(Train* train) {
    while (true) {
        this_thread::sleep_for(chrono::seconds(1));
        train->on_terminal();
        if (train->status == departure) {
            terminal.push_back(train);
            break;
        }
    }
}

int main()
{
    const char names_train[]{ 'A', 'B', 'C' };
    vector<Train*> trains;
    for (int i = 0; i < sizeof(names_train) / sizeof(names_train[0]); i++) {
        int time;
        cin >> time;
        Train* train = new Train(time, names_train[i]);
        trains.push_back(train);
    }
    thread train_A(Start, trains[0]);
    train_A.detach();
    thread train_B(Start, trains[1]);
    train_B.detach();
    thread train_C(Start, trains[2]);
    train_C.detach();

    while (terminal.size() < (sizeof(names_train) / sizeof(names_train[0]))) {

    }  
}
