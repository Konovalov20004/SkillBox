#include <iostream>
#define Winter


int main()
{
#ifdef Winter
	std::cout << "Winter" << std::endl;
#endif
#ifdef Spring
	std::cout << "Spring" << std::endl;
#endif
#ifdef Summer
	std::cout << "Summer" << std::endl;
#endif
#ifdef Fall
	std::cout << "Fall" << std::endl;
#endif
}