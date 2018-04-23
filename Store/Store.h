#pragma once
#include "Product.h"

class Store
{
private:
	Product *Products;
	int NumProd;
	int CurNumProd;

public:
	Store(int NumProd=100);//NumProd=100 by default
	Store(const Store &s);
	Store & operator= (const Store &s);
	~Store();

	void SetNumProd(const int&);
	int GetNumProd() const;

	void AddProd();
	void DelProd(int SKU);
	void ChangeProd(int SKU);
	void DisplayProd();
	
};


