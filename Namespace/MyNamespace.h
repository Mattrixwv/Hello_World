//Tutorials/Namespace/MyNamespace.h
//Matthew Ellison
// Created: 12-18-17
//Modified: 12-18-17
//This file contains the declarations of several functions in two different namespaces

namespace myNamespace{
	template <class T>
	T difference(T num1, T num2);

	template <class T>
	T divide(T num1, T num2);
}

namespace yourNamespace{
	template <class T>
	T difference(T num1, T num2);

	template <class T>
	T divide(T num1, T num2);
}
