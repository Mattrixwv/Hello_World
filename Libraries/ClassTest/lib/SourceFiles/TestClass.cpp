#include "TestClass.h"

TestClass::TestClass(int num){
	this->num = num;
}

int TestClass::add(int num){
	return this->num + num;
}

int TestClass::getNum(){
	return num;
}
