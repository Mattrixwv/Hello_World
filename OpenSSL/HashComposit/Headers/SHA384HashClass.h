//Tutorials/OpenSSL/HashComposit/Headers/SHA384HashClass.h
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the declaration of the SHA384HashClass class
//This function uses the OpenSSL library to perform an SHA384 hash of the bytes sent to it

///Would like to be able to do this by simply passing a file into a function and getting the same thing

#ifndef SHA384_HASH_CLASS_H
#define SHA384_HASH_CLASS_H

#include "HashesHead.h"
#include <string>
#include <cstdint>
#include "openssl/sha.h"

class SHA384HashClass : public HashesHead{
private:
	bool isFinished;
	unsigned char digest[SHA384_DIGEST_LENGTH];
	SHA512_CTX ctx;
public:
	SHA384HashClass();
	virtual void addToHash(uint8_t fileByte);
	virtual std::string getHash();
};

#endif //SHA384_HASH_CLASS_H
