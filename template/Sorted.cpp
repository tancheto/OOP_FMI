#include "stdafx.h"
#include<iostream>
template <class T>

class Sorted
{
private:
	T* arr;
	int size;
public:
	Sorted();
	Sorted(const Sorted& s);
	Sorted& operator=(const Sorted& s);
	~Sorted();
};

template <class T>
Sorted<T>::Sorted() :arr(nullptr), size(10)
{}

template <class T>
Sorted<T>::Sorted(const Sorted& s)
{
	this->size = s.size;
	this->arr = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = s.arr[i];
	}
}

template <class T>
Sorted<T>::Sorted& operator=(const Sorted& s)
{
	delete[] this->arr;
	this->size = s.size;
	this->arr = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = s.arr[i];
	}

	return *this;
}

template <class T>
Sorted<T>::~Sorted()
{
	delete[] this->arr;
}
