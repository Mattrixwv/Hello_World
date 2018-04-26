//
//Matthew Ellison
// Created: 4-23-18
//Modified: 4-23-18
//This file contains the test function for the FileBuffer class

#include <iostream>
#include <string>
#include <cstdint>
#include "FileBuffer.hpp"

#define MB (1024 * 1024)


int main(){
	FileBuffer inFile(10 * MB);	//Make a 10MB buffer
	inFile.open("Test.txt");
	if(inFile.fail()){
		std::cout << "Error opening file" << std::endl;
		return 0;
	}
	while(!inFile.eof()){
		std::cout << (char)inFile.read();
	}

	std::cin.get();

	return 0;
}
/* */
