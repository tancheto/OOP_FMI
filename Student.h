#pragma once

class Grade
{
private:
	double value;
	char subject[15];
public:
	void setValue(double value);
	double getValue() const;
	void setSubject(const char subject[]);
	const char *getSubject() const;

	Grade();
	Grade(double);
	Grade(double, char*);
	Grade(const Grade& otherGrade);

};

class Student
{
private:
	char name[15];
	int fn;
	int maxCount;
	int gradesCount;
	Grade *grades;

public:
	Student(char name[], int fn, int maxCount, Grade *grades);
	void setName(char name[]);
	char*getName();
	void setFN(int fn);
	int getFN();
	void setGradesNum(int);
	int getGradesNum();
	void setGrades(Grade *grades);
	void addGrade(Grade g);
	Grade* getGrades();
	~Student();

};
