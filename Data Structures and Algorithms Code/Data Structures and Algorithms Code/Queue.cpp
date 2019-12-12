#include "Queue.h"

//default constructor
template<class T>
Queue<T>::Queue() : LinkedList<T>(){
}

template<class T>
Queue<T>::Queue(T first) : LinkedList<T>(first) {
}

template<class T>
void Queue<T>::enqueue(T val) {
	addFirst(val);
}

template<class T>
T Queue<T>::dequeue() {
	return LinkedList<T>::removeFirst();
}

template<class T>
int Queue<T>::size() {
	return LinkedList<T>::size();
}