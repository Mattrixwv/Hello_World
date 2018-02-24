//Tutorials/OpenSSL/HashComposit/main.cpp
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This is the driver function for the hashcomposit program
//This program must be linked with libcrypto.lib from OpenSSL


#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <fstream>
#include "Headers/MD4HashClass.h"
#include "Headers/MD5HashClass.h"
#include "Headers/SHA1HashClass.h"
#include "Headers/SHA224HashClass.h"
#include "Headers/SHA256HashClass.h"
#include "Headers/SHA384HashClass.h"
#include "Headers/SHA512HashClass.h"
#include "Headers/WhirlpoolHashClass.h"

enum functionLocation {MD4_LOCATION, MD5_LOCATION, SHA1_LOCATION, SHA224_LOCATION, SHA256_LOCATION, SHA384_LOCATION, SHA512_LOCATION, WHIRLPOOL_LOCATION, NUM_HASH_FUNCTIONS};

int main(int argc, char** argv){
	std::string fileName;
	std::vector<std::string> functionArguments;
	bool hasFileName = false;
	bool functionsNeeded[NUM_HASH_FUNCTIONS];
	for(int cnt = 0;cnt < NUM_HASH_FUNCTIONS;++cnt){
		functionsNeeded[cnt] = false;
	}
	//Run through the arguments and sort them
	for(int cnt = 1;cnt < argc;++cnt){
		//If it is not the file name
		if(argv[cnt][0] != '-'){
			if(!hasFileName){
				fileName = argv[cnt];
			}
			else{
				std::cout << "There is more than one file name" << std::endl;
				return 0;
			}
		}
		else{
			functionArguments.push_back(argv[cnt]);
		}
	}
	//Have the default argument to be all of the hashes
	if(functionArguments.size() == 0){
		functionArguments.push_back("-all");
	}
	//Check which functions you need to use and if there are any invalid functions
	for(int cnt = 0;cnt < functionArguments.size();++cnt){
		if(functionArguments[cnt] == "-MD4" && functionsNeeded[MD4_LOCATION] == false){
			functionsNeeded[MD4_LOCATION] = true;
		}
		else if(functionArguments[cnt] == "-MD5" && functionsNeeded[MD5_LOCATION] == false){
			functionsNeeded[MD5_LOCATION] = true;
		}
		else if(functionArguments[cnt] == "-SHA1" && functionsNeeded[SHA1_LOCATION] == false){
			functionsNeeded[SHA1_LOCATION] = true;
		}
		else if(functionArguments[cnt] == "-SHA224" && functionsNeeded[SHA224_LOCATION] == false){
			functionsNeeded[SHA224_LOCATION] = true;
		}
		else if(functionArguments[cnt] == "-SHA256" && functionsNeeded[SHA256_LOCATION] == false){
			functionsNeeded[SHA256_LOCATION] = true;
		}
		else if(functionArguments[cnt] == "-SHA384" && functionsNeeded[SHA384_LOCATION] == false){
			functionsNeeded[SHA384_LOCATION] = true;
		}
		else if(functionArguments[cnt] == "-SHA512" && functionsNeeded[SHA512_LOCATION] == false){
			functionsNeeded[SHA512_LOCATION] = true;
		}
		else if(functionArguments[cnt] == "-Whirlpool" && functionsNeeded[WHIRLPOOL_LOCATION] == false){
			functionsNeeded[WHIRLPOOL_LOCATION] = true;
		}
		else if(functionArguments[cnt] == "-all"){
			for(int cnt = 0;cnt < NUM_HASH_FUNCTIONS;++cnt){
				functionsNeeded[cnt] = true;
			}
		}
		else{
			std::cout << functionArguments[cnt] << " is an invalid argument!" << std::endl;
			return 0;
		}
	}
	//Open the file
	std::ifstream file(fileName);
	//Check that the file was opened
	if(file.fail()){
		std::cout << "That is an invalid file name!" << std::endl;
		return 0;
	}
	//Setup the classes correctly
	HashesHead* hashClasses[NUM_HASH_FUNCTIONS];
	hashClasses[MD4_LOCATION] = new MD4HashClass;
	hashClasses[MD5_LOCATION] = new MD5HashClass;
	hashClasses[SHA1_LOCATION] = new SHA1HashClass;
	hashClasses[SHA224_LOCATION] = new SHA224HashClass;
	hashClasses[SHA256_LOCATION] = new SHA256HashClass;
	hashClasses[SHA384_LOCATION] = new SHA384HashClass;
	hashClasses[SHA512_LOCATION] = new SHA512HashClass;
	hashClasses[WHIRLPOOL_LOCATION] = new WhirlpoolHashClass;

	while(true){
	//while(!file.eof()){	//Use for windows
		//Read the next byte from the file
		uint8_t fileByte = 0;
		file.read(reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
		//Remove if statement for windows
		if(file.eof()){
			break;
		}
		//Add it to whichever functions are needed
		if(functionsNeeded[MD4_LOCATION]){
			hashClasses[MD4_LOCATION]->addToHash(fileByte);
		}
		if(functionsNeeded[MD5_LOCATION]){
			hashClasses[MD5_LOCATION]->addToHash(fileByte);
		}
		if(functionsNeeded[SHA1_LOCATION]){
			hashClasses[SHA1_LOCATION]->addToHash(fileByte);
		}
		if(functionsNeeded[SHA224_LOCATION]){
			hashClasses[SHA224_LOCATION]->addToHash(fileByte);
		}
		if(functionsNeeded[SHA256_LOCATION]){
			hashClasses[SHA256_LOCATION]->addToHash(fileByte);
		}
		if(functionsNeeded[SHA384_LOCATION]){
			hashClasses[SHA384_LOCATION]->addToHash(fileByte);
		}
		if(functionsNeeded[SHA512_LOCATION]){
			hashClasses[SHA512_LOCATION]->addToHash(fileByte);
		}
		if(functionsNeeded[WHIRLPOOL_LOCATION]){
			hashClasses[WHIRLPOOL_LOCATION]->addToHash(fileByte);
		}
	}
	file.close();

	//Print all of the hashes
	if(functionsNeeded[MD4_LOCATION]){
		std::cout << hashClasses[MD4_LOCATION]->getHash() << "\tMD4" << std::endl;
	}
	if(functionsNeeded[MD5_LOCATION]){
		std::cout << hashClasses[MD5_LOCATION]->getHash() << "\tMD5" << std::endl;
	}
	if(functionsNeeded[SHA1_LOCATION]){
		std::cout << hashClasses[SHA1_LOCATION]->getHash() << "\tSHA1" << std::endl;
	}
	if(functionsNeeded[SHA224_LOCATION]){
		std::cout << hashClasses[SHA224_LOCATION]->getHash() << "\tSHA224" << std::endl;
	}
	if(functionsNeeded[SHA256_LOCATION]){
		std::cout << hashClasses[SHA256_LOCATION]->getHash() << "\tSHA256" << std::endl;
	}
	if(functionsNeeded[SHA384_LOCATION]){
		std::cout << hashClasses[SHA384_LOCATION]->getHash() << "\tSHA384" << std::endl;
	}
	if(functionsNeeded[SHA512_LOCATION]){
		std::cout << hashClasses[SHA512_LOCATION]->getHash() << "\tSHA512" << std::endl;
	}
	if(functionsNeeded[WHIRLPOOL_LOCATION]){
		std::cout << hashClasses[WHIRLPOOL_LOCATION]->getHash() << "\tWhirlpool" << std::endl;
	}
	//Delete all of the dynamically allocated classes for neatness
	for(int cnt = 0;cnt < NUM_HASH_FUNCTIONS;++cnt){
		delete hashClasses[cnt];
	}
	std::cout << "Press enter to exit" << std::endl;
	std::cin.get();

	return 0;
}
