//Tutorials/Linked List/LinkedList.h
//Matthew Ellison
// Created: 12-9-17
//Modified: 12-9-17
//This file contains the declaration of the LinkedList class
//This is a practice of how to create a Linked List as well as a template class
//This array is simple and doesn't shrink if necessary
//I also tested this class with valgrind to check for memory leaks

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class LinkedList
{
private:
	struct Node{
		T info;
		Node* next;
		Node(T info, Node* next = nullptr){
			this->info = info;
			this->next = next;
		}
	};

	Node* head;
	Node* tail;
	unsigned long int size;
public:
	LinkedList(){
		head = tail = nullptr;
		size = 0;
	}
	LinkedList(T item){
		head = tail = nullptr;
		size = 0;
		push(item);
	}
	~LinkedList(){
		Node * current = head;
		Node * previous = nullptr;
		//Traverse the list and delete the nodes along the way
		while(current != nullptr){
			previous = current;
			current = current->next;
			delete previous;
		}
	}
	unsigned long int getSize(){
		return size;
	}
	//Add items to the array
	void push(T item){
		push(item, (size));
	}

	void push(T item, unsigned long int location){	//Add an item at node location
		//If location is out-of-bounds return
		///Throwing an error would be better
		if(location > size || location < 0){
			return;
		}
		//If you are trying to insert something at the beginning of the list you need to move the head pointer
		if(location == 0){
			head = new Node(item, head);
			//Check if that was the first element added and adjust the tail pointer if necessary
			if(tail == nullptr)
				tail = head;
		}
		//If you are trying to insert something at the end of the list you need to move the tail pointer
		else if(location == size){
			tail->next = new Node(item);
			tail = tail->next;
		}
		//If you are trying to insert something in the middle you can ignore the special pointers
		else{
			Node* currentNode = head;

			int loc = 1;
			//Traverse the list until you reach the correct location
			while(loc < location){
				currentNode = currentNode->next;
				++loc;
			}
			//You don't need to error check for out of bounds at this point, it was done earlier
			currentNode->next = new Node(item, currentNode->next);
		}
		++size;
	}
	T pop(){
		return pop(size - 1);
	}
	T pop(unsigned long int location){	//Remove the item at arr[location]
		//Check if location is out-of-bounds
		if(location < 0)
			location = 0;
		else if(location >= size)
			location = size - 1;
			//Throwing exceptions would be better than adjusting the location because of possibly deleting unintended info
		T temp;
		//Check if you are popping the first element and move the head pointer
		if(location == 0){
			temp = head->info;
			if(size == 1){
				delete head;
				head = tail = nullptr;
			}
			else{
				Node* nodeTemp = head;
				head = head->next;
				delete nodeTemp;
			}
		}
		//Check if you are popping the last element and move the tail pointer
		else if(location == (size - 1)){
			temp = tail->info;
			Node* nodeTemp = head;
			//Look for the new end to the list
			while(nodeTemp->next != tail)
				nodeTemp = nodeTemp->next;
			delete tail;
			tail = nodeTemp;
		}
		//If you are popping something in the middle don't worry about any of the special pointers
		else{
			Node* currentNode = head;
			//Loop assuming you are looking at currentNode->next
			//This allows you to remove a node without having to have a previous pointer
			for(int cnt = 1;cnt < location;++cnt)
				currentNode = currentNode->next;
			temp = currentNode->next->info;
			Node* nodeTemp = currentNode->next->next;
			delete currentNode->next;
			currentNode->next = nodeTemp;
		}
		--size;
		return temp;
	}
	void sort(){	//Sort the array
		//Implement a bubble sort
	}
	T& at(unsigned long int location){	//Look at the item at location
		if(location < 0)
			location = 0;
		else if (location >= size)
			location = size - 1;
			//Throwing an error would be better
		if(location == 0)
			return head->info;
		else if(location == (size - 1))
			return tail->info;
		else{
			Node* currentNode = head;
			for(int cnt = 0;cnt < location;++cnt)
				currentNode = currentNode->next;
			return currentNode->info;
		}
	}
	T& operator[](unsigned long int location){
		return at(location);
	}	//Same as at(), just using [] notaion
};

#endif
