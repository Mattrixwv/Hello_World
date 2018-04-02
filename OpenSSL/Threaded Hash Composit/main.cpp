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
#include <thread>
#include <openssl/md4.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/whrlpool.h>
#include <iomanip>
#include <chrono>


enum functionLocation {MD4_LOCATION, MD5_LOCATION, SHA1_LOCATION, SHA224_LOCATION, SHA256_LOCATION, SHA384_LOCATION, SHA512_LOCATION, WHIRLPOOL_LOCATION, NUM_HASH_FUNCTIONS};


int main(int argc, char** argv){
	std::string fileName;
	std::vector<std::string> functionArguments;
	bool hasFileName = false;
	bool functionsNeeded[NUM_HASH_FUNCTIONS];
	for(int cnt = 0;cnt < NUM_HASH_FUNCTIONS;++cnt){
		functionsNeeded[cnt] = false;
	}
	///*Should put in an argument to allow comparison of a string or a string in a file (When only a single hash is asked for)
	//Run through the arguments and sort them
	for(int cnt = 1;cnt < argc;++cnt){
		//If it is not the file name
		if(argv[cnt][0] != '-'){
			if(!hasFileName){
				fileName = argv[cnt];
				hasFileName = true;
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
	std::ifstream file;
	file.open(fileName, std::ios::binary);
	//Check that the file was opened
	if(file.fail()){
		std::cout << "That is an invalid file name!" << std::endl;
		return 0;
	}
	//Setup the hashes
	MD4_CTX md4_ctx;
	MD4_Init(&md4_ctx);
	MD5_CTX md5_ctx;
	MD5_Init(&md5_ctx);
	SHA_CTX sha1_ctx;
	SHA1_Init(&sha1_ctx);
	SHA256_CTX sha224_ctx;
	SHA224_Init(&sha224_ctx);
	SHA256_CTX sha256_ctx;
	SHA256_Init(&sha256_ctx);
	SHA512_CTX sha384_ctx;
	SHA384_Init(&sha384_ctx);
	SHA512_CTX sha512_ctx;
	SHA512_Init(&sha512_ctx);
	WHIRLPOOL_CTX whirlpool_ctx;
	WHIRLPOOL_Init(&whirlpool_ctx);
	//Determine the number of hashes that are being run
	unsigned int numHashesRunning = 0;
	for(int cnt = 0;cnt < NUM_HASH_FUNCTIONS;++cnt){
		if(functionsNeeded[cnt]){
			++numHashesRunning;
		}
	}
	//Setup the threads
	std::thread threads[numHashesRunning];

//These preprocessor directives make it harder to read the code, but makes a single file portable. Pick your poison
//Here I chose to make it a little harder to read since it is only about how the different systems read files
//In theory this should work on a mac as well, assuming linux and mac both raise file flags the same way, but I have no way to test that, so no promises
	std::chrono::high_resolution_clock::time_point begin, end;
	begin = std::chrono::high_resolution_clock::now();
	uint8_t fileByte = 0;
	while(true){
		//Read the next byte from the file
		file.read(reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
		if(file.eof()){
			break;
		}
		int threadCounter = 0;
		//Add it to whichever functions are needed
		if(functionsNeeded[MD4_LOCATION]){
			threads[threadCounter++] = std::thread(MD4_Update, &md4_ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
		}
		if(functionsNeeded[MD5_LOCATION]){
			threads[threadCounter++] = std::thread(MD5_Update, &md5_ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
		}
		if(functionsNeeded[SHA1_LOCATION]){
			threads[threadCounter++] = std::thread(SHA1_Update, &sha1_ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
		}
		if(functionsNeeded[SHA224_LOCATION]){
			threads[threadCounter++] = std::thread(SHA224_Update, &sha224_ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
		}
		if(functionsNeeded[SHA256_LOCATION]){
			threads[threadCounter++] = std::thread(SHA256_Update, &sha256_ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
		}
		if(functionsNeeded[SHA384_LOCATION]){
			threads[threadCounter++] = std::thread(SHA384_Update, &sha384_ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
		}
		if(functionsNeeded[SHA512_LOCATION]){
			threads[threadCounter++] = std::thread(SHA512_Update, &sha512_ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
		}
		if(functionsNeeded[WHIRLPOOL_LOCATION]){
			threads[threadCounter++] = std::thread(WHIRLPOOL_Update, &whirlpool_ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
		}
		for(int cnt = 0;cnt < numHashesRunning;++cnt){
			threads[cnt].join();
		}
	}
	end = std::chrono::high_resolution_clock::now();
	file.close();
	std::cout << "It took " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds to hash this file\n";
	std::cout << "It took " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << " seconds to hash this file" << std::endl;

	//Calculate the correct hash strings and print all of the hashes
	if(functionsNeeded[MD4_LOCATION]){
		char temp[(MD4_DIGEST_LENGTH * 2) + 1];
		unsigned char digest[MD4_DIGEST_LENGTH];
		MD4_Final(digest, &md4_ctx);
		for (int i = 0; i < MD4_DIGEST_LENGTH; i++)
			sprintf(&temp[i*2], "%02x", (unsigned int)digest[i]);
		std::cout << std::setw(WHIRLPOOL_DIGEST_LENGTH * 2) << std::left << temp << "\tMD4" << std::endl;
	}
	if(functionsNeeded[MD5_LOCATION]){
		unsigned char digest[MD5_DIGEST_LENGTH];
		char mdString[(MD5_DIGEST_LENGTH * 2) + 1];
		MD5_Final(digest, &md5_ctx);
		for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
			sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
		std::cout << std::setw(WHIRLPOOL_DIGEST_LENGTH * 2) << std::left << mdString << "\tMD5" << std::endl;
	}
	if(functionsNeeded[SHA1_LOCATION]){
		char temp[(SHA_DIGEST_LENGTH * 2) + 1];
		unsigned char digest[SHA_DIGEST_LENGTH];
		SHA1_Final(digest, &sha1_ctx);
		for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
			sprintf(&temp[i*2], "%02x", (unsigned int)digest[i]);
		std::cout << std::setw(WHIRLPOOL_DIGEST_LENGTH * 2) << std::left << temp << "\tSHA1" << std::endl;
	}
	if(functionsNeeded[SHA224_LOCATION]){
		char temp[(SHA224_DIGEST_LENGTH * 2) + 1];
		unsigned char digest[SHA224_DIGEST_LENGTH];
		SHA224_Final(digest, &sha224_ctx);
		for (int i = 0; i < SHA224_DIGEST_LENGTH; i++)
			sprintf(&temp[i*2], "%02x", (unsigned int)digest[i]);
		std::cout << std::setw(WHIRLPOOL_DIGEST_LENGTH * 2) << std::left << temp << "\tSHA224" << std::endl;
	}
	if(functionsNeeded[SHA256_LOCATION]){
		char temp[(SHA256_DIGEST_LENGTH * 2) + 1];
		unsigned char digest[SHA256_DIGEST_LENGTH];
		SHA256_Final(digest, &sha256_ctx);
		for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
			sprintf(&temp[i*2], "%02x", (unsigned int)digest[i]);
		std::cout << std::setw(WHIRLPOOL_DIGEST_LENGTH * 2) << std::left << temp << "\tSHA256" << std::endl;
	}
	if(functionsNeeded[SHA384_LOCATION]){
		char temp[(SHA384_DIGEST_LENGTH * 2) + 1];
		unsigned char digest[SHA384_DIGEST_LENGTH];
		SHA384_Final(digest, &sha384_ctx);
		for (int i = 0; i < SHA384_DIGEST_LENGTH; i++)
			sprintf(&temp[i*2], "%02x", (unsigned int)digest[i]);
		std::cout << std::setw(WHIRLPOOL_DIGEST_LENGTH * 2) << std::left << temp << "\tSHA384" << std::endl;
	}
	if(functionsNeeded[SHA512_LOCATION]){
		char temp[(SHA512_DIGEST_LENGTH * 2) + 1];
		unsigned char digest[SHA512_DIGEST_LENGTH];
		SHA512_Final(digest, &sha512_ctx);
		for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
			sprintf(&temp[i*2], "%02x", (unsigned int)digest[i]);
		std::cout << std::setw(WHIRLPOOL_DIGEST_LENGTH * 2) << std::left << temp << "\tSHA512" << std::endl;
	}
	if(functionsNeeded[WHIRLPOOL_LOCATION]){
		char temp[(WHIRLPOOL_DIGEST_LENGTH * 2) + 1];
		unsigned char digest[WHIRLPOOL_DIGEST_LENGTH];
		WHIRLPOOL_Final(digest, &whirlpool_ctx);
		for (int i = 0; i < WHIRLPOOL_DIGEST_LENGTH; i++)
			sprintf(&temp[i*2], "%02x", (unsigned int)digest[i]);
		std::cout << std::setw(WHIRLPOOL_DIGEST_LENGTH * 2) << std::left << temp << "\tWhirlpool" << std::endl;
	}


	std::cout << "Press enter to exit" << std::endl;
	std::cin.get();

	return 0;
}
