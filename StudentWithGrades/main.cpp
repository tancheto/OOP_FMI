#include"stdafx.h"
#include<iostream>
#include"Student.h"
#include"Grade.h"
#pragma warning(disable: 4996)	

int main()
{
	Grade gradeArr[3];

	Grade myGrade;
	std::cout << myGrade.getValue() << ", ";
	std::cout << myGrade.getSubject() << std::endl;

	Grade anotherGrade(6);
	std::cout << anotherGrade.getValue() << ", ";
	std::cout << anotherGrade.getSubject() << std::endl;

	Grade oneMoreGrade(6, "DIS1");
	std::cout << oneMoreGrade.getValue() << ", ";
	std::cout << oneMoreGrade.getSubject() << std::endl;

	gradeArr[0] = myGrade;
	gradeArr[1] = anotherGrade;
	gradeArr[2] = oneMoreGrade;

	std::cout << "--------------------------" << std::endl;

	Student myStudent("Tanya", 62132, 3, gradeArr);

	Grade *GradesTanya = myStudent.getGrades();

	myStudent.PrintAll();

	Grade gradeToAdd1 (4.50, "Algebra");
	Grade gradeToAdd2(5.50, "DS");
	Grade gradeToAdd3(6, "DIS2");

	myStudent.addGrade(gradeToAdd1);
	myStudent.addGrade(gradeToAdd2);
	myStudent.addGrade(gradeToAdd3);

	std::cout << "--------------------------" << std::endl;
	std::cout << "With added grades:" << std::endl;

	myStudent.Print();
	myStudent.PrintGrades();
	
	std::cout << "Average grade:" <<myStudent.GetAverage()<< std::endl;
	std::cout << "--------------------------" << std::endl;

	Student Tanya(myStudent);

	myStudent.deleteGrades();
	Tanya.PrintAll();

	return 0;
}
