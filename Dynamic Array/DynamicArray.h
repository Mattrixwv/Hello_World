//Tutorials/Dynamic Array/DynamicArray.h
//Matthew Ellison
// Created: 12-7-17
//Modified: 12-7-17
//This file contains the declaration of the DynamicArray class
//This is a practice of how to create a dynamic array as well as a template class
//This array is simple and doesn't shrink if necessary

template <class T>
class DynamicArray
{
private:
	T* arr;
	unsigned long size;
	unsigned long maxSize;
	void expand();	//Helper function that makes the array larger if it is full
public:
	DynamicArray();
	DynamicArray(T item);
	~DynamicArray();
	unsigned long getSize();
	unsigned long getMax();
	//Add items to the array
	void push(T item);	//Add an item at the end of the array
	void push(unsigned long location, T item);	//Add an item at arr[location]
	T pop(unsigned long location = size);	//Remove the item at arr[location]
	void sort();	//Sort the array
	T at(unsigned long location = size);	//Look at the item at arr[location]
	T operator[](unsigned long location = size)	{	return at(location);	}	//Same as at(), just using array location
};
