#pragma once
#include"Grade.h"

class Student
{
private:
	char name[15];
	int fn;
	
	int gradesCount;
	Grade *grades;

public:
	int maxCount;
	Student(char name[], int fn, int gradesCount, Grade *grades);
	Student(const Student &s);
	void setName(const char name[]);
	const char *getName() const;
	void setFN(const int &fn);
	int getFN() const;
	void setGradesNum(const int&);
	int getGradesNum() const;
	void setGrades(const Grade *grades);
	Grade* getGrades() const;
	void addGrade(const Grade &g);	
	void deleteGrades();
	double GetAverage() const;
	void PrintGrades();
	void Print();
	void PrintAll();
	~Student();

};
