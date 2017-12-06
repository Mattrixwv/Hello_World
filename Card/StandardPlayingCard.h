//Tutorials/Card/StandardPlayingCard.h
//Matthew Ellison
// Created: 11-18-17
//Modified: 11-18-17
//This file contains the declaration of the StandardPlayingCard class.
//This card class is used to simulate a standard deck A-K with suits S,C,H,D

#ifndef STANDARD_PLAYING_CARD_H
#define STANDARD_PLAYING_CARD_H

//Done this way you can determine color by using %2
enum Suit {spades = 0, hearts = 1, clubs = 2, diamonds = 3};

#include <ostream>
#include <string>
#include "Card.h"

class StandardPlayingCard : public Card
{
private:
	Suit suit;
	int setValue(int value);
public:
	StandardPlayingCard(int value, Suit suit);
	~StandardPlayingCard();
	//Declared inline for speed
	Suit getSuit()	{	return suit;	}
	std::string print();
	friend std::ostream& operator<<(std::ostream& os, StandardPlayingCard& card);
	//friend std::ostream& operator<<(std::ostream& os);
};

#endif //STANDARD_PLAYING_CARD_H
