//Tutorials/Dice/Dice.h
//Matthew Ellison
// Created: 12-6-17
//Modified: 12-6-17
//This file contains the declaration for the Dice class

#include <random>


class Dice
{
private:
	std::default_random_engine randomGenerator;	//A random number generator
	std::uniform_int_distribution<unsigned long> distribution;	//An even distribution for the random numbers
	unsigned long sides;		//The number of sides on the dice
	unsigned long face;		//The number that was just rolled
public:
	Dice(unsigned long sides = 6);
	unsigned long getSides(){	return sides;	}
	unsigned long getFace(){	return face;	}
	unsigned long roll();
};
