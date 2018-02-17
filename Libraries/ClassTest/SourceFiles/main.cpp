#include "TestClass.h"
#include <iostream>

int main()
{
	TestClass test(5);
	std::cout << "getNum(): " << test.getNum() << std::endl;
	std::cout << "add(3): " << test.add(3) << std::endl;

	std::cout << "Press Enter to exit" << std::endl;
	std::cin.get();

	return 0;
}
