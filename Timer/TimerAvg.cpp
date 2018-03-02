//
//Matthew Ellison
// Created: 2-28-18
//Modified: 2-28-18
//This file contains the code for a timer that runs several times and averages the results
//This is done mostly to check if striping an executable does anything to performance

#include <iostream>
#include <chrono>
#include <cstdint>
#include <thread>
#include <mutex>

const int NUM_REPS = 80000;
const int NUM_CYCLES = 10;
const int NUM_THREADS = 8;

static std::mutex barrier;
void threadedTimer(uint64_t num, double* total);


int main(){
	std::chrono::high_resolution_clock::time_point begin, end;
	std::chrono::high_resolution_clock::duration dur;
	std::thread threads[NUM_THREADS];
	double avg = 0;
	uint64_t num = 0;

	//Start all of the threads
	for(unsigned int threadCnt = 0;threadCnt < NUM_THREADS;++threadCnt){
		threads[threadCnt] = std::thread(threadedTimer, num, &avg);
		++num;
	}
	//Join them so nothing runs off without everything else
	for(unsigned int threadCnt = 0;threadCnt < NUM_THREADS;++threadCnt){
		threads[threadCnt].join();
	}
/* */
/*
	uint64_t cnt = 0;
	for(cnt = 0;cnt < NUM_THREADS;++cnt){
		threadedTimer(&cnt, &avg);
	}
/* */
	//Calculate and print the average of each 'reps' run
	std::cout << "\nAverage: " << avg/(double)NUM_THREADS << std::endl;

	return 0;
}

void threadedTimer(uint64_t num, double* total){
	std::chrono::high_resolution_clock::time_point begin, end;
	std::chrono::high_resolution_clock::duration dur;
	dur == std::chrono::high_resolution_clock::duration::zero();

	for(uint64_t cycleCnt = 0;cycleCnt < NUM_CYCLES;++cycleCnt){
		begin = std::chrono::high_resolution_clock::now();
		for(uint64_t repCnt = 0;repCnt < NUM_REPS;++repCnt){
			//Just to make sure this thing is incrementing correctly
			std::lock_guard<std::mutex> guard(barrier);
			std::cout << num << ". " << cycleCnt << " : " << repCnt << std::endl;
		}
		end = std::chrono::high_resolution_clock::now();
		dur += end - begin;
	}
	std::lock_guard<std::mutex> guard(barrier);
	*total += (double)dur.count()/(double)NUM_CYCLES;
}
