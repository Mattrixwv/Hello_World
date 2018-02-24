//Tutorials/OpenSSL/HashComposit/Headers/SHA512HashClass.cpp
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the implementation of the SHA512HashClass class
//This function uses the OpenSSL library to perform an SHA512 hash of the bytes sent to it

#include "../Headers/HashesHead.h"
#include "../Headers/SHA512HashClass.h"
#include "openssl/sha.h"
#include <string>
#include <cstdint>
#include <stdio.h>

SHA512HashClass::SHA512HashClass(){
	SHA512_Init(&ctx);
	isFinished = false;
}

void SHA512HashClass::addToHash(uint8_t fileByte){
	if(!isFinished){
		SHA512_Update(&ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
	}
	//Should throw an exception if it is finished
}

std::string SHA512HashClass::getHash(){
	isFinished = true;
	SHA512_Final(digest, &ctx);
	char mdString[(SHA512_DIGEST_LENGTH * 2) + 1];
	for(int cnt = 0;cnt < SHA512_DIGEST_LENGTH;++cnt){
		sprintf(&mdString[cnt * 2], "%02x", (unsigned int)digest[cnt]);
	}
	return mdString;
}
