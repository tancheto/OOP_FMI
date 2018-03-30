#pragma once




class Vector
{
private:
	double x;
	double y;
	double z;

public:

	Vector(double x=0, double y=0, double z=0)
	{
		SetX(x);
		SetY(y);
		SetZ(z);
	}

	void SetX(double x);
	void SetY(double y);
	void SetZ(double z);

	double GetX() const;
	double GetY() const;
	double GetZ() const;


	Vector Add(const Vector &v) const;

	void Print() const;

	Vector operator+(const Vector &b);
	Vector operator*(const double n);
	Vector operator*(const Vector &b);
	Vector operator^(const Vector &b);

};

