
#include "stdafx.h"
#include<iostream>
#include"Building.h"

int StrLen(char* Str)
{
	int Counter = 0;
	while (Str[Counter] != '\0')
	{
		Counter++;
	}
	return Counter;
}

void WidenLen(char* &Str)
{
	int i = 0;
	char* NewStr = new char[2 * StrLen(Str) + 1];
	for (i = 0; i <= StrLen(Str); i++)
	{
		NewStr[i]=Str[i];
	}
	NewStr[i] = '\0';
	delete[] Str;
	Str = NewStr;
}

void StrCpy(char* &destination, const char* source)
{
	int CharCount = 0;
	while (source[CharCount] != '\0')
	{
		if (CharCount == StrLen(destination))
		{
			WidenLen(destination);
		}
		destination[CharCount] = source[CharCount];
		CharCount++;
	}
	destination[CharCount] = '\0';//terminating zero
}

void Building::CopyBuilding(const Building &b)
{
	this->setHeight(b.getHeight());
	this->setArea(b.getArea());
	this->address = new char[10];

	int counter = 0;
	while (b.address[counter] != '\0')
	{
		if (StrLen(b.address) == counter)
		{
			WidenLen(this->address);
		}
		this->address[counter] = b.address[counter];
		counter++;
	}
	this->address[counter] = '\0';
}

Building::Building(const int height, const double area, const char* address)
{
	this->setHeight(height);
	this->setArea(area);
	this->address = new char[10];
	this->setAddress(address);
}

Building::Building(const Building &b)
{
	CopyBuilding(b);
}

Building& Building::operator=(const Building &b)
{
	delete[] this->address;

	CopyBuilding(b);
	return *this;
}

Building::~Building()
{
	delete[] this->address;
}

void Building::setHeight(const int& height )
{
	this->height = height;
}

int Building::getHeight()const
{
	return this->height;
}

void Building::setArea(const double& area)
{
	this->area = area;
}

double Building::getArea()const
{
	return this->area;
}

void Building::setAddress(const char* &address)
{
	StrCpy(this->address, address);
}

char* Building::getAddress()const
{
	return this->address;
}

void Building::printAll() const
{
	std::cout << "Address:";
	int i = 0;
	while (this->address[i] != '\0')
	{
		std::cout << this->address[i];
		i++;
	}

	std::cout << std::endl << "Height:" << this->getHeight() << std::endl << "Area:" << this->getArea() << std::endl;
}