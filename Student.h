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

	Grade(double value = 6, char* subject= "OOP");

};

class Student
{
private:
	char name[15];
	int fn;
	int gradesNum;
	Grade *grades = new Grade[];
public:
	void setName(char name[]);
	char*getName() const;
	void setFN(int fn);
	int getFN() const;
	
};
