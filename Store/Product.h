#pragma once

extern int GlobalSKU;

class Product
{
	//the product is GSM

private:
	int SKU;
	double Price;
	int Count;
	double Memory;
	double Size;
	char* Brand;
	char* Model;
	char* Colour;
	char* OS;

public:
	Product();
	Product(double, int, double, double, char*, char*, char*, char*);
	Product(const Product &p);
	Product& operator=(const Product &p);
	~Product();

	void SetSKU(const int &SKU);
	int GetSKU() const;
	void SetPrice(const double &Price);
	double GetPrice() const;
	void SetCount(const int &Count);
	int GetCount() const;
	void SetMemory(const double &Memory);
	double GetMemory() const;
	void SetSize(const double &Size);
	double GetSize() const;
	void SetBrand(const char* &Brand);
	char* GetBrand() const;
	void SetModel(const char* &Model);
	char* GetModel() const;
	void SetColour(const char* &Colour);
	char* GetColour() const;
	void SetOS(const char* &OS);
	char* GetOS() const;

	void PrintInfo()const;
	
};


