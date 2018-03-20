#pragma once

class Grade
{
private:
	double value;
	char subject[15];
public:
	void setValue(double value);
	double getValue();
	void setSubject(char subject[]);
	char *getSubject();

	Grade();
	Grade(double);
	Grade(double, char* );

};

class Student
{
private:
	char name[15];
	int fn;
	int gradesNum;
	Grade *grades = new Grade[gradesNum];
public:
	Student(char name[], int fn, int gradesNum, Grade *grades);
	void setName(char name[]);
	char*getName();
	void setFN(int fn);
	int getFN();
	void setGradesNum(int);
	int getGradesNum();
	void setGrades(Grade *grades);
	Grade* getGrades();
	~Student();
	
};
