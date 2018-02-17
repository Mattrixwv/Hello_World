//Tutorials/Hello World/helloWorld.cpp
//Matthew Ellison
// Created: 12-6-17
//Modified: 12-6-17
//This file contains a simple hello world program with comments

#include <iostream>	//This is how you add libraries to C++
//iostream contains the declaration of cout
#include <string>	//contains the std::string type

void functionCall(int num);	//This is a prototype for a function named functionCall
//All functions must be declared before their first mention in the code
//Prototypes is a way to do this. The function itself is located after main()
//void declares what type is going to be returned. This can be any data type
//num is a parameter and is something that can be passed into the function that will change the behavior of the function
int function2();

//This is a global constant variable
//const means constant, it can't be changed
//double means double precision floating point variable, can also use float but has less precision
//convesion is to name these variables with all caps
const double PI = 3.14159265;
//Every variable has a scope, this is usually anything on the same level or deeper of the curly brackets that it has been declared in
//Since this was declared outside of the curly brackets it is global and can be used anywhere
//You don't use global variables very often to help with data encapsulation (safety/security)

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

	functionCall(num);
	std::cout << "This is the number you typed into the function: " << function2() << std::endl;
	//This is the best way to end a program
	std::cout << "Press the Enter key to continue";
	std::cin.ignore(10000, '\n');	//Sometimes this is needed infront of .get() because of carry over from the last cin
	//This ignores 10000 character or up to the '\n' character in the cin buffer, whichever comes first. (Any number can go in there)
	std::cin.get();	//This pauses the program until the Enter key is pressed


	//Another way of doing this is with a system call
	//System calls are OS dependant and generally slow so we try to stay away from them
	//system("Pause");	//This pauses the program until any key is press, but works only in windows
	//In a system call you can send anything that you would type into the terminal i.e.
	//system("ls");	Will list all of the file in the directory, just like if you had typed it into the terminal,
	//but it will only appear in the terminal. There is no way to return it to the running program

	return 0;	//When returning from main the number gets returned to the OS
	//returning 0 tells the system that everything went alright
}

void functionCall(int num){
	std::cout << "This is a function call.\n"
			<< "The number you entered earlier is " << num << std::endl;
}

int function2(){
	int num;	//You can have two variables of the same name as long as they are in different scopes
	//This num only exists within function2, just as the num in main only exists in main
	std::cout << "Enter another number: ";
	std::cin >> num;
	while(std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "That is an invalid number\nEnter another number: ";
		std::cin >> num;
	}
	return num;
}
