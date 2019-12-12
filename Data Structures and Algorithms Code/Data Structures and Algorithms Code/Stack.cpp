#include "Stack.h"

template<class T>
Stack<T>::Stack() : LinkedList<T>() {

}

template<class T>
Stack<T>::Stack(T first) : LinkedList<T>(first) {

}

template<class T>
void Stack<T>::push(T val) {
	addFirst(val);
}

template<class T>
T Stack<T>::pop() {
	return LinkedList<T>::removeLast();
}

template<class T>
T Stack<T>::peek() {
	T val = LinkedList<T>::removeLast();
	addLast(val); //replace value at end of stack
	return val;
}

template<class T>
int Stack<T>::size() {
	return LinkedList<T>::size();
}