

#include<iostream>
#include "Header.h"
#pragma warning(disable: 4996)

void Grade::setValue(double value)
{
	if (value < 2 || value>6)
	{
		std::cout << "Invalid grade!" << std::endl;
	}
	else
	{
		this->value = value;
	}
}

double Grade::getValue()
{
	return this->value;
}

void Grade::setSubject(char subject[])
{
	int i = 0;
	while (subject[i] != '\0')
	{
		this->subject[i] = subject[i];
		i++;
	}
	this->subject[i] = '\0';
}

char *Grade::getSubject()
{
	return this->subject;
}

Grade::Grade(double value, char* subject)
{
	setValue(value);
	setSubject(subject);
}

void setName(char name[])
{
	int i = 0;
	while (name[i] != '\0')
	{
		this->name[i] = name[i];
		i++;
	}
	this->name[i] = '\0';
}

char*getName()
{
	return this->name;
}
void setFN(int fn)
{
	this->fn = fn;
}
int getFN()
{
	return this->fn;
}

int main()
{
	Grade myGrade;
	myGrade.setValue(6.00);
	std::cout << myGrade.getValue() << std::endl;
	myGrade.setSubject("Maths");
	std::cout << myGrade.getSubject() << std::endl;

	Grade anGrade(5, "geography");
	std::cout << anGrade.getValue() << std::endl;
	std::cout << anGrade.getSubject() << std::endl;

}

