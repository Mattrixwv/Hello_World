#include <iostream>

void aFunction(int num1, int num2);
int soFunction(int num1, int num2);


int main(){
	int num1, num2;
	std::cout << "Enter the first number: ";
	std::cin >> num1;
	std::cout << "Enter the second number: ";
	std::cin >> num2;

	aFunction(num1, num2);

	std::cout << soFunction(num1, num2) << std::endl;

	std::cout << "Press Enter to continue." << std::endl;
	std::cin.ignore(10000, '\n');
	std::cin.get();

	return 0;
}
