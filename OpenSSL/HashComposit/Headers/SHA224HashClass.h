//Tutorials/OpenSSL/HashComposit/Headers/SHA224HashClass.h
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the declaration of the SHA224HashClass class
//This function uses the OpenSSL library to perform an SHA224 hash of the bytes sent to it

///Would like to be able to do this by simply passing a file into a function and getting the same thing

#ifndef SHA224_HASH_CLASS_H
#define SHA224_HASH_CLASS_H

#include "HashesHead.h"
#include <string>
#include <cstdint>
#include "openssl/sha.h"

class SHA224HashClass : public HashesHead{
private:
	bool isFinished;
	unsigned char digest[SHA224_DIGEST_LENGTH];
	SHA256_CTX ctx;
public:
	SHA224HashClass();
	virtual void addToHash(uint8_t fileByte);
	virtual std::string getHash();
};

#endif //SHA224_HASH_CLASS_H
