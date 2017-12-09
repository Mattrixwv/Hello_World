//Tutorials/Dynamic Array/DynamicArray.h
//Matthew Ellison
// Created: 12-7-17
//Modified: 12-7-17
//This file contains the implementation of the DynamicArray class


#include "DynamicArray.h"
#include <string>


template <class T>
void DynamicArray<T>::expand(){	//Helper function that makes the array larger if it is full
	if(maxSize == 0){
		arr = new T[1];
		maxSize = 1;
	}
	else{
		maxSize *= 2;
		T* temp = new T[maxSize];
		///Should do some error checking for inability to allocate
		///bad_alloc
		//Copy the elements over
		for(int cnt = 0;cnt < size;++cnt)
			temp[cnt] = arr[cnt];
		//Delete and copy the pointer over
		delete[] arr;
		arr = temp;
	}
}

template <class T>
DynamicArray<T>::DynamicArray(){
	arr = nullptr;
	size = 0;
	maxSize = 0;
}

template <class T>
DynamicArray<T>::DynamicArray(T item){
	arr = nullptr;
	size = 0;
	maxSize = 0;
	push(item);
}

template <class T>
DynamicArray<T>::~DynamicArray(){
	delete[] arr;
	arr = nullptr;
	size = 0;
	maxSize = 0;
}

//Add items to the array
template <class T>
void DynamicArray<T>::push(T item, unsigned long int location){	//Add an item at arr[location]
	if((location < 0) || (location > size))
		return;
	else if(size == maxSize)
		expand();

	//Move everything from location to the end, down
	for(int cnt = size;cnt > location;--cnt)
		arr[cnt] = arr[cnt - 1];
	//Add the element
	arr[location] = item;
	++size;
}

template <class T>
T DynamicArray<T>::pop(unsigned long int location){	//Remove the item at arr[location]
	T temp;
	//Error check location
	if(location < 0 || location >= size)
		return temp;
		//Thowing an exception would be better

	//Grab the element
	temp = arr[location];
	//Move all elements beyond location back one
	for(int cnt = (location + 1);cnt < size;++cnt)
		arr[cnt - 1] = arr[cnt];
	--size;
	//This would be where you would put in shrinking code
}

template <class T>
void DynamicArray<T>::sort(){	//Sort the array
	//Sorting algorithm
}

template <class T>
T& DynamicArray<T>::at(unsigned long int location){	//Look at the item at arr[location]
	//Error checking
	if(location < 0)
		return arr[0];
	else if(location >= size)
		return arr[size - 1];
	//Throwing exceptions would be better

	//Return the element at location
	else
		return arr[location];
}

//When dealing with a template class there are two ways to allow you to compile without getting an
//"undefined reference" error.
//The first is to move all of your implementation to the .h file.
//This causes all of your functions to be declared as inline functions, resulting better performance but
//also in greater program size. This also allows others to see your code if you do not wish that to happen
//The second is to explicitly declare all of the types it will support.
//This limits the types that people can use, but also keeps your class from being used with untested
//types. This means that you must forsee every types that someone might want to use however. This also
//creates the problem of the compiler having to create functions for each of the types listed in the .o
//file, creating a much longer compile time.
//I chose this route to prove that it could be done. I was also having trouble getting my class to work
//with strings for some reason. I never did figure out why, but I changed the destructor and it now seems
//to work. If you run into any problems with that please leave an error report on my github page so I
//can try to patch it.
//However, with something like a dynamic array or a linked list you should really move your implememntation
//into your header file because it should work the same way for all possible classes.
//To see an example of this see my LinkedList project

template class DynamicArray<int>;
template class DynamicArray<unsigned int>;
template class DynamicArray<long int>;
template class DynamicArray<unsigned long int>;
template class DynamicArray<long long int>;
template class DynamicArray<unsigned long long>;
template class DynamicArray<char>;
template class DynamicArray<unsigned char>;
template class DynamicArray<float>;
template class DynamicArray<double>;
template class DynamicArray<std::string>;
