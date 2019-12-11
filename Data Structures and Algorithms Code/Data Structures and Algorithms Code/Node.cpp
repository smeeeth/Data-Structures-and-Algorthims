#include "Node.h"

//default constructor
template<class T>
Node<T>::Node()
{
}

//constructor with arguments
template<class T>
Node<T>::Node(T& item, Node<T>* next)
{
	this->value = item;
	this->next = next;
}

//getter for next node
template<class T>
Node<T>* Node<T>::getNext()
{
	return this->next;
}

//setter for next node
template<class T>
void Node<T>::setNext(Node<T>*	node)
{
	this->next = node;
}

//getter for value
template <class T>
T Node<T>::getValue() {
	return this->value;
}