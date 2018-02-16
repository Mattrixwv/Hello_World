//Tutorials/Card/StandardPlayingCard.h
//Matthew Ellison
// Created: 11-18-17
//Modified: 11-18-17
//This file contains the Tests for the StandardPlayingCard class

#include <iostream>
#include <string>
#include "StandardPlayingCard.h"

int main()
{
	StandardPlayingCard card1(5, hearts);
	StandardPlayingCard card2(-5, diamonds);
	StandardPlayingCard* cards[10];
	for(int cnt = 0;cnt < 10;++cnt)
		cards[cnt] = new StandardPlayingCard(cnt + 1, spades);
	std::cout << "card1.print(): " << card1.print() << std::endl;
	std::cout << "card2.print(): " << card2.print() << std::endl;
	std::cout << "cout << card1: " << card1 << std::endl;
	for(int cnt = 0;cnt < 10;++cnt)
		std::cout << "cout << cards[" << cnt << "]: " << *cards[cnt] << std::endl;
	std::cout << "The test finished successfully!\nPress Enter to continue" << std::endl;
	std::cin.get();

	return 0;
}
