//Tutorials/Template Function/TemplateFunction.cpp
//Matthew Ellison
// Created: 12-16-17
//Modified: 12-16-17
//This file contains a tutorial for creating a template for a Function
//A template allows you to create a single function instead of a function for every different type that could be sent to it
//This shortens your code as well as the number of lines you need to debug, presuming all operations or function calls are supported by the objects passed to it

#include <iostream>
#include <string>

template <class T>
T sum(T num1, T num2);
template <class T1, class T2>
T1 functName(T1 num1, T2 num2);

int main()
{
	int numInt1 = 15;
	int  numInt2 = 42;
	double numDbl1 = 53.7;
	double numDbl2 = 4.2;
	std::string string1 = "Hello";
	std::string string2 = " World";

	std::cout << "This is the result when " << numInt1 << " and " << numInt2 << " are sent to it: " << sum(numInt1, numInt2) << std::endl;
	std::cout << "This is the result when " << numDbl1 << " and " << numDbl2 << " are sent to it: " << sum(numDbl1, numDbl2) << std::endl;
	std::cout << "This is the unexpected/untested result when \"" << string1 << "\" and \"" << string2 << "\" are sent to it: " << sum(string1, string2) << std::endl;

	//Do an example of multiple types in a tmeplate
	std::cout << "This is the result when " << numDbl2 << " and " << numInt2 << " are sent to the second template: " << functName(numDbl2, numInt2) << std::endl;
	std::cout << "This is the result when " << numInt1 << " and " << numDbl2 << " are sent to the second template: " << functName(numInt1, numDbl2) << std::endl;

	return 0;
}

template <class T>
T sum(T num1, T num2){
	return num1 + num2;
}

template <class T1, class T2>
T1 functName(T1 num1, T2 num2){
	return num1 / num2;
}
