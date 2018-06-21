#include "Expert.h"


Expert::Expert(string name):Employee(name)
{
	work = 0;
}

bool Expert::execute(string task)
{
//	std::cout << task << std::endl;
	work++;
	std::cout << "Task:DONE" << std::endl;
	return true;
}

double Expert::successRate()const
{
	if (work == 0)
	{
		return 0;
	}
	return 1;
}

Employee * Expert::Clone() const
{
	return new Expert(*this);
}

int Expert::getWork() const
{
	return work;
}

void Expert::print() const
{
	std::cout << "Expert:" << this->getName() << "\n";
}
