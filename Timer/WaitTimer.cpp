//Tutorials/Timer/WaitTimer.cpp
//Matthew Ellison
// Created: 3-7-18
//Modified: 3-7-18
//This file contains an example of how to pause a thread for a certain period of time


#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>

int main(){
	int num = 10;
	std::cout << "Program Starting" << std::endl;


	std::cout << "Decrementing " << num << " seconds" << std::endl;
	for(int cnt = num;cnt >= 0;--cnt){
		//This is not exactly 10 seconds
		//It is 10 seconds + time_to_print
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << cnt << std::endl;
	}
	std::cout << "Finished decrementing" << std::endl;

	std::cout << "Waiting " << num << " seconds" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(num));
	std::cout << "Finshed waiting" << std::endl;

	std::time_t t = std::chrono::high_resolution_clock::to_time_t(std::chrono::high_resolution_clock::now());
	struct std::tm* tim = std::localtime(&t);
	tim->tm_sec += 10;
	std::cout << "Waiting until: " << tim->tm_hour << ':' << tim->tm_min << ':' << tim->tm_sec << std::endl;
	std::this_thread::sleep_until(std::chrono::high_resolution_clock::from_time_t(mktime(tim)));
	std::cout << "Time is: " << std::chrono::high_resolution_clock::to_time_t(std::chrono::high_resolution_clock::now())
			<< "\nFinished waiting!" << std::endl;

	std::cout << "Program Ending" << std::endl;
	std::cin.get();

	return 0;
}