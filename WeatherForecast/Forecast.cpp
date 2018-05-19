#include <iostream>
#include "Forecast.h"

Forecast::Forecast()
{
	char* place = "";
	Temperature t(0, 0, 0);
	this->temp = t;
}

Forecast::Forecast(const char * place, Temperature const & temp)
{
	this->place = new char[strlen(place) + 1];
	this->SetPlace(place);
	this->SetTemperature(temp);
}

Forecast::Forecast(Forecast & f)
{
	this->place = new char[strlen(f.GetPlace()) + 1];
	SetPlace(f.GetPlace());
	SetTemperature(f.GetTemperature());
}

Forecast & Forecast::operator=(Forecast & f)
{
	delete[] place;

	this->place = new char[strlen(f.GetPlace()) + 1];
	SetPlace(f.GetPlace());
	SetTemperature(f.GetTemperature());

	return* this;
}

Forecast::~Forecast()
{
	delete[] place;
}

void Forecast::SetPlace(const char * place)
{
	strcpy_s(this->place, strlen(place) + 1, place);
}

char * Forecast::GetPlace() const
{
	return this->place;
}

void Forecast::SetTemperature(Temperature temp)
{
	this->temp = temp;
}

Temperature Forecast::GetTemperature() const
{
	return this->temp;
}

void Forecast::UpdateIfHotter(Forecast const & F)
{
	if (strcmp(F.GetPlace(), this->GetPlace()) == 0 && F.GetTemperature() > this->GetTemperature())
	{
		this->temp = F.GetTemperature();
	}
}

std::ostream & operator<<(std::ostream & os, const Forecast & f)
{
	os << "Place:" << f.GetPlace() << std::endl;
	os << "Temperature:" << std::endl;
	os << "~Min:" << f.GetTemperature().GetMin()<<std::endl;
	os << "~Max:" << f.GetTemperature().GetMax() << std::endl;
	os << "~Average:" << f.GetTemperature().GetAverage() << std::endl;

	return os;
}

std::istream & operator >> (std::istream & is, Forecast & f)
{
	char* t="";

	is>>t;
	f.SetPlace(t);

	int min, max, average;

	std::cout << "Enter min, max and average temperatures:";
	is >> min >> max >> average;

	Temperature temper(min, max, average);

	f.SetTemperature(temper);

	return is;
}
