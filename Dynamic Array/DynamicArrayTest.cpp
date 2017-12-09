//Tutorials/Dynamic Array/DynamicArrayTest.cpp
//Matthew Ellison
// Created: 12-7-17
//Modified: 12-7-17
//This file contains the test function for the DynamicArray class

#include "DynamicArray.h"
#include <iostream>
#include <string>


int main()
{
	DynamicArray<int> arr1;
	DynamicArray<double> arr2;
	DynamicArray<std::string> arr3;
	DynamicArray<char> arr4;

	//Integers

	for(int cnt = 0;cnt < 10;++cnt)
		arr1.push(cnt * 5);
	arr1.push(500, 5L);
	for(int cnt = 0;cnt < arr1.getSize();++cnt)
		std::cout << cnt + 1 << ". " << arr1[cnt] << '\n';
	//std::cout << "Complete!" << std::endl;
	std::cout << "This is what happens when you try to access something out of bounds: " << arr1[50] << "\n\n\nDoubles:\n";

	//Doubles
	for(int cnt = 0;cnt < 10;++cnt)
		arr2.push(cnt * 3.5);
	arr2.push(500, 5L);
	for(int cnt = 0;cnt < arr2.getSize();++cnt)
		std::cout << cnt + 1 << ". " << arr2[cnt] << '\n';
	std::cout << "This is what happens when you try to access something out of bounds: " << arr2[50] << "\n\n\nCharacters:\n";


	//Strings
	for(int cnt = 0;cnt < 10;++cnt)
		arr3.push(std::to_string(cnt * 2));
	arr3.push("Hi", 5L);
	for(int cnt = 0;cnt < arr3.getSize();++cnt)
		std::cout << cnt + 1 << ". " << arr3[cnt] << '\n';
	std::cout << "This is what happens when you try to access something out of bounds: " << arr3[50] << std::endl;


	for(int cnt = 0;cnt < 10;++cnt)
		arr4.push(cnt + 65);
	arr4.push('Q', 5L);
	for(int cnt = 0;cnt < arr4.getSize();++cnt)
		std::cout << cnt + 1 << ". " << arr4[cnt] << '\n';
	//std::cout << "Complete!" << std::endl;
	std::cout << "This is what happens when you try to access something out of bounds: " << arr4[50] << std::endl;

	return 0;
}
