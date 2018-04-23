
#include "stdafx.h"
#include <iostream>
#include "BrowserHistory.h"

//function returning the length of a string
int StrLen(char* Str)
{
	int Counter = 0;
	while (Str[Counter] != '\0')
	{
		Counter++;
	}
	return Counter;
}

//function that doubles the length of a string (URL)
void HistoryEntry::WidenLen()
{
	int i = 0;
	char* NewURL = new char[2*LenURL+1];//2* current length + terminating 0
	for (i = 0; i <= this->LenURL; i++)//<=LenURL because of the terminating 0
	{
		NewURL[i] = url[i];
	}
	delete[] url;//deleting the smaller char array
	this->url = NewURL;//the URL of the object is the larger URL
	this->LenURL *= 2;//the length of the URL of the current object doubles
}

//constructor
BrowserHistory::BrowserHistory(int N)
{
	this->SetN(N);// calling the setter
	this->CurrentNum = 0;// by now there are no added sites
	this->Hist = new HistoryEntry[N];//defining the dynamic array
}

//copy constructor
BrowserHistory::BrowserHistory(const BrowserHistory& b)
{
	//setting the new object's data- copying from (this) to (b) object
	this->SetN(b.GetN());
	this->CurrentNum = b.CurrentNum;
	this->Hist = new HistoryEntry[b.GetN()];//new dynamic array- we cannot copy pointers

	for (int i = 0; i < b.CurrentNum; i++)
	{
		this->Hist[i].month = b.Hist[i].month;
		this->Hist[i].LenURL = b.Hist[i].LenURL;
		this->Hist[i].url = new char[b.Hist[i].LenURL+1];//new dynamic array

		//copying the URL
		int CharCount = 0;
		while (b.Hist[i].url[CharCount] != '\0')
		{
			if (CharCount == b.Hist[i].LenURL)
			{
				this->Hist[i].WidenLen();
			}
			this->Hist[i].url[CharCount] = b.Hist[i].url[CharCount];
			CharCount++;
		} 
	
		this->Hist[i].url[CharCount] = '\0';

	}
}

//redefinition of operator =
BrowserHistory& BrowserHistory:: operator=(const BrowserHistory& b)
{
	//deleting the old dynamc data from the object, which is already set 
	if (this != &b)
	{
		for (int i = 0; i < this->CurrentNum; i++)
		{
			delete[] this->Hist[i].url;//deleting all of the dynamic url's
		}
		delete[] this->Hist;//deleting the array of hstory entries

		//copying the data from (this) to (b) object		
		this->SetN(b.GetN());
		this->CurrentNum = b.CurrentNum;
		this->Hist = new HistoryEntry[b.GetN()];//new dynamic array

		for (int i = 0; i < b.CurrentNum; i++)
		{
			this->Hist[i].month = b.Hist[i].month;
			this->Hist[i].LenURL = b.Hist[i].LenURL;
			this->Hist[i].url = new char[b.Hist[i].LenURL + 1];//new dynamic array

			//copying the URL
			int CharCount = 0;
			while (b.Hist[i].url[CharCount] != '\0')
			{
				if (CharCount == b.Hist[i].LenURL)
				{
					this->Hist[i].WidenLen();
				}
				this->Hist[i].url[CharCount] = b.Hist[i].url[CharCount];
				CharCount++;
			}

			this->Hist[i].url[CharCount] = '\0';
		}
	}
	return *this;//returning pointer to (this) object
}

//destructor
BrowserHistory::~BrowserHistory()
{
	for (int i = 0; i < this->CurrentNum; i++)
	{	   
		delete[] this->Hist[i].url;//deleting every dynamic array [URL] in the History array
	}

	delete[] this->Hist;//deleting the dynamic array Hist
}

//setter for max number of sites in the history=N
void BrowserHistory::SetN(const int &N)
{
	this->N = N;
}
//getter for N
int BrowserHistory::GetN() const
{
	return this->N;
}

