#pragma once

class Employee
{
private:
	char* name;
	int experience;
	double salary;
public:
	Employee(const char* name="", const int experience=12,const double salary=1000);
	Employee(const Employee& e);
	Employee& operator= (const Employee& e);
	~Employee();
	void setName(const char* name);
	char* getName()const;
	void setExperience(const int experience);
	int getExperience()const;
	void setSalary(const double salary);
	double getSalary()const;
};

class ITSpecialist:public Employee
{
private:
	char* project;
public:
	ITSpecialist(const char* project = "");
	ITSpecialist(const ITSpecialist& IT);
	ITSpecialist& operator= (const ITSpecialist& IT);
	~ITSpecialist();
	void setProject(const char* project);
	char* getProject()const;
};

class Programmer : public ITSpecialist
{
private:
	char language[20];
public:
	void setLanguage(const char*);
	char* getLanguage()const;
	Programmer(const char* language="");
};

class QA : public ITSpecialist
{
private:
	bool test;
public:
	void setTest(const bool test);
	bool getTest()const;
	QA(const bool test=1);
};

class Manager : public Employee
{
private:
	int employeesNum;
public:
	void setEmployeesNum(const int EmployeesNum);
	int getEmployeesNum()const;
	Manager(const int employeesNum = 10);
};