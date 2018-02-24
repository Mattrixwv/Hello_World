//Tutorials/OpenSSL/HashComposit/Headers/MD4HashClass.h
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the declaration of the MD4HashClass class
//This function uses the OpenSSL library to perform an MD4 hash of the bytes sent to it

///Would like to be able to do this by simply passing a file into a function and getting the same thing

#ifndef MD4_HASH_CLASS_H
#define MD4_HASH_CLASS_H

#include "HashesHead.h"
#include <string>
#include <cstdint>
#include "openssl/md4.h"

class MD4HashClass : public HashesHead{
private:
	bool isFinished;
	unsigned char digest[MD4_DIGEST_LENGTH];
	MD4_CTX ctx;
public:
	MD4HashClass();
	virtual void addToHash(uint8_t fileByte);
	virtual std::string getHash();
};

#endif //MD4_HASH_CLASS_H
