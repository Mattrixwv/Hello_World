//Tutorials/OpenSSL/HashComposit/Headers/MD4HashClass.cpp
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the implementation of the MD4HashClass class
//This function uses the OpenSSL library to perform an MD4 hash of the bytes sent to it

#include "../Headers/HashesHead.h"
#include "../Headers/MD4HashClass.h"
#include "openssl/md4.h"
#include <string>
#include <cstdint>
#include <stdio.h>

MD4HashClass::MD4HashClass(){
	MD4_Init(&ctx);
	isFinished = false;
}

void MD4HashClass::addToHash(uint8_t fileByte){
	if(!isFinished){
		MD4_Update(&ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
	}
	//Should throw an exception if it is finished
}

std::string MD4HashClass::getHash(){
	isFinished = true;
	MD4_Final(digest, &ctx);
	char mdString[(MD4_DIGEST_LENGTH * 2) + 1];
	for(int cnt = 0;cnt < MD4_DIGEST_LENGTH;++cnt){
		sprintf(&mdString[cnt * 2], "%02x", (unsigned int)digest[cnt]);
	}
	return mdString;
}
