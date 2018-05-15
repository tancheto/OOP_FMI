#pragma once
#include<iostream>

class Timestamp
{
protected:
	unsigned long stamp;
public:
	Timestamp();
	Timestamp(const unsigned long s);
	unsigned long GetValue() const;
	void SetValue(const unsigned long s);

	friend std::istream& operator>>(std::istream is, Timestamp &stamp);
	friend std::ostream& operator<<(std::ostream os, const Timestamp &stamp);
	void operator+=(unsigned long d);
	Timestamp& operator+(unsigned long d);

};
