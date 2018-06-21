#include "Manager.h"


Manager::Manager(string name):Employee(name)
{
	 
	work = 0;
	success = 0;
}

Manager::Manager(const Manager & rhs):Employee(rhs)
{
	CloneEmployees(rhs.employees);
	work = rhs.work;
	success = rhs.success;
}

Manager::~Manager()
{
	vector<Employee*>::iterator iter;
	for (iter = employees.begin(); iter != employees.end(); iter++)
	{
		delete *iter;
	}
	employees.clear();
}

Manager &Manager::operator=(const Manager & rhs)
{
	if (this != &rhs)
	{
		vector<Employee*>::iterator iter;
		for (iter = employees.begin(); iter != employees.end(); iter++)
		{
			delete *iter;
		}
		employees.clear();

		*this = rhs;
		CloneEmployees(rhs.employees);
		work = rhs.work;
		success = rhs.success;
	}

	return *this;
}

bool Manager::execute(string task)
{
	bool exec = false;
	//std::cout << task << std::endl;

	int minWork = employees[0]->getWork();
	int minIndex = 0;

	for (int i = 1; i < (int)employees.size(); i++)
	{
		if (minWork > employees[i]->getWork())
		{
			minWork = employees[i]->getWork();
			minIndex = i;
		}
	}

	if (employees[minIndex]->execute(task))
	{
		success++;
		exec = true;
	}

	return exec;
}

double Manager::successRate() const
{
	if (work == 0)
	{
		return 0;
	}
	return (success / work);
}

Employee * Manager::Clone() const
{
	return new Manager(*this);
}

void Manager::CloneEmployees(const vector<Employee*> rhs)
{
	for (int i = 0; i < (int)rhs.size(); i++)
	{
		this->employees.push_back(rhs[i]->Clone());
	}
}

int Manager::getWork() const
{
	return work;
}

vector<Employee*> Manager::getEmployees() const
{
	return this->employees;
}

void Manager::addEmployee(const string name,int k, int type)
{
	if (type == 1)
	{
		employees.push_back(new Worker(name, k));
	}

	else if(type == 2)
	{
		employees.push_back(new Expert(name));
	}

	else if (type == 3)
	{
		employees.push_back(new Manager(name));
	}

	else
	{
		std::cout << "Error! No such a type of employees!" << std::endl;
	}
}

void Manager::addEmployee(Employee* &newEmployee)
{
	employees.push_back(newEmployee);
}

void Manager::deleteEmployee(const string name)
{
	int indexToDel = 0;
	for (int i = 0; i < (int)employees.size(); i++)
	{
		if (name == employees[i]->getName())
		{
			indexToDel = i;
			break;
		}
	}

	delete employees[indexToDel];
	employees.erase(employees.begin()+indexToDel);
}

void Manager::printStatus() const
{
	for (int i = 0; i < (int)employees.size(); i++)
	{
		std::cout << "Name:"<<employees[i]->getName();
		std::cout << "\nSuccess rate:"<<employees[i]->successRate();
		std::cout << "\n";
	}
}

void Manager::print() const
{
	std::cout << "Manager:" << this->getEmployees().size() <<" "<< this->getName() << "\n";
}
