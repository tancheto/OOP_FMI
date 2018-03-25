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