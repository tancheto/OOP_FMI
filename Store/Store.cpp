#include "stdafx.h"
#include <iostream>
#include "Store.h"

int StrLenStore(const char* Str)// strlen for the products in the store
{
	int Counter = 0;
	while (Str[Counter] != '\0')
	{
		Counter++;
	}
	return Counter;
}

void DoubleLenStore(char* &Array)//doubling the char arrays containing the names of the products in the store
{
	int i = 0;
	char* NewArray = new char[2 * StrLenStore(Array) + 1];//2* current length + terminating 0
	for (i = 0; i <= StrLenStore(Array); i++)//<=StrLen because of the terminating 0
	{
		NewArray[i] = Array[i];
	}
	delete[] Array;//deleting the smaller char array
	Array = NewArray;
}

void EnterCharArrayStore(char* &input)//entering new product from the keyboard
{
	int CharCount = 0;
	char c;

	while (std::cin.get(c) && c != '\n')
	{
		if (CharCount == StrLenStore(input))
		{
			DoubleLenStore(input);
		}
		input[CharCount] = c;//the next symbol of input is the next entered one
		CharCount++;
	}
	input[CharCount] = '\0';//terminating 0
	std::cin.clear();
}

void StrCpyStore(char * &destination, const char* source)//string copy function
{
	int CharCount = 0;
	while (source[CharCount] != '\0')
	{
		if (CharCount == StrLenStore(destination))
		{
			DoubleLenStore(destination);
		}
		destination[CharCount] = source[CharCount];
		CharCount++;
	}
	destination[CharCount] = '\0';//terminating zero
}

//constructor
//NumProd=100 by default
Store::Store(int NumProd)
{
	this->SetNumProd(NumProd);
	this->CurNumProd = 0;
	Products = new Product[this->GetNumProd()];//new dynamic array
}

//copy-constructor
Store::Store(const Store &s)
{
	this->SetNumProd(s.GetNumProd());
	this->CurNumProd = s.CurNumProd;
	Products = new Product[this->GetNumProd()];//new dynamic array

	for (int i = 0; i < this->GetNumProd(); i++)
	{
		this->Products[i] = s.Products[i];
	}
}

//redefining of operator =
Store& Store::operator=(const Store &s)
{
	if (this != &s)//if this object is different from s object
	{
		delete[] this->Products;

		this->SetNumProd(s.GetNumProd());
		this->CurNumProd = s.CurNumProd;
		Products = new Product[this->GetNumProd()];

		for (int i = 0; i < this->GetNumProd(); i++)
		{
			this->Products[i] = s.Products[i];
		}
	}

	return *this;
}

//destructor
Store::~Store()
{
	delete[] this->Products;
}

//setters and getters
void Store::SetNumProd(const int& NumProd)
{
	this->NumProd = NumProd;
}

int Store::GetNumProd() const
{
	return this->NumProd;
}

void Store::AddProd()
{
	if (this->CurNumProd == NumProd)//if the limit of products is hit
	{
		std::cout << "Too many products in this store, no space for more." << std::endl;
	}
	else
	{
		std::cout << "Add the new product..." << std::endl;
		Product NewProd;
		this->CurNumProd++;

		Products[CurNumProd-1].SetSKU(GlobalSKU);
		GlobalSKU++;//the global variable increases
		
		char* brand = new char[10];//new dynamic array for the name of the brand
		std::cout << "Enter the GSM's brand:" << std::endl;		
		EnterCharArrayStore(brand);// entering the brand char by char
		const char* brandConst = brand;	//setter only accepts char arrays, so we make another const variable with the same value	
		NewProd.SetBrand(brandConst);//setter for brand
		
		//same algorith is repeated for the other char* variables
		char* model = new char[10];
		std::cout << "Enter the model:"<<std::endl;
		EnterCharArrayStore(model);
		const char* modelConst = model;	
		NewProd.SetModel(modelConst);


		double price;
		std::cout << "Enter the price:"<<std::endl;
		std::cin >> price;

		//while input isn't valid
		while (!std::cin) 
		{
			//clearing and ignoring the stream after cin
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input! Enter the price:" << std::endl;
			std::cin >> price;
		}
		//setter
		NewProd.SetPrice(price);

		//same algorith is repeated for the other int and double variables
		int count;
		std::cout << "Enter the count:" << std::endl;
		std::cin >> count;
		//while input isn't valid
		while (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input! Enter the count:" << std::endl;
			std::cin >> count;
		}
		NewProd.SetCount(count);

		char* os = new char[10];
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter the OS:" << std::endl;
		EnterCharArrayStore(os);
		const char* osConst = os;		
		NewProd.SetOS(osConst);
		
		int memory;
		std::cout << "Enter the memory:" << std::endl;
		std::cin >> memory;
		//while input isn't valid
		while (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input! Enter the memory:" << std::endl;
			std::cin >> memory;
		}
		NewProd.SetMemory(memory);
		
		int size;
		std::cout << "Enter the size:" << std::endl;
		std::cin >> size;
		//while input isn't valid
		while (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input! Enter the size:" << std::endl;
			std::cin >> size;
		}
		NewProd.SetSize(size);

		char* colour = new char[10];
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter the colour:" << std::endl;
		EnterCharArrayStore(colour);
		const char* colourConst = colour;
		NewProd.SetColour(colourConst);
	
		Products[CurNumProd - 1] = NewProd;
	}

	std::cout << "Successfully added item! Press enter for main menu." << std::endl;
}

