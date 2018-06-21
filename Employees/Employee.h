#pragma once
#include<iostream>
#include<string>
using std::string;

class Employee
{
private:
	string name;
public:
	Employee(string name="\0");

	void setName(string name);

	virtual bool execute(string task)=0;
	virtual double successRate()const = 0;
	virtual Employee* Clone()const = 0;
	virtual int getWork()const = 0;
	string getName()const;

	virtual void addEmployee(Employee* &newEmployee)
	{}
	virtual void printStatus()const
	{}

	virtual void print()const = 0;
};

