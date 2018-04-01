#include "stdafx.h"
#include<iostream>
#include"Matrix.h"

Matrix::Matrix(double **mat, int dim)
{
	setDim(dim);
	setMat((const double**) mat);
}

Matrix::Matrix()
{

}

Matrix::Matrix(int dim)
{
	this->setDim(dim);
}

Matrix::Matrix(const Matrix &m)
{
	this->setDim(m.getDim());
	this->mat = new double* [m.getDim()];

	for (int i = 0; i < m.getDim(); i++)
	{
		this->mat[i] = new double[m.getDim()];
		for (int j = 0; j < m.getDim(); j++)
		{
			this->mat[i][j] = m.getMat()[i][j];
		}
	}
}

Matrix::~Matrix()
{
	/*
	for (int i = 0; i < this->getDim(); ++i)
	{
		delete[] mat[i];
	}

	delete[] mat;
	*/

	//std::cout << "Deleted object matrix!" << std::endl;
}

void Matrix::setDim(const int &dim)
{
	this->dim = dim;
}

int Matrix::getDim() const
{
	return this->dim;
}

void Matrix::setMat(const double** mat)
{
	this->mat = new double*[this->getDim()];

	for (int i = 0; i < this->getDim(); i++)
	{
		this->mat[i] = new double[this->getDim()];
		for (int j = 0; j < this->getDim(); j++)
		{
			this->mat[i][j] = mat[i][j];
		}
	}
}

double** Matrix::getMat() const
{
	return this->mat;
}

void Matrix::print() const
{
	for (int i = 0; i < this->getDim(); i++)
	{
		for (int j = 0; j < this->getDim(); j++)
		{
			std::cout << this->mat[i][j]<<" ";
		}
		std::cout << "\n";
	}
}

Matrix Matrix::operator+(const Matrix& a)
{
	Matrix res;

		res.setDim(this->getDim());
		double **resMat = new double*[this->getDim()];

		for (int i = 0; i < this->getDim(); i++)
		{
			resMat[i] = new double[this->getDim()];
			for (int j = 0; j < this->getDim(); j++)
			{
				resMat[i][j] = this->getMat()[i][j] + a.getMat()[i][j];
			}
		}
		res.setMat((const double**) resMat);

		for (int i = 0; i < this->getDim(); ++i)
		{
			delete[] resMat[i];
		}

		delete[] resMat;

		return res;
}

Matrix Matrix::operator-(const Matrix& a)
{
	Matrix res;

	res.setDim(this->getDim());
	double **resMat = new double*[this->getDim()];

	for (int i = 0; i < this->getDim(); i++)
	{
		resMat[i] = new double[this->getDim()];
		for (int j = 0; j < this->getDim(); j++)
		{
			resMat[i][j] = this->getMat()[i][j] - a.getMat()[i][j];
		}
	}
	res.setMat((const double**)resMat);

	for (int i = 0; i < this->getDim(); ++i)
	{
		delete[] resMat[i];
	}

	delete[] resMat;

	return res;
}

Matrix Matrix::operator*(const Matrix& a)
{
	Matrix res;
	int sum=0;

	res.setDim(this->getDim());
	double **resMat = new double*[this->getDim()];

	for (int i = 0; i < this->getDim(); i++)
	{
		resMat[i] = new double[this->getDim()];
		for (int j = 0; j < this->getDim(); j++)
		{
			sum = 0;
			for (int k = 0; k < this->getDim(); k++)
			{
			sum += this->getMat()[i][k] * a.getMat()[k][i];
			}
			resMat[i][j] = sum;
		}
	}
	res.setMat((const double**)resMat);

	for (int i = 0; i < this->getDim(); ++i)
	{
		delete[] resMat[i];
	}

	delete[] resMat;

	return res;
}
