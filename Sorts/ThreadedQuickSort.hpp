//Tutorials/Sorts/ThreadedQuickSort.hpp
//Matthew Ellison
// Created: 3-7-18
//Modified: 3-7-18
//This file implements a Quick sort using threads


#ifndef THREADED_QUICK_SORT_HPP
#define THREADED_QUICK_SORT_HPP

#include <thread>


namespace mee{

//Prototypes
template<class T>
void threadedQuickSort(T& ary, unsigned int arraySize);
template<class T>
void threadedQuickSort(T& ary, int bottom, int top);
template<class T>
int threadedPartition(T& ary, int bottom, int top);



template<class T>
void threadedQuickSort(T& ary, unsigned int arraySize){
	quickSort(ary, 0, arraySize - 1);
}

template<class T>
void threadedQuickSort(T& ary, int bottom, int top){
	if(bottom < top){
		int pos = threadedPartition(ary, bottom, top);
		std::thread threads[2];
		threads[0] = std::thread(threadedQuickSort, ary, bottom, pos - 1);
		threads[1] = std::thread(threadedQuickSort, ary, pos + 1, top);
		threads[0].join();
		threads[1].join();
	}
}

template<class T>
int threadedPartition(T& ary, int bottom, int top){
	int pivot = ary[top];
	int num = bottom - 1;

	for(int cnt = bottom;cnt <= top - 1;++cnt){
		if(ary[cnt] <= pivot){
			++num;
			std::swap(ary[num], ary[cnt]);
		}
	}

	std::swap(ary[num + 1], ary[top]);
	return num + 1;
}

} //namespce mee

#endif //THREADED_QUICK_SORT_HPP
