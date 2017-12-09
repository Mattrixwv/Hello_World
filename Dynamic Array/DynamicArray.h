//Tutorials/Dynamic Array/DynamicArray.h
//Matthew Ellison
// Created: 12-7-17
//Modified: 12-9-17
//This file contains the declaration of the DynamicArray class
//This is a practice of how to create a dynamic array as well as a template class
//This array is simple and doesn't shrink if necessary
//I also tested this class with valgrind to check for memory leaks

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <class T>
class DynamicArray
{
private:
	T* arr;
	unsigned long int size;
	unsigned long int maxSize;
	void expand();	//Helper function that makes the array larger if it is full
	void sort(int low, int high);		//Sorts the array
	unsigned int partition(int low, int high);	//Helper function for sort
public:
	DynamicArray();
	DynamicArray(T item);
	~DynamicArray();
	unsigned long int getSize()	{	return size;	}
	unsigned long int getMax()	{	return maxSize;	}
	//Add items to the array
	void push(T item)	{	push(item, (size));	}
	void push(T item, unsigned long int location);	//Add an item at arr[location]
	T pop()	{	return pop(size - 1);	}
	T pop(unsigned long int location);	//Remove the item at arr[location]
	void sort()	{	sort(0, (size - 1));	}	//Sort the array
	T& at(unsigned long int location);	//Look at the item at arr[location]
	T& operator[](unsigned long int location)	{	return at(location);	}	//Same as at(), just using array location
};

#endif
