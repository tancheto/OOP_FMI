#pragma once
#include<iostream>
#include"Pricetag.h"

template<class T>
class PriceCatalog
{
private:
	Pricetag<T>* catalog;
	int length;

public:
	PriceCatalog();
	PriceCatalog(const PriceCatalog& pc);
	PriceCatalog& operator=(const PriceCatalog& pc);
	~PriceCatalog();

	void CopyObj(const PriceCatalog& pc);

	void operator+=(Pricetag<T>& newTag);

	template<class T>
	friend std::ostream& operator << (std::ostream& os, const PriceCatalog<T> pc)
	{
		for (int i = 0; i < pc.length; i++)
		{
			os << pc.catalog[i] << std::endl;
		}
		return os;
	}

};

template<class T>
inline PriceCatalog<T>::PriceCatalog(): length(0)
{
	this->catalog = new Pricetag<T>[length];
}

template<class T>
inline PriceCatalog<T>::PriceCatalog(const PriceCatalog & pc)
{
	this->CopyObj(pc);
}

template<class T>
inline PriceCatalog<T>& PriceCatalog<T>::operator=(const PriceCatalog & pc)
{
	if (this != &pc)
	{
		delete[] catalog;

		this->CopyObj(pc);
	}

	return *this;
}

template<class T>
inline PriceCatalog<T>::~PriceCatalog()
{
	delete[] catalog;
}

template<class T>
inline void PriceCatalog<T>::CopyObj(const PriceCatalog & pc)
{
	this->catalog = new Pricetag<T>[pc.length];
	for (int i = 0; i < pc.length; i++)
	{
		this->catalog[i] = pc.catalog[i];
	}
	this->length = pc.length;

}

template<class T>
inline void PriceCatalog<T>::operator+=(Pricetag<T> & newTag)
{
	Pricetag<T>* newCatalog = new Pricetag<T>[length + 1];
	for (int i = 0; i < length; i++)
	{
		newCatalog[i] = this->catalog[i];
	}
	newCatalog[length] = newTag;
	
	delete[] this->catalog;
	this->catalog = newCatalog;
	length++;
}


