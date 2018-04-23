#include "stdafx.h"
#include <iostream>
#include "Stack.h"

Stack::Stack()
{
	length = MAX;//MAX=100
	arr = new double[length];
	upperIndex = 0;//in the start there are 0 elements in the stack
}

Stack::Stack(Stack const& s)
{
	this->length = s.length;
	this->upperIndex = s.upperIndex;
	this->arr = new double[length];
	for (int i = 0; i < upperIndex; i++)
	{
		arr[i] = s.arr[i];
	}
}

Stack& Stack::operator=(Stack const& s)
{
	if(this!=&s)
	{
		delete[] this->arr;	
		this->length = s.length;
		this->upperIndex = s.upperIndex;
		arr = new double[length];
		for (int i = 0; i < upperIndex; i++)
		{
			arr[i] = s.arr[i];
		}
	}
	return *this;
}

Stack::~Stack()
{
	delete[] this->arr;
}

bool Stack::isEmpty()
{
	if (upperIndex == 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Stack::isFull()
{
	if (upperIndex == length - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Stack::doubling()
{
	if (this->isFull())//if the stack is full, doubling its size
	{
		double *newArr = new double[2 * length];//new doubled array
		for (int i = 0; i < length; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		this->arr = newArr;
		length *= 2;
	}
}

double Stack::peek()
{
	if (this->isEmpty())//if the stack is empty
	{
		std::cout << "Error, the stack is empty!";
		return 0;
	}
	else
	{
		return arr[upperIndex - 1];
	}
}

double Stack::pop()
{
	if (this->isEmpty())//id the stack is empty
	{
		std::cout << "Error, the stack is empty!";
		return 0;
	}
	else
	{
		upperIndex--;//removing element
		return arr[upperIndex];//returning the upper element
	}
}

void Stack::push(double n)
{
	if (this->isFull())//if the stack is full, doubling its size
	{
		this->doubling();
	}
	upperIndex++;//adding element
	arr[upperIndex - 1] = n;
}

int Stack::size()
{
	return upperIndex;//index of upper element = size of stack
}
