#include "stdafx.h"
#include<iostream>
#include"Building.h"
#include"House.h"

House::House(const int storeysNum, const char* owner ):Building()
{
	setStoreys(storeysNum);
	owner = new char[10];
	setOwner(owner);
}

House::House(const House& h): Building(h)
{
	setStoreys(h.getStoreys());
	
}

House& House::operator=(const House& h)
{
	Building::operator=(h);

}
House::~House()
{

}

void House::setStoreys(const int&)
{

}
int House::getStoreys() const
{

}

void House::setOwner(const char*&)
{

}

char* House::getOwner() const
{

}
