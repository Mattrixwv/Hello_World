//Tutorials/Timer/Timer.cpp
//Matthew Ellison
// Created: 2-17-18
//Modified: 2-17-18
//This file contains an example of a timer

#include <iostream>
#include <chrono>

const int NUM_REPS = 10000;

int main()
{
	//There are several clocks, I like the high resolution
	std::chrono::high_resolution_clock::time_point beginning;
	std::chrono::high_resolution_clock::time_point ending;
	std::chrono::high_resolution_clock::duration dur;
	//now() returns a time_point
	beginning = std::chrono::high_resolution_clock::now();
	//Increment an empty loop
	for(int cnt = 0;cnt < NUM_REPS;++cnt){
		std::cout << cnt << '\n';
	}

	ending = std::chrono::high_resolution_clock::now();
	//A duration type can recieve operators performed on time_points
	dur = ending - beginning;

	std::cout << "It took " << dur.count() << " time to increment and print " << NUM_REPS << " times" << std::endl;
	//Add time conversions for nano/micro/milli/second/minute/hour

	std::cout << "Press Enter to exit" << std::endl;
	std::cin.get();

	return 0;
}
