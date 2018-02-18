//Tutorials/Card/Card.h
//Matthew Ellison
// Created: 11-18-17
//Modified: 11-18-17
//This file contains the declaration of the Card class.
//Most of these functions are virtual and can be overwritten easily

#include <ostream>
#include <string>
#include "Card.h"

Card::Card(int value){
	this->value = value;
}

Card::~Card(){

}

std::string Card::print(){
	return std::to_string(value);
}

std::ostream& Card::print(std::ostream& os){
	os << value;
	return os;
}

std::ostream& operator<<(std::ostream& os, Card& card){
	os << card.value;
	return os;
}

std::ostream& operator<<(std::ostream& os, Card* card){
	os << card->getValue();
	return os;
}
