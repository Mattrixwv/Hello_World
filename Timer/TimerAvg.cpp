//
//Matthew Ellison
// Created: 2-28-18
//Modified: 2-28-18
//This file contains the code for a timer that runs several times and averages the results
//This is done mostly to check if striping an executable does anything to performance

#include <iostream>
#include <chrono>

const int NUM_REPS = 80000;
const int NUM_CYCLES = 10;


int main(){
	std::chrono::high_resolution_clock::time_point begin, end;
	std::chrono::high_resolution_clock::duration dur;
	double avg = 0;

	for(int cntCycles = 0;cntCycles < NUM_CYCLES;++cntCycles){
		dur = std::chrono::high_resolution_clock::duration::zero();
		for(int cntOut = 0;cntOut < NUM_REPS;++cntOut){
			begin = std::chrono::high_resolution_clock::now();
			for(int cnt = 0;cnt < NUM_REPS;++cnt);
			end = std::chrono::high_resolution_clock::now();
			dur += end - begin;
		}
		avg += (double)dur.count()/(double)NUM_REPS;
	}

	std::cout << "\nAverage: " << avg/(double)NUM_CYCLES << std::endl;

	return 0;
}