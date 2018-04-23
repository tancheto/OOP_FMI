// task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"Store.h"
#include"Product.h"
#pragma warning(disable: 4996)

int StrLen(const char* Str)//strlen
{
	int Counter = 0;
	while (Str[Counter] != '\0')
	{
		Counter++;
	}
	return Counter;
}

void DoubleLen(char* &Array)//doubling the length of a dynamic char array
{
	int i = 0;
	char* NewArray = new char[2 * StrLen(Array) + 1];//2* current length + terminating 0
	for (i = 0; i <= StrLen(Array); i++)//<=StrLen because of the terminating 0
	{
		NewArray[i] = Array[i];
	}
	delete[] Array;//deleting the smaller char array
	Array = NewArray;
}

void EnterCharArray(char* &input)//entering a char array symbol by symbol
{
	int CharCount = 0;
	char c;

	while (std::cin.get(c) && c != '\n')
	{
		if (CharCount == StrLen(input))
		{
			DoubleLen(input);
		}
		input[CharCount] = c;
		CharCount++;
	}
	input[CharCount] = '\0';
}

void StrCpy(char * &destination, const char* source)//strcpy
{
	int CharCount = 0;
	while (source[CharCount] != '\0')
	{
		if (CharCount == StrLen(destination))
		{
			DoubleLen(destination);
		}
		destination[CharCount] = source[CharCount];
		CharCount++;
	}
	destination[CharCount] = '\0';//terminating zero
}


int main()
{
	Store MyStore;
	char *ch=new char[1];
	do
	{
		//main menu
		std::cout << "A   Add new product" << std::endl;
		std::cout << "X   Delete product" << std::endl;
		std::cout << "C   Change product" << std::endl;
		std::cout << "D   Display products" << std::endl;
		std::cout << "Q   Quit" << std::endl;		

		EnterCharArray(ch);
		if (StrLen(ch) == 1)
		{
			if (ch[0] == 'a' || ch[0] == 'A')
			{
				MyStore.AddProd();
				std::cin.clear();
				std::cin.ignore();
			}
			else if (ch[0] == 'x' || ch[0] == 'X')
			{
				int n;
				std::cout << "Enter the SKU of the product you would like to delete:" << std::endl;
				std::cin >> n;
				//while entered value is invalid
				while (!std::cin)
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "Invalid input. The SKU's are integer numbers greater or equal to 1." << std::endl;
					std::cout<<"Enter the SKU of the product you would like to delete:" << std::endl;
					std::cin >> n;
				}
				MyStore.DelProd(n);
				std::cin.clear();
				std::cin.ignore();
			}
			else if (ch[0] == 'c' || ch[0] == 'C')
			{
				int n;
				std::cout << "Enter the SKU of the product you would like to change:" << std::endl;
				std::cin >> n;
				//while entered value is invalid
				while (!std::cin)
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "Invalid input. The SKU's are integer numbers greater or equal to 1." << std::endl;
					std::cout << "Enter the SKU of the product you would like to change:" << std::endl;
					std::cin >> n;
				}
				MyStore.ChangeProd(n);
				std::cin. clear();
				std::cin.ignore();
			}
			else if (ch[0] == 'd' || ch[0] == 'D')
			{
				MyStore.DisplayProd();
				std::cin. clear();
				std::cin.ignore();
			}

			else if (ch[0] == 'q' || ch[0] == 'Q')
			{
				break;
			}
			else 
			{
				std::cout << "Invalid input! There's not such an option in the menu. Press enter for main menu." << std::endl;
				std::cin.clear();
				std::cin.ignore();
			}
		}
		else
		{
			std::cout << "Invalid input! Too many letters." << std::endl;
		}
	}while (true);// it will stop looping when 'q' or 'Q' is entered

    return 0;
}

