//Tutorials/Namespace/MyNamespace.cpp
//Matthew Ellison
// Created: 12-18-17
//Modified: 12-18-17
//This file contains the implementations of the functions in the header file

#include "MyNamespace.h"


template <class T>
T myNamespace::difference(T num1, T num2){
	return num1 - num2;
}
template myNamespace::difference<int>;
template myNamespace::difference<double>;

template <class T>
T myNamespace::divide(T num1, T num2){
	return num1 / num2;
}
template myNamespace::divide<int>;
template myNamespace::divide<double>;


template <class T>
T yourNamespace::difference(T num1, T num2){
	return num2 - num1;
}
template yourNamespace::difference<int>;
template yourNamespace::difference<double>;

template <class T>
T yourNamespace::divide(T num1, T num2){
	return num2 / num1;
}
template yourNamespace::divide<int>;
template yourNamespace::divide<double>(double num1, double num2);
