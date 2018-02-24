//Tutorials/OpenSSL/HashComposit/Headers/HashesHead.h
//Matthew Ellison
// Created: 2-23-18
//Modified: 2-23-18
//This file contains the declaration of the abstranct base class HashesHead that is used as the basis for all the other hashes in this program
//This class is not meant to be used by itself

#ifndef HASHES_HEAD_H
#define HASHES_HEAD_H

#include <string>
#include <cstdint>

class HashesHead{
private:
public:
	virtual void addToHash(uint8_t fileByte) = 0;
	virtual std::string getHash() = 0;
};

#endif //HASHES_HEAD_H