void Store::DelProd(int SKU)
{
	bool FoundSKU = false;
	if (CurNumProd < 1)//if there are no products in the store
	{
		std::cout << "Error in deleting! There are no items in the store." << std::endl;
	}
	else
	{
		for (int i = 0; i < CurNumProd; i++)
		{
			if (Products[i].GetSKU() == SKU)
			{
				FoundSKU = true;//if the sku exists
				Products[i].SetSKU(-1);
				for (int j = i; j < CurNumProd - 1; j++)
				{
					Products[j] = Products[j + 1];//shifting the postions
				}
				this->CurNumProd--;
				std::cout << "Succesfully deleted item! Press enter for main menu." << std::endl;
			}
		}
		if (!FoundSKU)//if the sku doesn't exist
		{
			std::cout << "Invalid input! There's not such a SKU." << std::endl;
		}
	}
}

void Store::ChangeProd(int SKU)
{
	bool FoundSKU = false;
	if (CurNumProd < 1)//if there are no items in the store
	{
		std::cout << "There are no items in the store." << std::endl;
	}
	for (int i = 0; i < CurNumProd; i++)
	{
		if (Products[i].GetSKU() == SKU)
		{
			FoundSKU = true;// if this sku exists

			Product NewProd;

			// new product's info:

			Products[i].SetSKU(GlobalSKU);
			GlobalSKU++;

			//ignoring and clearing the stream
			std::cin.clear();
			std::cin.ignore();

			//following the same algorithms as in AddProd method...

			char* brand = new char[10];
			std::cout << "Enter the new GSM's brand:" << std::endl;
			EnterCharArrayStore(brand);
			const char* brandConst = brand;
			NewProd.SetBrand(brandConst);

			char* model = new char[10];
			std::cout << "Enter the new model:" << std::endl;
			EnterCharArrayStore(model);
			const char* modelConst = model;
			NewProd.SetModel(modelConst);

			double price;
			std::cout << "Enter the new price:" << std::endl;
			std::cin >> price;
			while (!std::cin)
			{
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input! Enter the new price:" << std::endl;
				std::cin >> price;
			}
			NewProd.SetPrice(price);

			int count;
			std::cout << "Enter the new count:" << std::endl;
			std::cin >> count;
			while (!std::cin)
			{
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input! Enter the new count:" << std::endl;
				std::cin >> count;
			}
			NewProd.SetCount(count);

			std::cin.clear();
			std::cin.ignore();

			char* os = new char[10];
			std::cout << "Enter the new OS:" << std::endl;
			EnterCharArrayStore(os);
			const char* osConst = os;
			NewProd.SetOS(osConst);

			int memory;
			std::cout << "Enter the new memory:" << std::endl;
			std::cin >> memory;
			while (!std::cin)
			{
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input! Enter the new memory:" << std::endl;
				std::cin >> memory;
			}
			NewProd.SetMemory(memory);

			int size;
			std::cout << "Enter the new size:" << std::endl;
			std::cin >> size;
			while (!std::cin)
			{
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input! Enter the new size:" << std::endl;
				std::cin >> size;
			}
			NewProd.SetSize(size);

			std::cin.clear();
			std::cin.ignore();

			char* colour = new char[10];
			std::cout << "Enter the new colour:" << std::endl;
			EnterCharArrayStore(colour);
			const char* colourConst = colour;
			NewProd.SetColour(colourConst);

			Products[CurNumProd - 1] = NewProd;
			std::cout << "Succesfully changed item! Press enter for main menu." << std::endl;

		}
	}
	if (!FoundSKU)// if this sku doesn't exist
	{
		std::cout << "Invalid input! There's not such a SKU." << std::endl;
	}
}

void Store::DisplayProd()
{
	if (CurNumProd == 0)//if there are no items in the store
	{
		std::cout << "No items in the store." << std::endl;
	}

	//otherwise- printing ...
	for (int i = 0; i < CurNumProd; i++)
	{
		Products[i].PrintInfo();
		std::cout << "-----------------------" << std::endl;
	}
	std::cout << "Press enter for main menu." << std::endl;
}