//Tutorials/OpenSSL/HashComposit/Headers/WhirlpoolHashClass.h
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the declaration of the WhirlpoolHashClass class
//This function uses the OpenSSL library to perform an Whirlpool hash of the bytes sent to it

///Would like to be able to do this by simply passing a file into a function and getting the same thing

#ifndef Whirlpool_HASH_CLASS_H
#define Whirlpool_HASH_CLASS_H

#include "HashesHead.h"
#include <string>
#include <cstdint>
#include "openssl/whrlpool.h"

class WhirlpoolHashClass : public HashesHead{
private:
	bool isFinished;
	unsigned char digest[WHIRLPOOL_DIGEST_LENGTH];
	WHIRLPOOL_CTX ctx;
public:
	WhirlpoolHashClass();
	virtual void addToHash(uint8_t fileByte);
	virtual std::string getHash();
};

#endif //Whirlpool_HASH_CLASS_H
