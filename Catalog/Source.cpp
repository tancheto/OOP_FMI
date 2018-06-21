#include<iostream>
#include"Pricetag.h"
#include"PriceCatalog.h"

int main()
{
	Pricetag<double> myTag(8.10);
	Pricetag<double> A(3.4);
	Pricetag<double> B(5.6);
	Pricetag<double>C;

	std::cout << "C:";
	std::cin >> C;

	PriceCatalog<double> myCatalog;

	myCatalog += myTag;
	myCatalog += A;
	myCatalog += B;
	myCatalog += C;

	std::cout << myCatalog << std::endl;

	return 0;
}