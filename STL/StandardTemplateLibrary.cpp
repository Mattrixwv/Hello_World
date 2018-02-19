//Tutorials/STL/StandardTemplateLibrary.cpp
//Matthew Ellison
// Created: 2-19-18
//Modified: 2-19-18
//This file contains code demonstrating elements in C++'s template library

#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <array>

const int ARRAY_SIZE = 100;
const int ARRAY_LOWEST_NUMBER = 0;
const int ARRAY_HIGHEST_NUMBER = 5000;


int main()
{
	///Add parts for random access
	std::chrono::high_resolution_clock::time_point beginning;
	std::chrono::high_resolution_clock::time_point ending;
	std::chrono::high_resolution_clock::duration loadFrontDur, loadBackDur, accessDur, popBackDur, popFrontDur;
	std::default_random_engine generator(std::random_device{}());
	std::uniform_int_distribution<int> dist(ARRAY_LOWEST_NUMBER, ARRAY_HIGHEST_NUMBER);
	//Declaring normal arrays so that you can use the same numbers for each structure
	int numInts[ARRAY_SIZE] {0};
	for(int cnt = 0;cnt < ARRAY_SIZE;++cnt){
		numInts[cnt] = dist(generator);
	}
	std::cout << "A vector is a dynamic array" << std::endl;
	//A dynamic array is fast at accessing elements, but can be slow at adding them and especially removing elements in the middle or back
	std::vector<int> vectInt;
	//This is a range based for loop, good for searching and accessing, but not if you are planning on removing an item and continuing to search
	//num becomes every int in the array in turn
	//This loads the array into the vector from the back
	beginning = std::chrono::high_resolution_clock::now();
	for(int num : numInts){
		vectInt.push_back(num);
	}
	ending = std::chrono::high_resolution_clock::now();
	loadBackDur = ending - beginning;

	//This loads the array into the vector from the front
	vectInt.clear();
	vectInt.shrink_to_fit();
	beginning = std::chrono::high_resolution_clock::now();
	for(int num : numInts){
		vectInt.insert(vectInt.begin(), num);
	}
	ending = std::chrono::high_resolution_clock::now();
	loadFrontDur = ending - beginning;

	//This accesses and prints every element in the vector
	beginning = std::chrono::high_resolution_clock::now();
	for(int cnt = 0;cnt < vectInt.size();++cnt){
		std::cout << vectInt[cnt] << '\n';
	}
	ending = std::chrono::high_resolution_clock::now();
	accessDur = ending - beginning;

	//This pops every element from the back of the vector
	beginning = std::chrono::high_resolution_clock::now();
	while(vectInt.size() > 0){
		vectInt.pop_back();
	}
	ending = std::chrono::high_resolution_clock::now();
	popBackDur = ending - beginning;

	//This resets the vector
	for(int num : numInts){
		vectInt.push_back(num);
	}
	//This pops every element from the front of the vector
	beginning = std::chrono::high_resolution_clock::now();
	while(vectInt.size() > 0){
		vectInt.erase(vectInt.begin());
	}
	ending = std::chrono::high_resolution_clock::now();
	popFrontDur = ending - beginning;

	//Print the results
	std::cout << "For the vector it took:\n"
			  << loadBackDur.count() << " time to load from the back\n"
			  << loadFrontDur.count() << " time to load from the front\n"
			  << accessDur.count() << " time to access and print\n"
			  << popBackDur.count() << " time to pop every element from the back\n"
			  << popFrontDur.count() << " time to pop every element from the front\n" << std::endl;


	//A linked list can be slow to access
	std::cout << "A list is a linked list" << std::endl;
	//A linked list is fast at deleting elements in the middle or end, but slow in simply accessing random data
	std::list<int> lst;
	//This loads the array into the list from the back
	beginning = std::chrono::high_resolution_clock::now();
	for(int num : numInts){
		lst.push_back(num);
	}
	ending = std::chrono::high_resolution_clock::now();
	loadBackDur = ending - beginning;

	//This loads the array into the list from the front
	lst.clear();
	beginning = std::chrono::high_resolution_clock::now();
	for(int num : numInts){
		lst.push_front(num);
	}
	ending = std::chrono::high_resolution_clock::now();
	loadFrontDur = ending - beginning;

	//This prints every element in the array
	beginning = std::chrono::high_resolution_clock::now();
	for(std::list<int>::iterator it = lst.begin();it != lst.end();++it){
		std::cout << *it << std::endl;
	}
	ending = std::chrono::high_resolution_clock::now();
	accessDur = ending - beginning;

	//This pops every element from the back of the list
	beginning = std::chrono::high_resolution_clock::now();
	while(vectInt.size() > 0){
		lst.pop_back();
	}
	ending = std::chrono::high_resolution_clock::now();
	popBackDur = ending - beginning;

	//This reloads the list
	for(int num : numInts){
		lst.push_back(num);
	}

	//This pops every element from the front of the list
	beginning = std::chrono::high_resolution_clock::now();
	while(vectInt.size() > 0){
		lst.pop_front();
	}
	ending = std::chrono::high_resolution_clock::now();
	popFrontDur = ending - beginning;

	//Print out the results
	std::cout << "For the vector it took:\n"
			  << loadBackDur.count() << " time to load from the back\n"
			  << loadFrontDur.count() << " time to load from the front\n"
			  << accessDur.count() << " time to access and print\n"
			  << popBackDur.count() << " time to pop every element from the back\n"
			  << popFrontDur.count() << " time to pop every element from the front\n" << std::endl;


	std::cin.get();
	return 0;
}