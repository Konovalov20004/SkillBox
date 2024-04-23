#include "CMakeProject2.h"

using namespace std;

class Phone {
private:
	//int number{};
	multimap<string, string> phonebook_buf;

	string enter() {
		string tmp;
		while (true) {
			cin >> tmp;
			if (cin.fail() || cin.peek() != '\n') {
				cerr << "Error" << endl;

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				continue;
			}
			break;
		}
		return tmp;
	}

	bool check_file() {
		string path{ "C:/Users/Sergey/Desktop/C++/Learn/SkillBox/26/CMakeProject2/phonebook.bin" };
		ifstream file(path, ios::binary);
		if (!file.is_open()) {
			ofstream create_file(path, ios::binary);
			if (!file.is_open()) {
				cerr << "Eror to open file" << endl;
				return 1;
			}
			cout << "Phone book load" << endl;
			create_file.close();
		}
		file.close();
		return 0;
	}

	void save_phonebook() {
		string path{ "C:/Users/Sergey/Desktop/C++/Learn/SkillBox/26/CMakeProject2/phonebook.bin" };
		if(check_file())
			return;
		ofstream phonebook(path, ios::binary);
		int count;
		multimap<string, string>::iterator it = phonebook_buf.begin();
		for (int i = 0; i < phonebook_buf.size() / 2; i++) {
			phonebook << it->first;
			phonebook << " ";
			phonebook << it->second;
			if (i == phonebook_buf.size() / 2 - 1)
				phonebook << '\r';
			else
				phonebook << '\n';
			it++;
		}
		
		phonebook.close();
	}

	void load_phonebook() {
		string path{ "C:/Users/Sergey/Desktop/C++/Learn/SkillBox/26/CMakeProject2/phonebook.bin" };
		ifstream file(path, ios::binary);
		if(check_file())
			return;
		if (file.peek() == '\0' || file.peek() == 255 || file.peek() < 0 )
			return;
		while (true) {
			string name, number;
			file >> number;
			file >> name;
			pair<string, string> contact_key_name{ name,number };
			phonebook_buf.insert(contact_key_name);
			pair<string, string> contact_key_number{ number,name };
			phonebook_buf.insert(contact_key_number);
			
			if (file.peek() == '\r' )
				break;
		}
		file.close();
	}

	bool set_number() {
		string number, name;
		cout << "Enter number phone" << endl;
		number = enter();
		if (number.length() != 12 && number[0] != '+' && number[1] != '7') {
			cerr << "Invalid number format" << endl;
			return 1;
		}
		cout << "Enter name contact" << endl;
		name = enter();
		pair<string, string> contact_key_name{ name, number };
		pair<string, string> contact_key_number{ number, name };
		phonebook_buf.insert(contact_key_name);
		phonebook_buf.insert(contact_key_number);
		return 0;
	}

public:
	Phone() {
		load_phonebook();
		return;
	}

	void add() {
		if (!set_number()) {
			cout << "Contact add" << endl;
		}
	}

	void call() {
		string data;
		data = enter();
		multimap<string, string>::iterator contact;
		contact = phonebook_buf.find(data);
		if (contact == phonebook_buf.end()) {
			cout << "Contact not found" << endl;
			return;
		}
		cout << "Call:\n" << contact->first << "\n" << contact->second << endl;
	}

	void sms() {
		cout << "Enter data contact: name or number" << endl;
		string data, text;
		data = enter();
		multimap<string, string>::iterator contact;
		contact = phonebook_buf.find(data);
		if (contact == phonebook_buf.end())
			cout << "Contact not found" << endl;
		cout << "SMS:\n" << contact->first << '\n' << contact->second << endl;;
		cout << "Enter text sms: " << endl;
		text = enter();
		cout << "Send message" << endl;
	}

	void ex() {
		save_phonebook();
		exit(0);
	}

};
