#pragma once
#include<string>
using std::string;

class Customer
{
private:
	int id;
	string name;
	string address;

public:
	Customer(int id = 0, string name = "", string address = "");

	int getId() const;
	string getName() const;
	string getAddress() const;
	void display()const;
};

