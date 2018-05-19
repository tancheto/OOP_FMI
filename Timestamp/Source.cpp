#include <iostream>
#include"Timestamp.h"
#include"TimestampWithDescription.h"

std::istream& operator >> (std::istream& is, Timestamp &stamp)
{
	unsigned long temp;

	is >> temp;
	stamp.SetValue(temp);
	return is;
}

std::ostream& operator<< (std::ostream& os, const Timestamp &stamp)
{
	std::cout << "~Timestamp~" << std::endl;
	os << "Value:" << stamp.GetValue() << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, TimestampWithDescription& tswd)
{
	std::cout << "~Timestamp with description~" << std::endl;
	os <<(const Timestamp&)tswd;

	os << "Description:" << tswd.GetDescription()<<std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, TimestampWithDescription& tswd)
{

	is >> (Timestamp&)tswd;
	char* temp="";

	//is.ignore();
	//is.getline(temp, 1000);
	is >> temp;
	tswd.SetDescription(temp);

	return is;
}

int main()
{
	TimestampWithDescription myTimestamp(10, "kleimo");

	Timestamp PlainTimestamp(20);

	PlainTimestamp += 10;
	(Timestamp)myTimestamp = myTimestamp + 70;

	std::cout << PlainTimestamp;
	std::cout << myTimestamp;
	
	system("pause");
	return 0;
}