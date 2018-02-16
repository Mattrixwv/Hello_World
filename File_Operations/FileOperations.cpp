//Tutorials/File Operations/FilesOperations.cpp
//Matthew Ellison
// Created: 12-12-173
//Modified: 12-12-17
//This file gives examples of how to use the fstream objects

#include <iostream>
#include <fstream>
#include <string>
#include <random>

int main()
{
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::fstream ioFile;
	std::default_random_engine rnd(std::random_device{}());

	///Need to add error checking
	//Write to a file
	outputFile.open("TestFile.txt");
	for(int cnt = 0;cnt < 100;++cnt)
		outputFile << rnd() << '\n';
	outputFile.close();

	//Read from a file
	inputFile.open("TestFile.txt");
	std::cout << "These are the random numbers that were generated:" << std::endl;
	while(!inputFile.eof()){
		std::string fileInput;
		std::getline(inputFile, fileInput);
		std::cout << fileInput << '\n';
	}
	inputFile.close();

	//Use ioFile
	ioFile.open("TestFile2.txt", std::ios::out);
	for(int cnt = 0;cnt < 100;++cnt)
		ioFile << rnd() << '\n';
	ioFile.flush();
	ioFile.close();

	std::cout << "\n\nThese are the random numbers written to the second file:" << std::endl;
	ioFile.open("TestFile2.txt", std::ios::in);
	while(!ioFile.eof()){
		std::string fileInput;
		std::getline(ioFile, fileInput);
		std::cout << fileInput << '\n';
	}
	ioFile.close();

	//Append a file
	ioFile.open("TestFile.txt", std::ios::app);
	ioFile << "Test Append\n";
	ioFile.close();

	//Seek in a file
	ioFile.open("TestFile2.txt", std::ios::in | std::ios::out);
	ioFile.seekg(19L, std::ios::beg);
	char fileInput;
	ioFile.get(fileInput);
	std::cout << "This is the 20th character in the file: " << fileInput << std::endl;
	ioFile.seekp(19L, std::ios::beg);
	//Writes the number just like you would if you selected the 20th byte and started typing with insert on.
	//This overwrites the file byte by byte but can leave things behind as well
	ioFile << rnd() << '\n';
	ioFile.seekg(19L, std::ios::beg);
	ioFile.get(fileInput);
	std::cout << "This is the new 20th character in the file: " << fileInput << std::endl;
	ioFile.close();
	//Create a binary file
	ioFile.open("TestFile.bin", std::ios::out | std::ios::binary);
	int num = 15;
	double num2 = 54.7;
	ioFile.write(reinterpret_cast<char*>(&num), sizeof(num));
	ioFile.write(reinterpret_cast<char*>(&num2), sizeof(num2));
	ioFile.close();
	int inNum = 0;
	double inNum2 = 0;
	ioFile.open("TestFile.bin", std::ios::in | std::ios::binary);
	ioFile.read(reinterpret_cast<char*>(&inNum), sizeof(inNum));
	ioFile.read(reinterpret_cast<char*>(&inNum2), sizeof(inNum2));
	std::cout << "The integer read from the file is: " << inNum
			<< "\nThe double read from the file is: " << inNum2 << std::endl;

	return 0;
}
