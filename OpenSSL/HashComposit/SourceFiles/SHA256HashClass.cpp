//Tutorials/OpenSSL/HashComposit/Headers/SHA256HashClass.cpp
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the implementation of the SHA256HashClass class
//This function uses the OpenSSL library to perform an SHA256 hash of the bytes sent to it

#include "../Headers/HashesHead.h"
#include "../Headers/SHA256HashClass.h"
#include "openssl/sha.h"
#include <string>
#include <cstdint>
#include <stdio.h>

SHA256HashClass::SHA256HashClass(){
	SHA256_Init(&ctx);
	isFinished = false;
}

void SHA256HashClass::addToHash(uint8_t fileByte){
	if(!isFinished){
		SHA256_Update(&ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
	}
	//Should throw an exception if it is finished
}

std::string SHA256HashClass::getHash(){
	isFinished = true;
	SHA256_Final(digest, &ctx);
	char mdString[(SHA256_DIGEST_LENGTH * 2) + 1];
	for(int cnt = 0;cnt < SHA256_DIGEST_LENGTH;++cnt){
		sprintf(&mdString[cnt * 2], "%02x", (unsigned int)digest[cnt]);
	}
	return mdString;
}
