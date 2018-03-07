//Tutorials/Sorts/Sorts.cpp
//Matthew Ellison
// Created: 3-7-18
//Modified: 3-7-18
//This file contains the function that compares the different sorts


#include <iostream>
#include <iomanip>
#include <random>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <chrono>
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "ThreadedQuickSort.hpp"
#ifdef _WIN32
	#include <ctime>
#endif //_WIN32


int main(){
	#ifdef _WIN32
		std::default_random_engine generator(time(0));
	#else
		std::default_random_engine generator(std::random_device{}());
	#endif	//_WIN32
	std::uniform_int_distribution<int64_t> dist(INT64_MIN, INT64_MAX);
	//Prompt for number of numbers to generate
	unsigned int numsToGen;
	std::cout << "How many numbers do you want to generate? ";
	std::cin >> numsToGen;
	while(std::cin.fail()){
		std::cout << "That is an invalid number\nTry again: ";
		std::cin >> numsToGen;
	}
	std::vector<int64_t> orgArray;
	orgArray.reserve(numsToGen);
	//Generate numbers
	for(int cnt = 0;cnt < numsToGen;++cnt){
		orgArray.push_back(dist(generator));
	}
	std::cout << "Numbers generated successfully\n\n" << std::endl;
	std::chrono::high_resolution_clock::time_point begin, end;

	//Bubble sort
	std::vector<int64_t> bubbleArray(orgArray);
	begin = std::chrono::high_resolution_clock::now();
	mee::bubbleSort(bubbleArray, bubbleArray.size());
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Bubble sort completed successfully\nSort took " << std::right << std::setw(16) << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds\n" << std::endl;

	//Quick sort
	std::vector<int64_t> quickArray(orgArray);
	begin = std::chrono::high_resolution_clock::now();
	mee::quickSort(quickArray, quickArray.size());
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Quick sort completed successfully\nSort took " << std::right << std::setw(16) << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds\n" << std::endl;

	//Quick sort
	std::vector<int64_t> threadedQuickArray(orgArray);
	begin = std::chrono::high_resolution_clock::now();
	mee::threadedQuickSort(threadedQuickArray, threadedQuickArray.size());
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Threaded quick sort completed successfully\nSort took " << std::right << std::setw(16) << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds\n" << std::endl;

	//STL sort
	std::vector<int64_t> sortArray(orgArray);
	begin = std::chrono::high_resolution_clock::now();
	std::sort(sortArray.begin(), sortArray.end());
	end = std::chrono::high_resolution_clock::now();
	std::cout << "STL sort completed successfully\nSort took " << std::right << std::setw(16) << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds\n" << std::endl;


	return 0;
}
