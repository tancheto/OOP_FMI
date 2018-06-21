#pragma once
#include "Employee.h"
#include"Worker.h"
#include"Expert.h"
#include<string>
#include<vector>
using std::string;
using std::vector;

class Manager :
	public Employee
{
private:
	vector<Employee*> employees;
	int work;
	int success;

public:
	Manager(string name="\0");
	Manager(const Manager& rhs);
	virtual ~Manager();
	Manager& operator=(const Manager& rhs);

	virtual bool execute(string task) override;
	virtual double successRate()const override;
	virtual Employee* Clone() const override;

	void CloneEmployees(const vector<Employee*> rhs);
	virtual int getWork()const override;
	vector<Employee*> getEmployees()const;

	void addEmployee(const string name,int k, int type);
	virtual void addEmployee(Employee* &newEmployee) override;
	void deleteEmployee(const string name);

	virtual void printStatus()const;
	virtual void print()const override;
};


