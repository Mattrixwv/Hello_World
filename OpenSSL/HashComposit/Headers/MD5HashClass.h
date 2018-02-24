//Tutorials/OpenSSL/HashComposit/Headers/MD5HashClass.h
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the declaration of the MD5HashClass class
//This function uses the OpenSSL library to perform an MD5 hash of the bytes sent to it

///Would like to be able to do this by simply passing a file into a function and getting the same thing

#ifndef MD5_HASH_CLASS_H
#define MD5_HASH_CLASS_H

#include "HashesHead.h"
#include <string>
#include <cstdint>
#include "openssl/md5.h"

class MD5HashClass : public HashesHead{
private:
	bool isFinished;
	unsigned char digest[MD5_DIGEST_LENGTH];
	MD5_CTX ctx;
public:
	MD5HashClass();
	virtual void addToHash(uint8_t fileByte);
	virtual std::string getHash();
};

#endif //MD5_HASH_CLASS_H
