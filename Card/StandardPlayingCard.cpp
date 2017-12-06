//Tutorials/Card/StandardPlayingCard.h
//Matthew Ellison
// Created: 11-18-17
//Modified: 11-18-17
//This file contains the declaration of the StandardPlayingCard class.
//This card class is used to simulate a standard deck A-K with suits S,C,H,D

#include <ostream>
#include <string>
#include "Card.h"
#include "StandardPlayingCard.h"

StandardPlayingCard::StandardPlayingCard(int value, Suit suit) : Card(setValue(value)){
	this->suit = suit;
}

StandardPlayingCard::~StandardPlayingCard(){

}

int StandardPlayingCard::setValue(int value){
	//Allows a value between A and K
	if(value < 0)
		value = -value;
	if(value > 13)
		value %= 13;
	return value;
	//Throw an exception
}

std::string StandardPlayingCard::print(){
	//Get the value first
	std::string temp = Card::print();
	//Get the suit second
	switch(suit){
		case 0 : temp += 'S';	break;
		case 1 : temp += 'H';	break;
		case 2 : temp += 'C';	break;
		case 3 : temp += 'D';	break;
		default: break;	//Throw an exception
	}
	return temp;
}

std::ostream& operator<<(std::ostream& os, StandardPlayingCard& card){
	//os << card.print();
	os << card.getValue();
	switch(card.suit){
		case 0 : os << 'S';	break;
		case 1 : os << 'H';	break;
		case 2 : os << 'C';	break;
		case 3 : os << 'D'; break;
		default: break;	//Throw an exception
	}
	return os;
}

/*
std::ostream& operator<<(std::ostream&  os, StandardPlayingCard* card){
	//os << card->print();
	os << card->value;
	switch(card->suit){
		case 0 : os << 'S';	break;
		case 1 : os << 'H';	break;
		case 2 : os << 'C';	break;
		case 3 : os << 'D'; break;
		default: break;	//Throw an exception
	}
	return os;
}
*/
