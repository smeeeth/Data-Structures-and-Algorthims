#pragma once
#include "LinkedList.h"

using namespace std;

template<class T>
class Stack :
	protected LinkedList<T>
{
public:
	Stack();
	Stack(T first);
	void push(T val);
	T pop();
	T peek();
	int size();
};

