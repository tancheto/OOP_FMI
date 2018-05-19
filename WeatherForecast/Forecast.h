#pragma once
#include<iostream>
#include"Temperature.h"

class Forecast
{
private:
	char* place;
	Temperature temp;
public:
	Forecast();
	Forecast(const char* place, Temperature const& temp);
	Forecast(Forecast& f);
	Forecast& operator=(Forecast& f);
	~Forecast();

	void SetPlace(const char* place);
	char* GetPlace() const;
	void SetTemperature(Temperature temp);
	Temperature GetTemperature() const;
	void UpdateIfHotter(Forecast const& F);
	
};

std::ostream& operator <<(std::ostream& os,const  Forecast& f);
std::istream& operator >> (std::istream& is, Forecast& f);