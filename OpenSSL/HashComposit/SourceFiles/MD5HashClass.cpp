//Tutorials/OpenSSL/HashComposit/Headers/MD5HashClass.cpp
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the implementation of the MD5HashClass class
//This function uses the OpenSSL library to perform an MD4 hash of the bytes sent to it

#include "../Headers/HashesHead.h"
#include "../Headers/MD5HashClass.h"
#include "openssl/md5.h"
#include <string>
#include <cstdint>
#include <stdio.h>

MD5HashClass::MD5HashClass(){
	MD5_Init(&ctx);
	isFinished = false;
}

void MD5HashClass::addToHash(uint8_t fileByte){
	if(!isFinished){
		MD5_Update(&ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
	}
	//Should throw an exception if it is finished
}

std::string MD5HashClass::getHash(){
	isFinished = true;
	MD5_Final(digest, &ctx);
	char mdString[(MD5_DIGEST_LENGTH * 2) + 1];
	for(int cnt = 0;cnt < MD5_DIGEST_LENGTH;++cnt){
		sprintf(&mdString[cnt * 2], "%02x", (unsigned int)digest[cnt]);
	}
	return mdString;
}
