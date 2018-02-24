//Tutorials/OpenSSL/HashComposit/Headers/SHA1HashClass.cpp
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the implementation of the SHA1HashClass class
//This function uses the OpenSSL library to perform an SHA1 hash of the bytes sent to it

#include "../Headers/HashesHead.h"
#include "../Headers/SHA1HashClass.h"
#include "openssl/sha.h"
#include <string>
#include <cstdint>
#include <stdio.h>

SHA1HashClass::SHA1HashClass(){
	SHA1_Init(&ctx);
	isFinished = false;
}

void SHA1HashClass::addToHash(uint8_t fileByte){
	if(!isFinished){
		SHA1_Update(&ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
	}
	//Should throw an exception if it is finished
}

std::string SHA1HashClass::getHash(){
	isFinished = true;
	SHA1_Final(digest, &ctx);
	char mdString[(SHA_DIGEST_LENGTH * 2) + 1];
	for(int cnt = 0;cnt < SHA_DIGEST_LENGTH;++cnt){
		sprintf(&mdString[cnt * 2], "%02x", (unsigned int)digest[cnt]);
	}
	return mdString;
}
