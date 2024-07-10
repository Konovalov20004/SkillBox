#include <iostream>

template<typename T>
T avg() {
	T size{ 5 };
	T* arr = new T[5];
	T average{};
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
		average += arr[i];
	}
	average /= size;
	return average;
}

int main()
{
	std::cout << avg<double>();
}
