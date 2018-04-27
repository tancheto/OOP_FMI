#pragma once
#include"Building.h"

class House: public Building
{
private:
	int storeysNum;
	char* owner;
public:
	House(const int storeysNum=2, const char* owner="");
	House(const House& h);
	House& operator=(const House& h);
	~House();

	void setStoreys(const int&);
	int getStoreys() const;
	
	void setOwner(const char*&);
	char* getOwner() const;

};
