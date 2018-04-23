
#include "stdafx.h"
#include <iostream>
#include "Product.h"

int GlobalSKU = 0;//global variable responsible for sku

int StrLenProd(const char* Str)//the strlen of the name of the product
{
	int Counter = 0;
	while (Str[Counter] != '\0')
	{
		Counter++;
	}
	return Counter;
}

void DoubleLenProd(char* &Array)//doubling the char array of the product
{
	int i = 0;
	char* NewArray = new char[2 * StrLenProd(Array) + 1];//2* current length + terminating 0
	for (i = 0; i <= StrLenProd(Array); i++)//<=StrLen because of the terminating 0
	{
		NewArray[i] = Array[i];
	}
	delete[] Array;//deleting the smaller char array
	Array = NewArray;
}

void EnterCharArrayProd(char* &input)//entering char array for the product with random length
{
	int CharCount = 0;
	char c;

	while (std::cin.get(c) && c != '\n')
	{
		if (CharCount == StrLenProd(input))
		{
			DoubleLenProd(input);
		}
		input[CharCount] = c;
		CharCount++;
	}
	input[CharCount] = '\0';
}

void StrCpyProd(char* &destination, const char* source)//copying char arrays
{
	int CharCount = 0;
	while (source[CharCount] != '\0')
	{
		if (CharCount == StrLenProd(destination))
		{
			DoubleLenProd(destination);
		}
		destination[CharCount] = source[CharCount];
		CharCount++;
	}
	destination[CharCount] = '\0';//terminating zero
}

//default constructor
Product::Product()
{
	SKU=GlobalSKU+1;
	Price=0;
	Count=0;
	Memory=0;
	Size=0;
	//initialising the char arrays with length=10 at the beginning
	Brand=new char[10];
	Model=new char[10];
	Colour=new char[10];
	OS=new char[10];
}

//constructor
Product::Product(double Price, int Count, double Memory, double Size, char* Brand, char* Model, char* Colour, char* OS)
{
	//calling the setters
	this->SetSKU(GlobalSKU);
	GlobalSKU++;//gloval variable for sku is increasing here
	this->SetPrice(Price);
	this->SetCount(Count);
	this->SetMemory(Memory);
	this->SetSize(Size);
	
	this->Brand = new char[10];
	StrCpyProd(this->Brand, Brand);	

	this->Model = new char[10];
	StrCpyProd(this->Model, Model);

	this->Colour = new char[10];
	StrCpyProd(this->Colour, Colour);

	this->OS = new char[10];
	StrCpyProd(this->OS, OS);

}

//copy-constructor
Product::Product(const Product &p)
{
	//calling the setters for the new object
	this->SetSKU(p.GetSKU());
	this->SetPrice(p.GetPrice());
	this->SetCount(p.GetCount());
	this->SetMemory(p.GetMemory());
	this->SetSize(p.GetSize());

	this->Brand = new char[10];
	StrCpyProd(this->Brand, p.Brand);

	this->Model = new char[10];
	StrCpyProd(this->Model, p.Model);

	this->Colour = new char[10];
	StrCpyProd(this->Colour, p.Colour);

	this->OS = new char[10];
	StrCpyProd(this->OS, p.OS);
}

//redefining of operator =
Product& Product:: operator=(const Product &p)
{
	if (this != &p)//if this object is different from p object
	{
		//deleting the dynamic variables of the already created object
		delete[] this->Brand;
		delete[] this->Model;
		delete[] this->Colour;
		delete[] this->OS;

		//calling the setters
		this->SetSKU(p.GetSKU());
		this->SetPrice(p.GetPrice());
		this->SetCount(p.GetCount());
		this->SetMemory(p.GetMemory());
		this->SetSize(p.GetSize());

		this->Brand = new char[10];
		StrCpyProd(this->Brand, p.Brand);

		this->Model = new char[10];
		StrCpyProd(this->Model, p.Model);

		this->Colour = new char[10];
		StrCpyProd(this->Colour, p.Colour);

		this->OS = new char[10];
		StrCpyProd(this->OS, p.OS);
	}
	return *this;//returning the address of the new object
}

//destructor
Product::~Product()
{
	//'deleting' the dynamic memory
	delete[] Brand;
	delete[] Model;
	delete[] Colour;
	delete[] OS;
}

//setters and getters 
void Product::SetSKU(const int &SKU)
{
	if (SKU >= 1)//validation
	{
		this->SKU = SKU;
	}
}

int Product::GetSKU() const
{
	return this->SKU;
}

void Product::SetPrice(const double &Price)
{
	if (Price >= 0)//validation
	{
		this->Price = Price;
	}
}

double Product::GetPrice() const
{
	return this->Price;
}

void Product::SetCount(const int &Count)
{
	if (Count > 0)//validation
	{
		this->Count = Count;
	}
}

int Product::GetCount() const
{
	return this->Count;
}

void Product::SetMemory(const double &Memory)
{
	if (Memory > 0)//validation
	{
		this->Memory = Memory;
	}
}

double Product::GetMemory() const
{
	return this->Memory;
}

void Product::SetSize(const double &Size)
{
	if (Size > 0)//validation
	{
		this->Size = Size;
	}
}

double Product::GetSize() const
{
	return this->Size;
}

void Product::SetBrand(const char* &Brand)
{
	StrCpyProd(this->Brand, Brand);
}

char* Product::GetBrand() const
{
	return this->Brand;
}

void Product::SetModel(const char* &Model)
{
	StrCpyProd(this->Model, Model);
}

char* Product::GetModel() const
{
	return this->Model;
}

void Product::SetColour(const char* &Colour)
{
	StrCpyProd(this->Colour, Colour);
}

char* Product::GetColour() const
{
	return this->Colour;
}

void Product::SetOS(const char* &OS)
{
	StrCpyProd(this->OS, OS);
}

char* Product::GetOS() const
{
	return this->OS;
}

//printing the info about the product
void Product::PrintInfo()const
{
	std::cout << "Product's info:" << std::endl;
	std::cout << "The stock keeping unit is:" << this->GetSKU() << std::endl;
	std::cout << "The GSM's brand is:" << this->GetBrand() << std::endl;
	std::cout << "Model:" << this->GetModel() << std::endl;
	std::cout << "Price:" << this->GetPrice() <<"BGN"<< std::endl;
	std::cout << "There are available " << this->GetCount() << " products of this type" << std::endl;
	std::cout << "OS:" << this->GetOS() << std::endl;
	std::cout << "RAM:" << this->GetMemory() <<"GB"<< std::endl;
	std::cout << "Size:" << this->GetSize() << " inches" << std::endl;
	std::cout << "Colour:" << this->GetColour() << std::endl;	
}
