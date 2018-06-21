#include "Worker.h"

Worker::Worker(string name, int k):Employee(name)
{
	setK(k);
	work = 0;
	success = 0;
}

void Worker::setK(int k)
{
	if (k <= 0)
	{
		this->k = 1;
	}
	else
	{
		this->k = k;
	}
}

bool Worker::execute(string task)
{
	//std::cout << task << std::endl;
	work++;
	if (work%k == 0)
	{
		std::cout << "Task:ERROR" << std::endl;
		return false;
	}
	success++;
	std::cout << "Task:DONE" << std::endl;
	return true;
}

double Worker::successRate()const
{
	if (work == 0) 
	{
		return 0;
	}
	return (success / work);
}

Employee * Worker::Clone() const
{
	return new Worker(*this);
}

int Worker::getWork() const
{
	return work;
}

int Worker::getK() const
{
	return this->k;
}

void Worker::print() const
{
	std::cout << "Worker:" << this->getK() <<" "<< this->getName() << "\n";
}

