#pragma once
#include"Grade.h"

class Student
{
private:
	char name[15];
	int fn;
	int maxCount;
	int gradesCount;
	Grade *grades;

public:
	Student(char name[], int fn, int gradesCount, Grade *grades);
	void setName(char name[]);
	char*getName();
	void setFN(int fn);
	int getFN();
	void setGradesNum(int);
	int getGradesNum();
	void setGrades(Grade *grades);
	void addGrade(Grade g);
	Grade* getGrades();
	double GetAverage();
	void PrintGrades();
	void Print();
	void PrintAll();
	~Student();

};