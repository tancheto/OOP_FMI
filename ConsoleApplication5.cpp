// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#pragma warning(disable: 4996)

class stack
{
private:
	int length;
	int *arr = new int[length];

	
public:
	void SetLength(int length)
	{
		this->length = length;
	}
	void SetArr(int *arr)
	{
		for (int i = 0; i < this->length; i++)
		{
			this->arr[i] = arr[i];
		}
	}
	int GetLength()
	{
		return this->length;
	}
	void GetArr()
	{
		for (int i = 0; i < this->length; i++)
		{
			std::cout << this->arr[i] << " ";
		}
	}
	void pushElem(int elem)
	{
		arr[length] = elem;
		length++;
	}
	void popElem()
	{
		arr[length - 1] = NULL;
		length--;
	}
	int peekElem()
	{
		return arr[length - 1];
	}
};

int main()
{
	int mas[6] = { 0,1,2,3,4,5 };
	stack Tanya;
	Tanya.SetLength(6);
	Tanya.SetArr(mas);
	std::cout << Tanya.GetLength() << std::endl;
	Tanya.GetArr();
	std::cout<<std::endl;

	Tanya.pushElem(3);
	Tanya.GetArr();
	std::cout << std::endl;
	Tanya.popElem();
	Tanya.GetArr();
	std::cout << std::endl;
	std::cout<<Tanya.peekElem()<<std::endl;

    return 0;

}

