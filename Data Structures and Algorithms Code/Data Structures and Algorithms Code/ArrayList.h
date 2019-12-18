#pragma once

using namespace std;

template <class T>
class ArrayList
{
public:
	ArrayList();

	~ArrayList();

	void set(T val, int index);

	T get(int index);

	int indexOf(T val);

	int size();

private:
	int count;
	int realSize;
	T* data = nullptr;

	void expand();

	bool isValid(int index);

};

