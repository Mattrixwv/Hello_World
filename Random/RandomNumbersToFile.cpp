//Tutorials/Random/RandomNumbersToFile.cpp
//Matthew Ellison
// Created: 3-7-18
//Modified: 3-7-18
//This program generates random numbers and saves them to a file in text format
//It was created for the purpose of testing the sort functions


#include <iostream>
#include <random>
#include <fstream>
#include <cstdint>

#ifdef _WIN32
	#include <ctime>
#endif //_WIN32

const int64_t MIN = INT64_MIN;
const int64_t MAX = INT64_MAX;

int main(){
	#ifdef _WIN32	//Windows does not implement random_device well yet
		std::default_random_engine generator(time(0));
	#else
		std::default_random_engine generator(std::random_device{}());
	#endif
	
	std::uniform_int_distribution<int64_t> dist(MIN, MAX);

	std::fstream textFile, binFile;
	textFile.open("RandomNumbers.txt", std::ios::out);
	binFile.open("RandomNumbers.bin", std::ios::out | std::ios::binary);
	if(textFile.fail() || binFile.fail()){
		std::cout << "Failed to open the file for writing\nPress Enter to exit" << std::endl;
		std::cin.get();
		return 0;
	}


	unsigned int numsToGen;
	std::cout << "How many number do you wish to generate? ";
	std::cin >> numsToGen;
	//Write the numbers to the file
	for(int cnt = 0;cnt < numsToGen;++cnt){
		int64_t randNum = dist(generator);
		textFile << randNum;
		if(cnt < numsToGen - 1){
			textFile << '\n';
		}
		binFile.write(reinterpret_cast<char*>(&randNum), sizeof(randNum));
	}
	textFile.close();
	binFile.close();

	std::cout << "Numbers written successfully\nPress Enter to exit" << std::endl;
	std::cin.ignore(10000, '\n');
	std::cin.get();

	return 0;
}
