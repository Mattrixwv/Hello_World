//Tutorials/OpenSSL/SHA224.cpp
//Matthew Ellison
// Created: 2-22-18
//Modified: 2-22-18
//This file contains the SHA224 hash program that I created using OpenSSL's hash function


#include <iostream>
#include <cstdint>
#include <fstream>
#include <openssl/sha.h>
 
int main(int argc, char** argv) {
	if(argc < 2){
		std::cout << "There are not enough arguments" << std::endl;
		std::cin.get();
		return 0;
	}
	std::fstream file;
	file.open(argv[1], std::ios::in | std::ios::binary);

	if(file.fail()){
		std::cout << "That is not a valid file name" << std::endl;
		std::cin.get();
		return 0;
	}
	//Make sure the integer is 8 bits long
	//unsigned because, why not?
	uint8_t line;
	unsigned char digest[SHA224_DIGEST_LENGTH];

	SHA256_CTX ctx;
	SHA224_Init(&ctx);
	while(true){
		//std::getline(file, line);
		file.read(reinterpret_cast<char*>(&line), sizeof(line));
		if(file.eof()){
			break;
		}
		SHA224_Update(&ctx, reinterpret_cast<char*>(&line), sizeof(line));
	}
	SHA224_Final(digest, &ctx);

	//Do not yet understand what this is about, but I know it works so...
	char mdString[(SHA224_DIGEST_LENGTH * 2) + 1];
	for (int i = 0; i < SHA224_DIGEST_LENGTH; i++)
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

	file.close();
	std::cout << "SHA224 digest: " << mdString << std::endl;
	std::cin.get();

    return 0;
}