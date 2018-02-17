//Tutorials/Namespace/main.cpp
//Matthew Ellison
// Created: 12-19-17
//Modified: 12-19-17
//This file contains the test function for the different namespaces

#include <iostream>
#include "MyNamespace.h"


int main()
{
	int num1 = 5;
	int num2 = 42;
	double dbl1 = 2.1;
	double dbl2 = 91.97;

	std::cout << "This is the int difference for myNamespace: " << myNamespace::difference(num1, num2) << std::endl;
	std::cout << "This is the int difference for yourNamespace: " << yourNamespace::difference(num1, num2) << std::endl;
	std::cout << "This is the double difference for myNamespace: " << myNamespace::difference(dbl1, dbl2) << std::endl;
	std::cout << "This is the double difference for yourNamespace: " << yourNamespace::difference(dbl1, dbl2) << std::endl;
	std::cout << "This is the int division for myNamespace: " << myNamespace::divide(num1, num2) << std::endl;
	std::cout << "This is the int division for yourNamespace: " << yourNamespace::divide(dbl1, dbl2) << std::endl;
	std::cout << "This is the double division for myNamespace: " << myNamespace::divide(dbl1, dbl2) << std::endl;
	std::cout << "This is the double division for yourNamespace: " << yourNamespace::divide(dbl1, dbl2) << std::endl;

	std::cout << "Press Enter to exit" << std::endl;
	std::cin.get();

	return 0;
}