//adding new site by entering the information from the keybord
void BrowserHistory::AddSite()
{
	HistoryEntry NewSite;

	std::cout << "New history entry..." << std::endl;
		
	int CharCount = 0;
	char c;
	std::cout << "Enter the URL of the history entry:";	

	//entering the string symbol by symbol
	while (std::cin.get(c) && c!='\n')
	{
		if (CharCount == NewSite.LenURL)
		{
			NewSite.WidenLen();
		}
		NewSite.url[CharCount] = c;
		CharCount++;
	} 	

	NewSite.url[CharCount] = '\0';// terminating 0 at the end

	std::cout << "Enter the month of the history entry:";
	std::cin >> NewSite.month;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	/*
	^
	-necessary if there are 2 or more calls of function AddSite()
	-ignores the rest of the input by now
	-needed because of cin.get()
	-'\n' sets the delimiter, i.e.the character after which cin stops ignoring
	-numeric_limits<streamsize>::max() sets the maximum number of characters to 
	ignore
    */

	//validation...
	bool error = false;//by default there are errors in the input

	if (NewSite.month < 1 || NewSite.month>12)// if the month doesn't exist
	{
		std::cout << "Invalid input! There is not such a date." << std::endl;
		error = true;
	}	

	if (this->CurrentNum > this->GetN())//if the sites are more than the limit N
	{
		std::cout << "Invalid input! You hit the limit of stored sites." << std::endl;
		error = true;
	}
		
	if (CharCount == 0)//if the URL is the empty string
	{
		std::cout << "Invalid input! The URL is missing." << std::endl;
		error = true;
	}
	
	if(!error)//if there are no errors
	{
		std::cout << "Success! The site is added to the history." << std::endl;

		this->CurrentNum++;//the number of added sites increases

		//initialising...
		this->Hist[CurrentNum - 1].month = NewSite.month;	
		this->Hist[CurrentNum - 1].LenURL = NewSite.LenURL;		
		this->Hist[CurrentNum-1].url = new char[NewSite.LenURL + 1];

		int j = 0;
		while (NewSite.url[j] != '\0' && j< NewSite.LenURL)//we know the length of the URL
		{
			this->Hist[CurrentNum-1].url[j] = NewSite.url[j];//copying the url char by char
			j++;
		}

		this->Hist[CurrentNum-1].url[j] = '\0';//terminating 0
	}
	delete[] NewSite.url;//deletting the dynamic variable
}

void BrowserHistory::AddSite(const HistoryEntry& NewSite)//adding new site 
{
	std::cout << "New history entry..." << std::endl;
	bool error = false;//by default there are errors in the input

	//validation...
	if (NewSite.month < 1 || NewSite.month>12)// if the month doesn't exist
	{
		std::cout << "Invalid input! There is not such a date." << std::endl;
		error = true;
	}

	if (this->CurrentNum > this->GetN())//if the sites are more than the limit N
	{
		std::cout << "Invalid input! You hit the limit of stored sites." << std::endl;
		error = true;
	}

	if (StrLen(NewSite.url) == 0)//if the URL is the empty string
	{
		std::cout << "Invalid input! The URL is missing." << std::endl;
		error = true;
	}

	if (!error)//if there are no errors
	{
		std::cout << "Success! The site is added to the history." << std::endl;

		this->CurrentNum++;//the number of added sites increases

		//initialising...
		this->Hist[CurrentNum - 1].month = NewSite.month;
		this->Hist[CurrentNum - 1].LenURL = NewSite.LenURL;
		this->Hist[CurrentNum - 1].url = new char[NewSite.LenURL + 1];

		int CharCount = 0;

		while (NewSite.url[CharCount] != '\0')// we do't know the length of the URL
		{
			if (CharCount == NewSite.LenURL)
			{
				this->Hist[CurrentNum-1].WidenLen();
			}
			this->Hist[CurrentNum - 1].url[CharCount] = NewSite.url[CharCount];//copying the url char by char
			CharCount++;
		}
		this->Hist[CurrentNum-1].url[CharCount] = '\0';//terminating zero
	}	
}

//printing the infromation for the sites
void BrowserHistory::PrintSites() const
{
	for (int i = 0; i < this->CurrentNum; i++)// to current number of the added sites, not to N
	{
		std::cout << "Entry " << i + 1 << ": " << std::endl;
		std::cout << "Month:" << this->Hist[i].month << "; URL:" << this->Hist[i].url << std::endl;
		std::cout << "---------------------------" << std::endl;
	}
}

