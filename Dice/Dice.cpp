//Tutorials/Dice/Dice.cpp
//Matthew Ellison
// Created: 12-6-17
//Modified: 12-6-17
//This file contains the implementation of the Dice class

#include "Dice.h"
#include <random>


Dice::Dice(unsigned long sides) : distribution(1, sides)
{
	randomGenerator.seed(std::random_device{}());
	this->sides = sides;
	face = distribution(randomGenerator);
}

unsigned long Dice::roll(){
	face = distribution(randomGenerator);
	return face;
}
