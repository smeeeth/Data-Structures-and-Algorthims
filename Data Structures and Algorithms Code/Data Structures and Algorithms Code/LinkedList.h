#pragma once
#include "Node.h"

using namespace std;

template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(T first);
	~LinkedList();
	void addFirst(T value);
	void addLast(T value);
	T removeFirst();
	T removeLast();
	void insertAfter(T val, T toInsert);
	void insertBefore(T val, T toInsert);
	Node<T>* remove(T val);
	T removeAtPosition(int i);
	int size();

private:
	Node<T> *head;
	int count;
};

