
#include "stdafx.h"
#include <iostream>
#include "BrowserHistory.h"


int main()
{
	//tests

	BrowserHistory MyHistory;//N=100 by default

	//add multiple sites (info entered from the keyboard) test
	for (int i = 0; i < 3; i++)
	{
		MyHistory.AddSite();
	}

	HistoryEntry MySite;
	MySite.month = 5;
	MySite.url = "SomeKindOfURL";

	//add site to history test
	MyHistory.AddSite(MySite);	

	//print the info for all added sites in the browser history test
	MyHistory.PrintSites();

	//number of visited sites per month test
	for(int i=1;i<=12;i++)
	{
		std::cout << "Number of visited sites per month " << i <<":"<< MyHistory.NumSitesPerMonth(i) << std::endl;
	}
	std::cout << "Number of visited sites per non-existing month (15):" << MyHistory.NumSitesPerMonth(15) << std::endl;

	//printing the month(s) with max added sites test
	MyHistory.PrintMaxMonth();
	
	//copy constructor test
	std::cout << std::endl;
	std::cout << "Copy constructor:" << std::endl;
	BrowserHistory TestOne(MyHistory);
	TestOne.PrintSites();

	//operator = test
	std::cout << std::endl;
	std::cout << "Operator =:" << std::endl;
	BrowserHistory TestTwo;
	TestTwo = MyHistory;
	TestTwo.PrintSites();

	//removing site test
	std::cout << std::endl;
	std::cout << "Removing a site:" << std::endl;
	MyHistory.RemoveSite();
	MyHistory.PrintSites();

	//concatenating 2 sitest test
	std::cout << std::endl;
	std::cout << "Concatenating 2 objects:" << std::endl;
	BrowserHistory TestThree;
	TestThree = MyHistory+TestOne;
	TestThree.PrintSites();

    return 0;
}

