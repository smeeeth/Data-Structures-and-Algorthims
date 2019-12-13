#pragma once

using namespace std;

template <class T>
class Node
{
public:
	Node();
	Node(T& item, Node<T>* next = NULL);
	~Node();
	//accessors
	Node<T>* getNext();
	void setNext(Node<T>* node);
	T getValue();

private:
	Node<T>* next;
	T value;

};

