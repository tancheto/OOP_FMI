#include "stdafx.h"
#include <iostream>
#include "String.h"

String::String(int length)
{
	this->setlength(length);
	str = new char[this->getlength()];
}

String::String(const String &s)
{
	this->setlength(s.getlength());
	this->str = new char[this->getlength()];
	
	for (int i = 0; i < this->getlength(); i++)
	{
		this->str[i] = s.str[i];
	}
	this->str[this->getlength()] = '\0'; 
}

String::~String()
{
	delete[] this->str;
}

int String::strlen(const char* &s) const
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		i++;
	}
	return i;
}

void String::setstr(const char*&s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		this->str[i] = s[i];
	}
	this->str[strlen(s)] = '\0';
}
char* String::getstr()const
{
	return this->str;
}

void String::setlength(const int)
{
	this->length = length;
}
int String::getlength()const
{
	return this->length;
}

String& String::operator=(const String &s)
{
	delete[] this->str;
	this->setlength(s.getlength());
	this->str = new char[this->getlength()];

	for (int i = 0; i < this->getlength(); i++)
	{
		this->str[i] = s.str[i];
	}
	this->str[this->getlength()] = '\0';

	return *this;
}
