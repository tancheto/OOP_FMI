#pragma once

class Building
{
private:
	int height;
	double area;
	char* address;
public:
	Building(const int height=1, const double area=1, const char* address="");
	Building(const Building &b);
	Building& operator=(const Building &b);
	~Building();

	void CopyBuilding(const Building &b);
	void setHeight(const int&);
	int getHeight()const;
	void setArea(const double&);
	double getArea()const;
	void setAddress(const char* &);
	char* getAddress()const;

	void printAll() const;
	
};