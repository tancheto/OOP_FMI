#pragma once
#include<iostream>

template<class T> 
class Pricetag
{
	T tag;
public:
	Pricetag(const T& tag=0);

	void setTag(const T& tag);
	T& getTag();

	void discount(double& percentage);

	template<class T>
	friend std::ostream& operator<<(std::ostream& os, Pricetag<T>& tag)
	{
		os << "Price tag:" << tag.getTag() << std::endl;
		return os;
	}

	template<class T>
	friend std::istream& operator >> (std::istream& is, Pricetag<T>& tag)
	{
		T temp;

		std::cout << "Enter price tag:";
		is >> temp;

		tag.setTag(temp);

		return is;
	}

};



template<class T>
inline Pricetag<T>::Pricetag(const T& tag)
{
	this->setTag(tag);
}

template<class T>
void Pricetag<T>::setTag(const T& tag)
{
	this->tag = tag;
}

template<class T>
inline T & Pricetag<T>::getTag()
{
	return this->tag;
}

template<class T>
inline void Pricetag<T>::discount(double & percentage)
{
	if (percentage < 0 || percentage>100)
	{
		percentage = 0;
	}
	double discount = (percentage*tag)/ 100;
	this->setTag(this->getTag() - discount);
}
