//Tutorials/Sorts/BubbleSort.hpp
//Matthew Ellison
// Created: 3-7-18
//Modified: 3-7-18
//This file implements a Bubble sort


#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

namespace mee{

template<class T>
void bubbleSort(T& ary, unsigned int arraySize){
	for(int outCnt = 0;outCnt < arraySize - 1;++outCnt){
		for(int inCnt = 0;inCnt < arraySize - outCnt - 1;++inCnt){
			if(ary[inCnt] > ary[inCnt + 1]){
				std::swap(ary[inCnt],ary[inCnt + 1]);
			}
		}
	}
}

} //namespace mee

#endif //BUBBLE_SORT_HPP
