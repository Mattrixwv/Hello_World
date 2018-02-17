//Tutorials/Linked List/LinkedList.h
//Matthew Ellison
// Created: 12-9-17
//Modified: 12-9-17
//This file contains the test function for the LinkedList class

#include "LinkedList.h"
#include <iostream>

int main()
{
	LinkedList<int> ll1;

	for(int cnt = 0;cnt < 10;++cnt)
		ll1.push(cnt * 5);
	ll1.push(500, 5L);
	for(int cnt = 0;cnt < ll1.getSize();++cnt)
		std::cout << cnt + 1 << ". " << ll1[cnt] << '\n';
	std::cout << "pop(): " <<	ll1.pop() << std::endl;
	std::cout << "pop(3): " << ll1.pop(3) << std::endl;
	std::cout << "pop(0): " << ll1.pop(0) << std::endl;
	for(int cnt = 0;cnt < ll1.getSize();++cnt)
		std::cout << cnt + 1 << ". " << ll1[cnt] << '\n';
	std::cout << "pop(): " << ll1.pop() << std::endl;

	std::cout << "Press Enter to exit" << std::endl;
	std::cin.get();

	return 0;
}
