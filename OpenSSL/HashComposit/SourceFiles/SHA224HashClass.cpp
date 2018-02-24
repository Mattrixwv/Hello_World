//Tutorials/OpenSSL/HashComposit/Headers/SHA224HashClass.cpp
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the implementation of the SHA224HashClass class
//This function uses the OpenSSL library to perform an SHA224 hash of the bytes sent to it

#include "../Headers/HashesHead.h"
#include "../Headers/SHA224HashClass.h"
#include "openssl/sha.h"
#include <string>
#include <cstdint>
#include <stdio.h>

SHA224HashClass::SHA224HashClass(){
	SHA224_Init(&ctx);
	isFinished = false;
}

void SHA224HashClass::addToHash(uint8_t fileByte){
	if(!isFinished){
		SHA224_Update(&ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
	}
	//Should throw an exception if it is finished
}

std::string SHA224HashClass::getHash(){
	isFinished = true;
	SHA224_Final(digest, &ctx);
	char mdString[(SHA224_DIGEST_LENGTH * 2) + 1];
	for(int cnt = 0;cnt < SHA_DIGEST_LENGTH;++cnt){
		sprintf(&mdString[cnt * 2], "%02x", (unsigned int)digest[cnt]);
	}
	return mdString;
}
