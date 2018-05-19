#include<iostream>
#include"Temperature.h"
#include"Forecast.h"

int main()
{
	Temperature myTemperature(10,15,20);
	Forecast myForecast("Gabrovo", myTemperature);

	std::cout << myForecast << std::endl;

	std::cout <<"Amplitude:"<< myTemperature.GetAmplitude()<<std::endl;

	Temperature secondTemp(10, 15, 30);

	std::cout << "==:" << (secondTemp == myTemperature) << std::endl;
	std::cout << "!=:" << (secondTemp != myTemperature) << std::endl;
	std::cout<<"<:"<< (secondTemp < myTemperature) << std::endl;
	std::cout << "<=:" << (secondTemp <= myTemperature) << std::endl;
	std::cout << ">:" << (secondTemp > myTemperature) << std::endl;
	std::cout << ">=:" << (secondTemp >= myTemperature) << std::endl;

	system("pause");
	return 0;
}