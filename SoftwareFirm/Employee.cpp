
#include<iostream>
#include<String.h>
#include"Employee.h"

Employee::Employee(const char* name, const int experience, const double salary)
{
	name = new char[strlen(name)];
	this->setName(name);
	this->setExperience(experience);
	this->setSalary(salary);
}

Employee::Employee(const Employee& e)
{
	name = new char[strlen(e.getName())];
	this->setName(e.getName());
	this->setExperience(e.getExperience());
	this->setSalary(e.getSalary());
}

Employee& Employee::operator= (const Employee& e)
{
	delete[] name;
	name = new char[strlen(e.getName())];
	this->setName(e.getName());
	this->setExperience(e.getExperience());
	this->setSalary(e.getSalary());
	return *this;
}

Employee::~Employee()
{
	delete[] name;
}

void Employee::setName(const char* name)
{
	strcpy_s(this->name, strlen(name), name);
}

char* Employee::getName()const
{
	return this->name;
}
void Employee::setExperience(const int experience)
{
	this->experience = experience;
}
int Employee::getExperience()const
{
	return this->experience;
}
void Employee::setSalary(const double salary)
{
	this->salary = salary;
}
double Employee::getSalary()const
{
	return this->salary;
}

ITSpecialist::ITSpecialist(const char* project):Employee()
{
	project = new char[strlen(project)];
	this->setProject(project);
}

ITSpecialist::ITSpecialist(const ITSpecialist& IT)
{
	project = new char[strlen(IT.project)];
	this->setProject(IT.project);
}

ITSpecialist& ITSpecialist::operator= (const ITSpecialist& IT)
{
	delete[] project;
	project = new char[strlen(IT.project)];
	this->setProject(IT.project);
	return *this;
}

ITSpecialist::~ITSpecialist()
{
	delete[] project;
}

void ITSpecialist::setProject(const char* project)
{
	strcpy_s(this->project, strlen(project), project);
}

char* ITSpecialist::getProject()const
{
	return this->project;
}

Programmer::Programmer(const char* language):ITSpecialist()
{
	this->setLanguage(language);
}

void Programmer::setLanguage(const char*language)
{
	int i = 0;
	while (language[i] != '\0')
	{
		this->language[i] = language[i];
		i++;
	}
	this->language[i] = '\0';
}
char* Programmer::getLanguage()const
{
	return (char*) this->language;
}

QA::QA(const bool test) :ITSpecialist()
{
	this->setTest(test);
}

void QA::setTest(const bool test)
{
	this->test = test;
}
bool QA::getTest()const
{
	return this->test;
}

void Manager::setEmployeesNum(const int EmployeesNum)
{
	this->employeesNum = EmployeesNum;
}
int Manager::getEmployeesNum()const
{
	return this->employeesNum;
}
Manager::Manager(const int employeesNum):Employee()
{
	setEmployeesNum(employeesNum);
}