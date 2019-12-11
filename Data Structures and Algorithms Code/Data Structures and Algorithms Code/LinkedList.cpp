#include "LinkedList.h"

//default constructor
template<class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	count = 0;
}

//constructor with head data
template<class T>
LinkedList<T>::LinkedList(T first){
	head = new Node<T>(first, nullptr);
	count++;
}

//adds value at head position
template<class T>
void LinkedList<T>::addFirst(T value) {
	head = new Node<T>(value, head);
	count++;
}

//adds value at tail position
template<class T>
void LinkedList<T>::addLast(T value) {
	if (head == nullptr) {
		head = new Node<T>(value, nullptr);
		return;
	}
	Node<T>* node = head;
	while (node->getNext() != nullptr) {
		node = node->getNext();
	}
	node->setNext(new Node<T>(value, nullptr));
	count++;
}

//remove value at head position
template<class T>
T LinkedList<T>::removeFirst() {
	Node<T>* node = head;
	head = head->getNext();
	T val = node->getValue();
	delete node;
	count--;
	return val;
}

//remove value at tail position
template<class T>
T LinkedList<T>::removeLast() {
	Node<T>* node = head;
	T val;
	//if head is last node
	if (node->getNext() == nullptr) {
		val = node->getValue();
		head = nullptr;
	}
	else {
		while (node->getNext()->getNext() != nullptr) {
			node = node->getNext();
		}
		val = node->getNext()->getValue();
		node->setNext(nullptr);
	}
	count--;
	return val;
}


//adds value after first node with designated value
template<class T>
void LinkedList<T>::insertAfter(T val, T toInsert) {
	Node<T>* node = head;
	while (node != nullptr) {
		if (node->getValue() == val) {
			Node<T>* insert = new Node<T>(val, node->getNext());
			node->setNext(insert);
			return;
		}
		node = node->getNext();
	}
}

//adds value before node with designated value
template<class T>
void LinkedList<T>::insertBefore(T val, T toInsert) {
	Node<T>* node = head;
	while (node->getNext() != nullptr) {
		if (node->getNext()->getValue() == val) {
			Node<T>* insert = new Node<T>(val, node->getNext());
			node->setNext(insert);
			return;
		}
		node = node->getNext();
	}
}

//remove item with designated value; returns null if value is not found
template<class T>
Node<T>* LinkedList<T>::remove(T val) {
	if (size() < 1) return nullptr;
	Node<T>* node = head;
	while (node->getNext() != nullptr) {
		if (node->getNext()->getValue() == val) {
			Node<T> *remove = node->getNext();
			Node<T>* connect = remove->getNext();
			node->setNext(remove->getNext());
			delete remove;
			count--;
			return node;
		}
		node = node->getNext();
	}
	return nullptr;
}

//remove item at designated position; returns null if position is out of bounds
template<class T>
T LinkedList<T>::removeAtPosition(int i) {
	if (size() < 1) return nullptr;
	Node<T>* node = head;
	if (i > count - 1)
		return nullptr;
	while (i > 0) {
		i--;
		node = node->getNext();
	}
	delete node;
	count--;
	return node->getValue();

}

//return size of linked list
template<class T>
int LinkedList<T>::size() {
	return count;
}