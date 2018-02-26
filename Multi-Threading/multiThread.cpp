//Tutorials/Multi-Threading/multiThread.cpp
//Matthew Ellison
// Created: 2-26-18
//Modified: 2-26-18
//This file contains an example of how to multi-thread an application

#include <iostream>
#include <thread>
#include <atomic>

//*Program will not compile if you try to pass by reference
void threadedFunction(int* num);

int main(){
	std::thread thr[2];
	int num1 = 2;
	int num2 = 4;
	thr[0] = std::thread(threadedFunction, &num1);
	thr[1] = std::thread(threadedFunction, &num2);
	thr[0].join();
	thr[1].join();
	std::cout << num1 << '\t' << num2 << std::endl;

	return 0;
}
/* */

void threadedFunction(int* num){
	*num *= 2;
}
