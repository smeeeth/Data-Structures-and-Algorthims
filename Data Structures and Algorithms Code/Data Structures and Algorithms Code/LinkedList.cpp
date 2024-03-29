#include "LinkedList.h"
#include <stdexcept>

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

//delete list
template<class T>
LinkedList<T>::~LinkedList() {
	if (head == nullptr) return;
	Node<T>* node = head;
	Node<T>* next;
	while (node->getNext() != nullptr) {
		next = node->getNext();
		delete node;
		node = next;
	}
	delete node;
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
			Node<T>* insert = new Node<T>(toInsert, node->getNext());
			node->setNext(insert);
			count++;
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
			Node<T>* insert = new Node<T>(toInsert, node->getNext());
			node->setNext(insert);
			count++;
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
			count--;
			return node;
		}
		node = node->getNext();
	}
	return nullptr;
}

//remove item at designated position; throws exception if position is out of bounds
template<class T>
T LinkedList<T>::removeAtPosition(int i) {
	if (i > count - 1) throw out_of_range("Invalid Index");
	Node<T>* node = head;
	T val;
	//if removing head
	if (i == 0) {
		val = head->getValue();
		head = head->getNext();
	}
	else {
		while (i > 0) {
			i--;
			node = node->getNext();
		}
		val = node->getValue();
		node = node->getNext();
	}
	count--;
	return val;
}

//return size of linked list
template<class T>
int LinkedList<T>::size() {
	return count;
}