//The number of sites added for a specific month
int BrowserHistory::NumSitesPerMonth(const int& month)
{
	int Counter = 0;// counts the sites
	for (int i = 0; i < this->CurrentNum; i++)
	{
		if (Hist[i].month == month)
		{
			Counter++;
		}
	}
	return Counter;
}

//returns the month with max number of added sites
//[this month could be more than 1, so it returns array]
int* BrowserHistory::MaxMonth()
{
	int MaxMonths[12];
	int counter = 0;
	
	// determines what is the max number of sites per any month
	for (int i = 1; i <= 12; i++)
	{
		if (NumSitesPerMonth(i) >= this->MaxNumSites)
		{
			this->MaxNumSites = NumSitesPerMonth(i);
		}
	}	

	// determines which are the months with max number of sites
	for (int i = 1; i <= 12; i++)
	{
		if (NumSitesPerMonth(i) == this->MaxNumSites)
		{
			MaxMonths[counter]=i;
			counter++;
		}
	}

	this->MaxMonthsNum = counter;//number of months with max number of added sites
 
	return MaxMonths;
}

//prints the month with max number of added sites
void BrowserHistory::PrintMaxMonth()
{
	int *MaxMonths = MaxMonth();
	std::cout << "The max number of sites ("<<this->MaxNumSites<<") are visited in month(s):";
	
	//printing the months with max number of added sites
	for (int i = 0; i < this->MaxMonthsNum; i++)
	{
		std::cout << this->MaxMonth()[i];
		if (i != this->MaxMonthsNum - 1) 
		{ 
			std::cout << ", "; 
		}
	}
	std::cout << std::endl;
}

//removing site from the browser history
void BrowserHistory::RemoveSite()
{
	if (CurrentNum > 0)
	{
		delete[] this->Hist[CurrentNum-1].url;//removing dynamic char array
		CurrentNum--;
	}
	else
	{
		std::cout << "Error removing site! There are no sites in browser history." << std::endl;
	}
}

//concaten ating 2 sites by redefining of the operator +
BrowserHistory BrowserHistory::operator+(const BrowserHistory& b)
{
	BrowserHistory result;// the concatenation
	
	result.SetN(this->GetN() + b.GetN());// the max number of sites is a sum of max numbers of sites of the other two
	result.CurrentNum = this->CurrentNum + b.CurrentNum;//current num is also a sum
	result.Hist = new HistoryEntry[result.GetN()];// new dynamic array

	for (int i = 0; i < this->CurrentNum; i++)
	{
		//initialising...
		result.Hist[i].month = this->Hist[i].month;
		result.Hist[i].LenURL = this->Hist[i].LenURL;
		result.Hist[i].url = new char[this->Hist[i].LenURL+1];// new dynamic URL

		//firstly, we copy the data from the first object
		int CharCount = 0;
		while (this->Hist[i].url[CharCount] != '\0')
		{
			if (CharCount == this->Hist[i].LenURL)
			{
				result.Hist[i].WidenLen();
			}
			result.Hist[i].url[CharCount] = this->Hist[i].url[CharCount];
			CharCount++;
		}

		result.Hist[i].url[CharCount] = '\0';//terminating zero

	}

	//secondly, we copy the data from second object
	for(int j=0;j<b.CurrentNum;j++)
	{
		result.Hist[j+this->CurrentNum].month = b.Hist[j].month;
		result.Hist[j+this->CurrentNum].LenURL = b.Hist[j].LenURL;
		result.Hist[j+this->CurrentNum].url = new char[b.Hist[j].LenURL + 1];// new dynamic URL

		int CharCount = 0;
		while (b.Hist[j].url[CharCount] != '\0')
		{
			if (CharCount == b.Hist[j].LenURL)
			{
				result.Hist[j+this->CurrentNum].WidenLen();
			}
			result.Hist[j+this->CurrentNum].url[CharCount] = b.Hist[j].url[CharCount];
			CharCount++;
		}

		result.Hist[j+this->CurrentNum].url[CharCount] = '\0';//terminating zero
	}

	return result;//retruning the object result
}