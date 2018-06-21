#pragma once
#include "Employee.h"
#include<string>
using std::string;

class Expert :
	public Employee
{
private:
	int work;
public:
	Expert(string name = "\0");

	virtual bool execute(string task) override;
	virtual double successRate() const override;
	virtual Employee* Clone() const override;
	virtual int getWork()const override;

	virtual void print()const override;
};

