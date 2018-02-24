//Tutorials/OpenSSL/HashComposit/Headers/WhirlpoolHashClass.cpp
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the implementation of the WhirlpoolHashClass class
//This function uses the OpenSSL library to perform an Whirlpool hash of the bytes sent to it

#include "../Headers/HashesHead.h"
#include "../Headers/WhirlpoolHashClass.h"
#include "openssl/Whrlpool.h"
#include <string>
#include <cstdint>
#include <stdio.h>

WhirlpoolHashClass::WhirlpoolHashClass(){
	WHIRLPOOL_Init(&ctx);
	isFinished = false;
}

void WhirlpoolHashClass::addToHash(uint8_t fileByte){
	if(!isFinished){
		WHIRLPOOL_Update(&ctx, reinterpret_cast<char*>(&fileByte), sizeof(fileByte));
	}
	//Should throw an exception if it is finished
}

std::string WhirlpoolHashClass::getHash(){
	isFinished = true;
	WHIRLPOOL_Final(digest, &ctx);
	char mdString[(WHIRLPOOL_DIGEST_LENGTH * 2) + 1];
	for(int cnt = 0;cnt < WHIRLPOOL_DIGEST_LENGTH;++cnt){
		sprintf(&mdString[cnt * 2], "%02x", (unsigned int)digest[cnt]);
	}
	return mdString;
}
