#include<iostream>
#include "Customer.h"

//int GlobId = 0;

Customer::Customer(int id, string name, string address)
{
	this->id = id;
	this->name = name;
	this->address = address;
}

int Customer::getId() const
{
	return this -> id;
}
string Customer::getName() const
{
	return this->name;
}

string Customer::getAddress() const
{
	return this->address;
}

void Customer::display() const
{
	std::cout << "~ Customer ~" << std::endl;
	std::cout << "ID:" << getId() << std::endl;
	std::cout << "Name:" << getName() << std::endl;
	std::cout << "Address:" << getAddress()<< std::endl;
}

