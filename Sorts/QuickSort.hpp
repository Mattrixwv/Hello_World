//Tutorials/Sorts/QuickSort.hpp
//Matthew Ellison
// Created: 3-7-18
//Modified: 3-7-18
//This file implements a Quick sort


#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP


namespace mee{

//Prototypes
template<class T>
void quickSort(T& ary, unsigned int arraySize);
template<class T>
void quickSort(T& ary, int bottom, int top);
template<class T>
int partition(T& ary, int bottom, int top);


template<class T>
void quickSort(T& ary, unsigned int arraySize){
	quickSort(ary, 0, arraySize - 1);
}

template<class T>
void quickSort(T& ary, int bottom, int top){
	if(bottom < top){
		int pos = partition(ary, bottom, top);
		quickSort(ary, bottom, pos - 1);
		quickSort(ary, pos + 1, top);
	}
}

template<class T>
int partition(T& ary, int bottom, int top){
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

} //namespace mee

#endif //QUICK_SORT_HPP
