#include<iostream>
#include"Worker.h"
#include"Expert.h"
#include"Manager.h"
#include<string>
#include<vector>
using std::string;
using std::vector;

int main()
{
	Employee* Angel=new Manager ("Angel Angelov"); 
	Employee* Boyan = new Worker ("Boyan Boyanov", 2); 
	Employee* Vasilka = new Expert ("Vasilka Vasileva");
	Employee* Georgi=new Manager ("Georgi Georgiev");
	Employee* Dimitar = new Worker ("Dimitar Dimitrov", 4);
	
	Angel->addEmployee(Boyan);
	Angel->addEmployee(Vasilka);
	Angel->addEmployee(Georgi);
	Georgi->addEmployee(Dimitar);

	std::cout << "send them to clear the floor" << std::endl;
	Angel->execute("send them to clear the floor");
	std::cout << "wash the dishes" << std::endl;
	Angel->execute("wash the dishes");
	std::cout << "test the project" << std::endl;
	Angel->execute("test the project");
	std::cout << "call mum" << std::endl;
	Angel->execute("call mum");
	std::cout << "solve the problem of DIS" << std::endl;
	Angel->execute("solve the problem of DIS");
	std::cout << "buy toilet paper" << std::endl;
	Angel->execute("buy toilet paper");

	Angel->printStatus();

	Angel->print();
	Boyan->print(); 
	Vasilka->print();
	Georgi->print(); 
	Dimitar->print(); 

	return 0;
}
