
#include "stdafx.h"
#include<iostream>
#include"Matrix.h"

std::istream &operator>> (std::istream& is, Matrix& m)
{
	double **temp = new double*[m.getDim()];
	for (int i = 0; i < m.getDim(); i++)
	{
		temp[i] = new double[m.getDim()];
		for (int j = 0; j < m.getDim(); j++)
		{
			is >> temp[i][j];
		}
	}

	m.setMat((const double**) temp);

	for (int i = 0; i < m.getDim(); ++i)
	{
		delete[] temp[i];
	}

	delete[] temp;
	return is;
}

std::ostream &operator<<(std::ostream& os, const Matrix& m)
{

	for (int i = 0; i < m.getDim(); i++)
	{
		for (int j = 0; j < m.getDim(); j++)
		{
			os << m.getMat()[i][j]<<" ";
		}
		std::cout<<std::endl;
	}

	return os;
}

int main()
{
	double **arr1 = new double*[3];
	for (int i = 0; i < 3; i++)
	{
		arr1[i] = new double[3];
		for (int j = 0; j < 3; j++)
		{
			arr1[i][j] = (i+1)*(j+1);
		}
	}

	double **arr2 = new double*[3];
	int counter = 0;
	for (int i = 0; i < 3; i++)
	{
		arr2[i] = new double[3];
		for (int j = 0; j < 3; j++)
		{
			arr2[i][j] = counter;
			counter++;
		}
	}

	Matrix firstMatrix(arr1, 3);
	Matrix secondMatrix(arr2, 3);

	firstMatrix.print();
	std::cout<<std::endl;
	secondMatrix.print();
	std::cout << std::endl;
	
	Matrix a;
	
 	a = firstMatrix + secondMatrix;
	std::cout << "+" << std::endl;
	a.print();
	std::cout << std::endl;

	Matrix b;

	b = firstMatrix - secondMatrix;
	std::cout << "-" << std::endl;
	b.print();
	std::cout << std::endl;

	Matrix c;

	c = firstMatrix*secondMatrix;
	std::cout << "matrix*matrix" << std::endl;
	c.print();
	std::cout << std::endl;
	std::cout << c;
	std::cout << std::endl;

	Matrix ts(3);

    std::cin >> ts;
	std::cout<<ts;
	

	for (int i = 0; i < 3; ++i)
	{
		delete[] arr1[i];
		delete[] arr2[i];
	}

	delete[] arr1;
	delete[] arr2;
	
	return 0;
}
