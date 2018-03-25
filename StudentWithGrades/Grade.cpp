#include"stdafx.h"
#include<iostream>
#include"Grade.h"

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

double Grade::getValue() const
{
	return this->value;
}

void Grade::setSubject(const char subject[])
{
	int i = 0;
	while (subject[i] != '\0')
	{
		this->subject[i] = subject[i];
		i++;
	}
	this->subject[i] = '\0';
}

const char *Grade::getSubject() const
{
	return this->subject;
}

Grade::Grade()
{
	setValue(6);
	setSubject("OOP");
}

Grade::Grade(double value)
{
	setValue(value);
	setSubject("UP");
}

Grade::Grade(double value, char* subject)
{
	setValue(value);
	setSubject(subject);
}

Grade::Grade(const Grade& otherGrade)
{
	this->setSubject(otherGrade.getSubject());
	this->setValue(otherGrade.getValue());
}