//Tutorials/File_Operations/FileBuffer.hpp
//Matthew Ellison
// Created: 4-23-18
//Modified: 4-23-18
//This file contains the declaration of the FileBuffer class
//This class is designed to hold a predefined amount of the file in RAM


#ifndef FILE_BUFFER_HPP
#define FILE_BUFFER_HPP

#include <cstdint>
#include <fstream>
#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#endif

class FileBuffer{
private:
	#ifdef _WIN32
	uint64_t getTotalSystemMemory(){
		MEMORYSTATUSEX status;
		status.dwLength = sizeof(status);
		GlobalMemoryStatusEx(&status);
		return status.ullTotalPhys;
	}
	#elif __linux__
	uint64_t getTotalSystemMemory(){
		long pages = sysconf(_SC_PHYS_PAGES);
		long page_size = sysconf(_SC_PAGE_SIZE);
		return pages * page_size;
	}
	#endif
	uint64_t bufferSize;	//Size in bytes
	uint8_t* buffer;		//The actual buffer
	uint64_t location;		//The current location in the buffer
	uint64_t endBuffer;		//The end location of the buffer
	uint64_t fileSize;		//Holds the size of the current file
	std::ifstream inFile;	//The input file
	bool failBit;
	void fillBuffer(){		//Fills the buffer as full as possible
		//Find if the buffer is larger than the file
		//If it is set endBuffer to the correct location
		if((bufferSize) > (fileSize - inFile.tellg())){
			endBuffer = fileSize;
			endBuffer -= inFile.tellg();
			//You need to tell the function that the buffer is the correct size or an error will occur
			inFile.read(reinterpret_cast<char*>(buffer), (sizeof(buffer[0]) * endBuffer));
			inFile.get();
		}
		//Otherwise read the full buffer in
		else{
			endBuffer = bufferSize;
			inFile.read(reinterpret_cast<char*>(buffer), (sizeof(buffer[0]) * endBuffer));
		}
		location = 0;
	}
	void getFileSize(std::string fileName){
		std::ifstream temp;
		temp.open(fileName, std::ios::ate | std::ios::binary);
		fileSize = temp.tellg();
		temp.close();
	}
public:
	FileBuffer(uint64_t bufferSize){
		uint64_t maxSize = getTotalSystemMemory();
		//If the requested size is too large get it as big as you can
		if(bufferSize > (maxSize/2)){
			this->bufferSize = (maxSize/2);
		}
		//Otherwise try to make it that size
		else{
			this->bufferSize = bufferSize;
		}
		buffer = new uint8_t[bufferSize];
		failBit = false;
	}
	~FileBuffer(){
		delete[] buffer;
		inFile.close();
	}
	void open(std::string fileName){
		inFile.open(fileName, std::ios::binary);
		if(!inFile.fail()){
			getFileSize(fileName);
			fillBuffer();
		}
		else{
			failBit = true;
		}
	}
	bool fail(){
		return failBit;
	}
	void clear(){
		inFile.clear();
	}
	bool eof(){
		if(inFile.eof()){
			if(location >= endBuffer){
				return true;
			}
		}
		return false;
	}
	uint8_t read(){
		//If the current reading location is the end of the buffer, you need to refil
		if(location > endBuffer){
			fillBuffer();
		}
		if(location <= endBuffer){
			return buffer[location++];
		}
		else{
			return 0;
		}
	}
};

#endif //FILE_BUFFER_HPP
