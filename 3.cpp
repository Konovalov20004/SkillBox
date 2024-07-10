#include <iostream>

template<typename T>
class Value {
private:
	int Size{0};
	T* ar = new T [1];
public:
	Value(){
	}

	void add(T a) {
		T* newAr = new T[Size + 1];
		for (int i = 0; i < Size; i++) {
			newAr[i] = ar[i];
		}
		newAr[Size] = a;
		Size++;
		delete[] ar;
		ar = new T[Size];
		for (int i = 0; i < Size; i++) {
			ar[i] = newAr[i];
		}
		delete[] newAr; 
	}

	T operator[] (int i) {
		return ar[i];
	}

	int const size() {
		return Size;
	}


	void Clear() {
		delete[] ar;
	}
};

template<typename Key, typename val>
struct el {
	Key key;
	Value<val> value;
	
	el(Key a, val c){
		key = a;
		value.add(c);
	}
	el() {
		Key v;
		std::cin >> key >> v;
		value.add(v);
	}
	el(int a) {
		std::cin >> key;
	}

	~el() {
		value.Clear();
	}
};

template<typename Key, typename val>
class Registry {
private:
	int Size{ 0 };
	el<Key, val>** reg = new el<Key, val>*[1];

	el<Key, val>* serch(Key key){
		for (int i = 0; i < Size;i++) {
			if (reg[i]->key == key)
				return reg[i];
		}
		std::cout << "Elment not found" << std::endl;
		return nullptr;
	}

	void coppy(el<Key, val>** NewReg, int b = 0) {
		delete[] reg;
		reg = new el<Key, val>* [b];
		for (int i = 0; i < b; i++) {
			reg[i] = NewReg[i];
		}
		Size = b;
	}

	int yor(el<Key, val>* out, el<Key, val>* in) {
		if (out->key > in->key)
			return true;
		else if (out->key == in->key) {
			return true;
		}
		else
			return false;
	}

	void place(el<Key, val>* in, int b = 0) {
		for (int i = 0; i < Size && b == 0; i++) {
			if (in->key == reg[i]->key) {
				reg[i]->value.add(in->value[0]);
				return;
			}
		}
		
		int sizeTmpReg = b > 0 ? (Size - 1) : (Size + 1);
		el<Key, val>** tmpReg = new el<Key, val>* [sizeTmpReg];
		bool insrt = false;

		if (reg[0] == nullptr && b == 0) {
			tmpReg[0] = in;
			coppy(tmpReg, sizeTmpReg);
			return;
		}
		else if (reg[0] == nullptr && b > 0) {
			std::cout << "Registry empty" << std::endl;
			return;
		}

		int c = b > 0 ? Size : sizeTmpReg;
		for (int i = 0, j = 0; i < c; i++) {
			 if (j == Size && !insrt) {
				tmpReg[i] = in;
			} else if (!insrt && yor(reg[j], in)) {
				if (b != 0) {
					delete reg[j];
					j++;
					i--;
				} else
					tmpReg[i] = in;
				insrt = true;
			}  else {
				tmpReg[i] = reg[j];
				j++;
			}
		}
		coppy(tmpReg, sizeTmpReg);
		delete[] tmpReg;
		
	}


public:
	Registry() {
		reg[0] = nullptr;
	}

	void add(el<Key, val>* in) {
		place(in);
	}

	void del(Key k) {
		el<Key, val>* in = new el<Key, val>(k,"");
		in = serch(k);
		if (in != nullptr)
			place(in, 1);
		else
			delete in;
	}

	int size() {
		if (reg[0] == nullptr)
			return 0;
		else
			return Size;
	}
	void find(Key fin) {
		std::cout << serch(fin)->key << std::endl;
	}

	void print(Key fin) {
		el<Key, val>* tmp = serch(fin);
		for (int i = 0; i < tmp->value.size(); i++) {
			std::cout << tmp->value[i] << "\t";
		}
		std::cout << std::endl;
	}

	Key operator[](int i) {
		return reg[i]->key;
	}

};

int main()
{
	Registry<std::string, std::string> reg;
	std::string ac[]{ "a", "c","b","d", "c"};
	std::string acc;
	std::string aca{ "lskjdfl" };
	for (int i = 0; i < 5; i++) {
		el<std::string, std::string>* elem = new el<std::string, std::string>(ac[i], aca);
		reg.add(elem);
	}

	std::cout << reg.size() << std::endl;
	for (int i = 0; i < reg.size(); i++) {
		std::cout << reg[i];
	}
	std::cout << std::endl;

	while (true) {
		std::string command;
		std::cin >> command;

		if (command == "add") {
			el<std::string, std::string>* elem = new el<std::string, std::string>;
			reg.add(elem);
		}
		else if (command == "delete") {
			el<std::string, std::string>* elem = new el<std::string, std::string>(1);
			reg.del(elem->key);
		}
		else if (command == "print") {
			el<std::string, std::string>* elem = new el<std::string, std::string>(1);
			reg.print(elem->key);
		}
		else if (command == "search") {
			el<std::string, std::string>* elem = new el<std::string, std::string>(1);
			reg.find(elem->key);
		}
		else if (command == "all") {
			std::cout << reg.size() << std::endl;
			for (int i = 0; i < reg.size(); i++) {
				std::cout << reg[i];
			}
			std::cout << std::endl;
		}
		else if (command == "exit") { exit(0); }
		else { std::cout << "Command not found" << std::endl; }
	}

}

