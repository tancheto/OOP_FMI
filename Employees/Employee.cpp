#include "Employee.h"

Employee::Employee(string name)
{
	setName(name);
}

void Employee::setName(string name)
{
	this->name = name;
}

string Employee::getName() const
{
	return this->name;
}
