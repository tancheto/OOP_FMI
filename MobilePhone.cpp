// oop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

class Battery
{
private:
	char model[10];
	int time;
public:

	Battery(const char *model, int time)
	{
		SetBatteryModel(model);
		SetTime(time);
	}

	void SetBatteryModel(const char *model)
	{
		int i = 0;
		while (model[i] != '\0')
		{
			this->model[i] = model[i];
			i++;
		}
		this->model[i] = '\0';
	}

	char *GetBatteryModel()
	{
		return (this->model);
	}

	void SetTime(int time)
	{
		this->time = time;
	}

	int GetTime()
	{
		return this->time;
	}


};

class Display
{
private:
	int size;
	int colors;
public:
	Display(int size, int colors)
	{
		SetSize(size);
		SetColors(colors);
	}

	void SetSize(int size)
	{
		this->size = size;
	}

	int GetSize()
	{
		return this->size;
	}

	void SetColors(int colors)
	{
		this->colors = colors;
	}

	int GetColors()
	{
		return this->colors;
	}

};
class Mobile
{
private:
	char model[10];
	char producer[15];
	int price;
	Battery battery;
	Display display;

public:

	Mobile(const char *model, int time, int size, int colors):battery(model, time),display(size, colors)
	{
	}

	Battery GetBattery()
	{
		return this->battery;
	}

	Display GetDisplay()
	{
		return this->display;
	}
		
	void SetModel(char model[])
	{
		int i = 0;
		while (model[i] != '\0')
		{
			this->model[i] = model[i];
			i++;
		}
		this->model[i] = '\0';
	}

	char *GetModel()
	{
		return (this->model);
	}

	void SetProducer(char producer[])
	{
		int i = 0;
		while (producer[i] != '\0')
		{
			this->producer[i] = producer[i];
			i++;
		}
		this->producer[i] = '\0';
	}

	char *GetProducer()
	{
		return (this->producer);
	}

	void SetPrice(int price)
	{
		this->price = price;
	}

	int GetPrice()
	{
		return this->price;
	}

};




int main()
{
	Mobile MyMobile("ala-bala", 8, 5, 1000);

	MyMobile.SetModel("LG");
	std::cout << MyMobile.GetModel() << std::endl;

	MyMobile.SetProducer("Google");
	std::cout << MyMobile.GetProducer() << std::endl;

	MyMobile.SetPrice(500);
	std::cout << MyMobile.GetPrice() << std::endl;


	
	
	std::cout << MyMobile.GetBattery().GetBatteryModel() << std::endl;
	std::cout << MyMobile.GetBattery().GetTime() << std::endl;

	std::cout << MyMobile.GetDisplay().GetSize() << std::endl;
	std::cout << MyMobile.GetDisplay().GetColors() << std::endl;

    return 0;
}

