//Tutorials/Random/Random.cpp
//Matthew Ellison
// Created: 2-17-18
//Modified: 2-17-18
//This file contains a couple of examples of random number generators

#include <iostream>
//For the older (C) way to do this
#include <cstdlib>
#include <ctime>
//For the new (C++11) way to do this
#include <random>

//You can use the using keyword this way to simplify some code and shorten some lines, but still not the best practice
//By doing this you are specifying only certain function from a namespace instead of the whole thing
using std::cout;
using std::endl;
using std::cin;

//It is good practice to use const variables instead of magic numbers...especially if they are used in more than one place
const int NUM_ROLLS = 10;

int main()
{
	//This is the old way to create a random number generator
	//This is how you seed the generator
	//All computer operations are equations and therefore repeatable
	//If you use the same seed every time you will get the same sequence every time
	//This can be useful for debugging, but bad for something you want to give the appearance of randomness
	//time(0) returns the number of milliseconds since jan 1 1970, which should be different every time the program is run
	srand(time(0));
	//From here we can generate random numbers
	//The equation around rand() creates numbers between 1 and 20 (simulating d20) (simple but not even)
	std::cout << "Old random number generator:" << std::endl;
	for(int cnt = 0;cnt < NUM_ROLLS;++cnt){
		cout << cnt + 1 << ". " << ((rand() % 20) + 1) << endl;
	}
	std::cout << "\n\n\n";

	//This is the new way to create a random number generator
	//There are several different generators, I simply use the default for simplicity
	//This is the short way to seed the generator, there is a longer way to do it using specific variables
	//random_device does not work correctly on windows, it returns the same number every run
	//You can replace it with time(0) or even a magic number, it is just a seed
	std::default_random_engine generator(std::random_device{}());
	//This allows an even distribution of numbers between 1 and 20 (simulating d20)
	std::uniform_int_distribution<int> dist(1, 20);

	for(int cnt = 0;cnt < NUM_ROLLS;++cnt){
		cout << cnt + 1 << ". " << dist(generator) << endl;
	}

	cout << "Press Enter to exit" << std::endl;
	cin.get();

	return 0;
}
