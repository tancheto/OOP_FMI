// Geometry_oop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"Vector.h"


Vector operator-(const Vector& a, const Vector& b)
{
	Vector res;
	res.SetX(a.GetX() - b.GetX());
	res.SetY(a.GetY() - b.GetY());
	res.SetZ(a.GetZ() - b.GetZ());

	return res;

}

Vector operator*(const double n, const Vector &a)
{
	Vector res;
	res.SetX(n*a.GetX());
	res.SetY(n*a.GetY());
	res.SetZ(n*a.GetZ());

	return res;
}

std::istream &operator>>(std::istream& is, Vector& v)
{
	double t;

	is >> t;
	v.SetX(t);

	is >> t;
	v.SetY(t);

	is >> t;
	v.SetZ(t);

	return is;
}

std::ostream &operator<<(std::ostream& os,const Vector& v)
{

	os<<v.GetX()<<" "<<v.GetY()<<" "<<v.GetZ();

	return os;
}



int main()
{
	Vector a(1, 2, 3);
	Vector b(4, 5);
	Vector c(6);
	Vector n,m,l,p,q;

	std::cout << "a:"<<std::endl;
	a.Print();
	std::cout << "b:" << std::endl;
	b.Print();
	std::cout << "c:" << std::endl;
	c.Print();

	n = a + b;
	std::cout << "n = a + b:" << std::endl;
	n.Print();

	m = a - c;
	std::cout << "m = a - c:" << std::endl;
	m.Print();

	l = a*10;
	std::cout << "l = 10*a:" << std::endl;
	l.Print();

	p = a*b;
	std::cout << "p = a*b:" << std::endl;
	p.Print();

	q = a^b;
	std::cout << "q = a^b:" << std::endl;
	q.Print();

	Vector r;
	r.Print();
	std::cin >> r;
	r.Print();

	std::cout << r;
	std::cout << "--------------";
	std::cout << a <<std::endl<< b <<std::endl << c << std::endl;


    return 0;
}

