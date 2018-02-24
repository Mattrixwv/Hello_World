//Tutorials/OpenSSL/HashComposit/Headers/SHA384HashClass.cpp
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the implementation of the SHA384HashClass class
//This function uses the OpenSSL library to perform an SHA384 hash of the bytes sent to it

#include "../Headers/HashesHead.h"
#include "../Headers/SHA384HashClass.h"
#include "openssl/sha.h"
#include <string>
#include <cstdint>
#include <stdio.h>

SHA384HashClass::SHA384HashClass(){
	SHA384_Init(&ctx);
	isFinished = false;
}

void SHA384HashClass::addToHash(uint8_t fileByte){
	if(!isFinished){
		SHA384_Update(&ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
	}
	//Should throw an exception if it is finished
}

std::string SHA384HashClass::getHash(){
	isFinished = true;
	SHA384_Final(digest, &ctx);
	char mdString[(SHA384_DIGEST_LENGTH * 2) + 1];
	for(int cnt = 0;cnt < SHA384_DIGEST_LENGTH;++cnt){
		sprintf(&mdString[cnt * 2], "%02x", (unsigned int)digest[cnt]);
	}
	return mdString;
}
