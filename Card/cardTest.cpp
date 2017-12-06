//Tutorials/Card/cardTest.cpp
//Matthew Ellison
// Created: 11-18-17
//Modified: 11-18-17
//This is a function to test the Card class

#include <iostream>
#include "Card.h"

int main()
{
	Card card1(0);
	Card card2(5);
	Card* cards[10];
	for(int cnt = 0;cnt < 10;++cnt)
		cards[cnt] = new Card(cnt + 10);
	std::cout << "This is card1: " << card1.print() << std::endl;
	std::cout << "This is card2: " << card2.print() << std::endl;
	std::cout << "This is card1 using print(ostream): ";
	card1.print(std::cout);
	std::cout << std::endl;
	for(int cnt = 0;cnt < 10;++cnt)
		std::cout << "This is cards[" << cnt << "]: " << cards[cnt]->print() << std::endl;
	std::cout << "This test completed successfully" << std::endl;

	return 0;
}
