#include "ArrayList.h"

//create array with default size 2
template<class T>
ArrayList<T>::ArrayList(){
	realSize = 2;
	count = 0;
	data = new T[realSize];
}

//destructor
template<class T>
ArrayList<T>::~ArrayList() {
	delete []data;
}

//inserts value at index
template<class T>
void ArrayList<T>::set(T val, int index) {
	if (!isValid(index)) return;
	//if index is greater than current size, expand
	while (index >= realSize || count >= realSize) {
		expand();
	}
	data[index] = val;
	count++;
}

//return value at index
template<class T>
T ArrayList<T>::get(int index) {
	if (!isValid(index)) return 0;
	return data[index];
}

//get index of value
template<class T>
int ArrayList<T>::indexOf(T value) {
	for (int i = 0; i < count; i++) {
		if (data[i] == value)
			return i;
	}
	return -1;
}

template<class T>
int ArrayList<T>::size() {
	return count;
}

template<class T>
void ArrayList<T>::expand() {
	//double array size
	T* newData = new T[realSize * 2];
	//replace data
	for (int i = 0; i < realSize; i++) {
		newData[i] = data[i];
	}
	realSize = realSize * 2;
	delete[]data;
	data = newData;
}

template<class T>
bool ArrayList<T>::isValid(int index) {
	return index >= 0;
}
