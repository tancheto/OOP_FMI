// template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"template.h"


int main()
{
	int arr1[5] = { 4,3,5,7,10 };
	std::cout << "The median of the first collection is:" << median(arr1, 5) << std::endl;

	double arr2[6] = { 4,3,5,7,10,2 };
	std::cout << "The median of the second collection is:" << median(arr2, 6) << std::endl;
    return 0;
}

