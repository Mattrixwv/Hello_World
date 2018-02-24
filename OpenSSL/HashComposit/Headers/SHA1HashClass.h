//Tutorials/OpenSSL/HashComposit/Headers/SHA1HashClass.h
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the declaration of the SHA1HashClass class
//This function uses the OpenSSL library to perform an SHA1 hash of the bytes sent to it

///Would like to be able to do this by simply passing a file into a function and getting the same thing

#ifndef SHA1_HASH_CLASS_H
#define SHA1_HASH_CLASS_H

#include "HashesHead.h"
#include <string>
#include <cstdint>
#include "openssl/sha.h"

class SHA1HashClass : public HashesHead{
private:
	bool isFinished;
	unsigned char digest[SHA_DIGEST_LENGTH];
	SHA_CTX ctx;
public:
	SHA1HashClass();
	virtual void addToHash(uint8_t fileByte);
	virtual std::string getHash();
};

#endif //SHA1_HASH_CLASS_H
