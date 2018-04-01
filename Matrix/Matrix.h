#pragma once
class Matrix
{
private: 
	int dim;
	double **mat;
public:
	Matrix(double **mat, int dim = 3);
	Matrix();
	Matrix(int);
	Matrix(const Matrix &m);
	~Matrix();
	void setDim(const int&);
	int getDim() const;
	void setMat(const double**);
	double** getMat() const;
	void print() const;	
	Matrix operator+(const Matrix& a);	
	Matrix operator-(const Matrix& a);
	Matrix operator*(const Matrix& a);
	
};