//Tutorials/Hello World/helloWorld.cpp
//Matthew Ellison
// Created: 12-6-17
//Modified: 12-6-17
//This file contains a simple hello world program with comments

#include <iostream>	//This is how you add libraries to C++
//iostream contains the declaration of cout
#include <string>	//contains the std::string type

int main()
{
	std::cout << "Hello World" << std::endl;	//This is how you write to the console
	//std:: is the namespace cout and endl are contained in (Covered later)
	//endl empties the cache for cout and sends the cursor to the next line
	//<< is the extraction operator
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	//cin is how you get input from the console
	//>> is the insertion operator
	//>> reads only up until whitespace is encountered, the rest is stored in a buffer
	//This is error checking for the input
	while(std::cin.fail()){
		std::cin.clear();	//clears all error flags
		std::cin.ignore(10000, '\n');	//ignores 10000 characters or until it reaches the '\n' character
		std::cout << "That is an invalid number\nEnter a number: ";	//Reprompt for the number
		std::cin >> num;
	}
	std::cout << "The number you entered is: " << num << std::endl;

	std::string phrase = "";
	std::cout << "Enter a phrase:\n";
	std::cin.ignore(10000, '\n');		//You must ignore the '\n' character that is stored in the buffer from cin >> or that is all getline will pick up
	std::getline(std::cin, phrase);		//This how you pick up a line with whitespace
	std::cout << "The phrase you entered is: " << phrase << std::endl;

	return 0;	//When returning from main the number gets returned to the OS
	//returning 0 tells the system that everything went alright
}
