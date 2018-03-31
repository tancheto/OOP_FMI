#include"stdafx.h"
#include<iostream>
#include"Student.h"


Student::Student(char name[], int fn, int gradesCount, Grade *grades) :maxCount(5)
{
	setName(name);
	setFN(fn);
	setGradesNum(gradesCount);

	
	this->grades = new Grade[maxCount];
	setGrades(grades);
}

Student::Student(const Student &s)
{
	this->setFN(s.getFN());
	this->setGradesNum(s.getGradesNum());
	this->setName(s.getName());
	this->maxCount = s.maxCount;

	this->grades = new Grade[s.maxCount];

	for (int i = 0; i < this->maxCount; i++)
	{
		this->grades[i] = s.grades[i];
	}
}

void Student::setName(const char name[])
{
	int i = 0;
	while (name[i] != '\0')
	{
		this->name[i] = name[i];
		i++;
	}
	this->name[i] = '\0';
}

const char* Student::getName() const
{
	return this->name;
}
void Student::setFN(const int& fn)
{
	this->fn = fn;
}
int Student::getFN() const
{
	return this->fn;
}

void Student::setGradesNum(const int& gradesCount)
{
	this->gradesCount = gradesCount;
}

int Student::getGradesNum() const
{
	return this->gradesCount;
}

void Student::addGrade(const Grade &g)
{
	if(gradesCount<maxCount)
	{
		this->gradesCount++;	
		this->grades[gradesCount - 1] = g;
		std::cout << "Successfully added grade of " <<g.getSubject()<<"!"<< std::endl;
	}
	else
	{
		std::cout << "Invalid addition of subject "<<g.getSubject()<<"! Too many subjects, stop studying so much!!!"<<std::endl;
	}

}

void Student::setGrades(const Grade *grades)
{
	for (int i = 0; i < this->getGradesNum(); i++)
	{
		this->grades[i] = grades[i];
	}
}

Grade* Student::getGrades() const
{
	return this->grades;
}

void Student::deleteGrades()
{
	this -> grades = nullptr;
}

double Student::GetAverage() const
{
	double aver=0;
	int counter=0;

	for (int i = 0; i < this->getGradesNum(); i++)
	{
		aver += this->grades[i].getValue();
		counter++;
	}
	return (aver / counter);
}

void Student::PrintGrades()
{
	for (int i = 0; i<this->getGradesNum(); i++)
	{
		std::cout << this->grades[i].getSubject() << "-" << this->grades[i].getValue() << std::endl;
	}
}

void Student::Print()
{
	std::cout << this->getName() << ", " << this->getFN() << std::endl;
}

void Student::PrintAll()
{
	this->Print();
	this->PrintGrades();
}

Student::~Student()
{
	std::cout << "Deleted student!!!" << std::endl;
	delete[] this->grades;
}
