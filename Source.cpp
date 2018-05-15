#include <iostream>
#include"Timestamp.h"
#include"TimestampWithDescription.h"

int main()
{
	TimestampWithDescription myTimestamp(10,"kleimo");

	Timestamp PlainTimestamp(20);

	PlainTimestamp += 10;
	std::cout << PlainTimestamp.GetValue();
	system("pause");

}
