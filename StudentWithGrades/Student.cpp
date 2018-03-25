#include"stdafx.h"
#include<iostream>
#include "Header.h"
#pragma warning(disable: 4996)

void Grade::setValue(double value)
{
	if (value < 2 || value>6)
	{
		std::cout << "Invalid grade!" << std::endl;
	}
	else
	{
		this->value = value;
	}
}

double Grade::getValue() const
{
	return this->value;
}

void Grade::setSubject(const char subject[])
{
	int i = 0;
	while (subject[i] != '\0')
	{
		this->subject[i] = subject[i];
		i++;
	}
	this->subject[i] = '\0';
}

const char *Grade::getSubject() const
{
	return this->subject;
}

Grade::Grade()
{
	setValue(6);
	setSubject("OOP");
}

Grade::Grade(double value)
{
	setValue(value);
	setSubject("UP");
}

Grade::Grade(double value, char* subject)
{
	setValue(value);
	setSubject(subject);
}



void Student::setName(char name[])
{
	int i = 0;
	while (name[i] != '\0')
	{
		this->name[i] = name[i];
		i++;
	}
	this->name[i] = '\0';
}

char* Student::getName()
{
	return this->name;
}
void Student::setFN(int fn)
{
	this->fn = fn;
}
int Student::getFN()
{
	return this->fn;
}

void Student::setGradesNum(int maxCount)
{
	this->maxCount = maxCount;
}

void Student::setGrades(Grade *grades)
{
	for (int i = 0; i < this->getGradesNum(); i++)
	{
		this->addGrade(grades[i]);
	}
}

Grade* Student::getGrades()
{
	return this->grades;
}

Student::Student(char name[], int fn, int maxCount, Grade *grades):gradesCount(0)
{
	setName(name);
	setFN(fn);
	setGradesNum(maxCount);
	setGrades(grades);
	this->grades = new Grade[maxCount];
}

int Student::getGradesNum()
{
	return this->maxCount;
}

Student::~Student()
{
	std::cout << "Deleted student!!!" << std::endl;
	delete[] this->grades;
}

Grade::Grade(const Grade& otherGrade)
{
	this->setSubject(otherGrade.getSubject());
	this->setValue(otherGrade.getValue());
}

void Student::addGrade(Grade g)
{
	this->gradesCount++;
	this->grades[gradesCount - 1]=g;
}

int main()
{
	Grade gradeArr[3];

	Grade myGrade;
	std::cout << myGrade.getValue() << ", ";
	std::cout << myGrade.getSubject() << std::endl;

	Grade anotherGrade(6);
	std::cout << anotherGrade.getValue() << ", ";
	std::cout << anotherGrade.getSubject() << std::endl;

	Grade oneMoreGrade(6, "DIS");
	std::cout << oneMoreGrade.getValue() << ", ";
	std::cout << oneMoreGrade.getSubject() << std::endl;

	gradeArr[0] = myGrade;
	gradeArr[1] = anotherGrade;
	gradeArr[2] = oneMoreGrade;

	std::cout << "--------------------------" << std::endl;

	Student myStudent("Tanya", 62132, 3, gradeArr);

	Grade *GradesTanya = myStudent.getGrades();

	std::cout << myStudent.getName() << ", " << myStudent.getFN() << std::endl;
	for (int i = 0; i<myStudent.getGradesNum(); i++)
	{
		std::cout << GradesTanya[i].getSubject() << "-" << GradesTanya[i].getValue() << std::endl;
	}

	Grade addThisGrade(4, "Algebra");
	myStudent.addGrade(addThisGrade);
	std::cout << "--------------------------" << std::endl;
	std::cout << "Added grade:"<<std::endl;

	for (int i = 0; i<myStudent.getGradesNum(); i++)
	{
		std::cout << GradesTanya[i].getSubject() << "-" << GradesTanya[i].getValue() << std::endl;
	}

}
