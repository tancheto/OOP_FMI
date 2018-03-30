#include "stdafx.h"
#include<iostream>
#include"Vector.h"

void Vector::SetX(double x)
{
	this->x = x;
}
void Vector::SetY(double y) 
{
	this->y = y;
}
void Vector::SetZ(double z)
{
	this->z = z;
}

double Vector::GetX() const
{
	return this->x;
}
double Vector::GetY() const
{
	return this->y;
}
double Vector::GetZ() const
{
	return this->z;
}

Vector Vector::Add(const Vector &v) const
{
	Vector res;
	res.SetX(this->GetX() + v.GetX());
	res.SetY(this->GetY() + v.GetY());
	res.SetZ(this->GetZ() + v.GetZ());

	return res;
}

void Vector::Print() const
{
	std::cout << "X:" << this->GetX()<< ", Y:" << this->GetY() << ", Z:" << this->GetZ() << std::endl;
}

Vector Vector::operator+(const Vector &b)
{
	Vector res;
	res.SetX(this->GetX() + b.GetX());
	res.SetY(this->GetY() + b.GetY());
	res.SetZ(this->GetZ() + b.GetZ());

	return res;
}

Vector Vector::operator*(const double n)
{
	Vector res;
	res.SetX(n*this->GetX());
	res.SetY(n*this->GetY());
	res.SetZ(n*this->GetZ());

	return res;
}

Vector Vector::operator*(const Vector &b)
{
	Vector res;
	res.SetX(this->GetX()*b.GetX());
	res.SetY(this->GetY()*b.GetY());
	res.SetZ(this->GetZ()*b.GetZ());

	return res;
}

Vector Vector::operator^(const Vector &b)
{
	Vector res;
	res.SetX(this->GetY()*b.GetZ() - this->GetZ()*b.GetY());
	res.SetY(this->GetZ()*b.GetX() - this->GetX()*b.GetZ());
	res.SetZ(this->GetX()*b.GetY() - this->GetY()*b.GetX());

	return res;
}