#include<iostream>
#include"Timestamp.h" 

Timestamp::Timestamp()
{
	SetValue(0);
}
Timestamp::Timestamp(const unsigned long s)
{
	SetValue(s);
}
unsigned long Timestamp::GetValue() const
{
	return this->stamp;
}
void Timestamp::SetValue(const unsigned long s)
{
	this->stamp = s;
}

void Timestamp::operator+=(unsigned long d)
{
	this->SetValue(this->GetValue() + d);
}

Timestamp& Timestamp::operator+(unsigned long d)
{
	this->SetValue(this->GetValue() + d);
	return *this;
}
