//Tutorials/Card/Card.h
//Matthew Ellison
// Created: 11-18-17
//Modified: 11-18-17
//This file contains the declaration of the Card class.
//It is a general class that should be easy to use inheritance to get a specific deck

#ifndef CARD_H
#define CARD_H

#include <ostream>
#include <string>


class Card
{
private:
	int value;
public:
	Card(int value);
	virtual ~Card();
	virtual int getValue()	{	return value;	}
	//Converts value to a string
	virtual std::string print();
	//Prints value to an ostream
	virtual std::ostream& print(std::ostream& os);
	//Easier way to print value to an ostream
	//virtual friend std::ostream& operator<<(std::ostream& os, Card& card);
	//virtual friend std::ostream& operator<<(std::ostream& os, Card* card);
};

#endif //CARD_H
