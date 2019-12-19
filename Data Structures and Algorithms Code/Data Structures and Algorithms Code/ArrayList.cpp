#include "ArrayList.h"

//create array with default size 2
template<class T>
ArrayList<T>::ArrayList(int size) :
	realSize(size)
{
	data = new T[realSize];
}

//create array with default size 2 and given default value
template<class T>
ArrayList<T>::ArrayList(T defaultValue, int size) :
	ArrayList(size)
{
	defaultVal = defaultValue;
	for (int i = 0; i < realSize; i++) {
		data[i] = defaultVal;
	}
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
	while (index >= realSize) {
		expand();
	}
	data[index] = val;
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
	for (int i = 0; i < realSize; i++) {
		if (data[i] == value)
			return i;
	}
	return -1;
}

template<class T>
void ArrayList<T>::expand() {
	//double array size
	T* newData = new T[realSize * 2];
	//replace data
	for (int i = 0; i < realSize; i++) {
		newData[i] = data[i];
	}
	for (int i = realSize; i < realSize * 2; i++) {
		newData[i] = defaultVal;
	}
	realSize = realSize * 2;
	delete[]data;
	data = newData;
}

template<class T>
bool ArrayList<T>::isValid(int index) {
	return index >= 0;
}
