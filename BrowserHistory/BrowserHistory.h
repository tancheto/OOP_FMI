#pragma once

struct HistoryEntry
{
public:

	int month;
	int LenURL = 10;
	char* url=new char[LenURL];
	void WidenLen();	

	// the structure HistoryEntry is directly linked to the class BrowserHistory
	//so it doesn't need constructors, destructors and so on
	// all of them are implemented in the methods of the class BrowserHistory
};

class BrowserHistory
{
private:
	int N;//max number of added sites
	int CurrentNum;//current number of added sites
	HistoryEntry* Hist;//array of History entries 
	
public:
	BrowserHistory(int N=100);//N=100 by default 
	BrowserHistory(const BrowserHistory& b);
	BrowserHistory &operator=(const BrowserHistory& b);
	~BrowserHistory();

	void SetN(const int& N);
	int GetN() const;

	void AddSite();
	void AddSite(const HistoryEntry& e);
	void PrintSites() const;
	
	int MaxNumSites = 0;//the max number of sites added for specific month
	int MaxMonthsNum=0;//number of months with max number of added sites
	int NumSitesPerMonth(const int& month);
	int* MaxMonth();
	void PrintMaxMonth();
	void RemoveSite();

	BrowserHistory operator+(const BrowserHistory& b);
};

