#pragma once
#include "LinkedList.h"

using namespace std;

template <class T>
class Queue : 
	protected LinkedList<T>
{
public:
	Queue();
	Queue(T first);
	void enqueue(T val);
	T dequeue();
	int size();
};

