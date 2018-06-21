#pragma once
#include<iostream>
#include"Employee.h"
#include<string>
using std::string;

class Worker:public Employee
{
private:
	int k;
	int work;
	int success;

public:
	Worker(string name="\0", int k=1);
	
	void setK(int k);

	virtual bool execute(string task) override;
	virtual double successRate()const override;
	virtual Employee* Clone() const override;
	virtual int getWork()const override;
	int getK()const;

	virtual void print()const override;
};


