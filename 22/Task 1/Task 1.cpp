#include <iostream>
#include <map>
#include <string>

using namespace std;

void add_contact(multimap<string, string>& a, string key, string word);
void read_contact(multimap<string, string>& a, string found_data);

void enter(multimap<string, string>& a) {
    string data{}, key{}, word{};
    while (true) {
        getline(cin, data);
        if (cin.fail()) {
            cerr << "Error data" << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (data.find(' ') != data.npos) {
            int itr = data.find(' ');
            key = data.substr(0, itr);
            word = data.substr(++itr, data.size() - itr);
            add_contact(a, key, word);
            break;
        }
        else {
            read_contact(a, data);
            break;
        }
    }
}
void add_contact(multimap<string, string>& a, string key, string word) {
    if (!word.empty() && !key.empty()) {
        pair<string, string> one(key, word);
        a.insert(one);
        pair<string, string> tmp(word, key);
        a.insert(tmp);
    }
    else
        cout << "Incomplite data" << endl;
}

 void read_contact(multimap<string, string>& a, string found_data) {
        if (a.count(found_data) > 0) {
            auto s = a.equal_range(found_data);
            for (auto& i = s.first; i != s.second; i++) {
                cout << i->first << ' ' << i->second << endl;
            }
        }
        else {
            multimap<string, string>::iterator it = a.find(found_data);
            cout << found_data << ' ' << it->second << endl;
        }
}

int main()
{
    multimap<string, string> phonebook;
    
    string command;

    while (true) {
        enter(phonebook);
    }
}

