//Tutorials/Dice/DiceTest.cpp
//Matthew Ellison
// Created: 12-6-17
//Modified: 12-6-17
//This file contains the test function for the Dice class

#include <iostream>
#include "Dice.h"

const int DIE2SIZE = 20;


int main()
{
	Dice die1;
	Dice die2(DIE2SIZE);
	int arr1[6] = {0};
	int arr2[DIE2SIZE] = {0};

	for(int cnt = 0;cnt < (die1.getSides() * 1000);++cnt)
		++arr1[die1.roll() - 1];
	std::cout << "Here are the results of the first die:\n";
	for(int cnt = 0;cnt < die1.getSides();++cnt)
		std::cout << cnt + 1 << ". " << arr1[cnt] << '\n';
	//Roll the second die
	for(int cnt = 0;cnt < (die2.getSides() * 1000);++cnt)
		++arr2[die2.roll() - 1];
	std::cout << "Here are the results of the second die:\n";
	for(int cnt = 0;cnt < die2.getSides();++cnt)
		std::cout << cnt + 1 << ". " << arr2[cnt] << '\n';

	std::cout << "The test has completed successfully!" << std::endl;
	std::cin.get();

	return 0;
}
