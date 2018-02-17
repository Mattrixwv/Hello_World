//This file contains the test functions for returning a function from a function
#include <iostream>
#include <functional>


typedef int (*intFn)();
typedef int (*intFn2)(int);

intFn myFunction(int num);
int myReturnedFunction1();
int myReturnedFunction2(int num);
void myReturnedFunction();


int main()
{
	intFn funct;
	funct = myFunction(1);
	std::cout << funct() << std::endl;
	intFn2 funct2 = &myReturnedFunction2;
	std::cout << funct2(5) << std::endl;
	//This is the C++11 way to do this
	std::function<void()> funct3 = myReturnedFunction;
	funct3();

	std::cout << "Press Enter to exit" << std::endl;
	std::cin.get();

	return 0;
}


intFn myFunction(int num){
	if(num == 1)
		return myReturnedFunction1;
	else
		return nullptr;
}

int myReturnedFunction1(){
	return 1;
}

int myReturnedFunction2(int num){
	return num * num;
}

void myReturnedFunction(){
	std::cout << "This is the void function" << std::endl;
}
