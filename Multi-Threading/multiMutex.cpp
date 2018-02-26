//Tutorials/Multi-Threading/multiMutex.cpp
//Matthew Ellison
// Created: 2-26-18
//Modified: 2-26-18
//This file contains an example of using a mutex type to stop 2 threads from trying to modify the same element at the same time
//Because of the overhead of setting up threads and the fact that this function doesn't do hardly anything, the single threaded function is actually faster than the multi-threaded
///Currently unstable for numbers > 15

#include <iostream>
#include <cstdint>
#include <thread>
#include <mutex>
#include <chrono>

static std::mutex barrier;

void fibonacciNumber(int fibNum, uint64_t* totalFib);
void fibonacciNumberThreaded(int fibNum, uint64_t* totalFib);

int main(){
	uint64_t fibTotal = 0;
	int fibNum = 0;
	std::chrono::high_resolution_clock::time_point begin, end;
	std::chrono::nanoseconds nanoDur;
	std::cout << "What fibonacci number do you wish to compute: ";
	std::cin >> fibNum;
	if(std::cin.fail() || fibNum < 1){
		std::cout << "That is an invalid number!" << std::endl;
		return 0;
	}

	begin = std::chrono::high_resolution_clock::now();
	fibonacciNumber(fibNum, &fibTotal);
	end = std::chrono::high_resolution_clock::now();
	nanoDur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "It took " << nanoDur.count() << " nanoseconds for the single threaded process to compute Fibonacci[" << fibNum << "]\n";


	fibTotal = 0;
	begin = std::chrono::high_resolution_clock::now();
	fibonacciNumberThreaded(fibNum, &fibTotal);
	end = std::chrono::high_resolution_clock::now();
	nanoDur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "It took " << nanoDur.count() << " nanoseconds for the multi-threaded process to compute Fibonacci[" << fibNum << "]" << std::endl;
	
	return 0;
}

void fibonacciNumber(int fibNum, uint64_t* totalFib){
	if(fibNum <= 0){

	}
	else if(fibNum == 1){
		*totalFib += 1;
	}
	else{
		//uint64_t num1 = *totalFib;
		//uint64_t num2 = *totalFib;
		fibonacciNumber(fibNum - 1, totalFib);
		fibonacciNumber(fibNum - 2, totalFib);
		//totalFib += num1 + num2;
	}
}
/* */

void fibonacciNumberThreaded(int fibNum, uint64_t* totalFib){
	if(fibNum <= 0){
		//Do nothing
	}
	else if(fibNum == 1){
		//This keeps more than one process trying to modify totalFib at the same time, which would result in an inaccurate number
		std::lock_guard<std::mutex> blocked(barrier);
		*totalFib += 1;
	}
	else{
		std::thread thr[2];
		thr[0] = std::thread(fibonacciNumberThreaded, fibNum - 1, totalFib);
		thr[1] = std::thread(fibonacciNumberThreaded, fibNum - 2, totalFib);
		thr[0].join();
		thr[1].join();
	}
}
/* */
