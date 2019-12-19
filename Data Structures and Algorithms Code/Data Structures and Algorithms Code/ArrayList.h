#pragma once

using namespace std;

template <class T>
class ArrayList
{
public:
	ArrayList(int size = 2);

	ArrayList(T defaultVal, int size = 2);

	~ArrayList();

	void set(T val, int index);

	T get(int index);

	int indexOf(T val);

	int size();

private:
	int realSize;
	T* data = nullptr;
	T defaultVal;

	void expand();

	bool isValid(int index);

};

