#include"TimestampWithDescription.h"
int size = 10;//random

long StrLen(const char* &arr)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return i;
}
void StrCpy(char* &dest, const char* &source)
{
	int i = 0;
	const char* con_dest = dest;
	while (source[i] != '\0')
	{
		if (StrLen(con_dest) <= StrLen(source))
		{
			DoubleSize(dest);
		}
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
}
void DoubleSize(char* &arr)
{
	const char* con_arr = arr;
	char* NewArr = new char[StrLen(con_arr)*2];
	int i = 0;
	while (arr[i] != '\0')
	{
		NewArr[i] = arr[i];
		i++;
	}
	NewArr[i] = '\0';

	delete[] arr;
	arr = NewArr;
}

TimestampWithDescription::TimestampWithDescription(unsigned long value, char* d): Timestamp(value)
{
	descr = new char[size];
	SetDescription(d);
}
TimestampWithDescription::TimestampWithDescription(TimestampWithDescription& tswd)
{
	this->SetDescription(tswd.GetDescription());
}

TimestampWithDescription& TimestampWithDescription:: operator=(TimestampWithDescription& tswd)
{
	delete[] this->descr;
	this->SetDescription(tswd.GetDescription());
	return *this;
}

TimestampWithDescription::~TimestampWithDescription()
{
	delete[] this->descr;
}

char* TimestampWithDescription::GetDescription()
{
	return this->descr;
}

void TimestampWithDescription::SetDescription(const char* d)
{
	StrCpy(this->descr, d);
}

/*std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& tswd)
{
	os << tswd.descr;
}
std::istream& operator>>(std::istream& is, TimestampWithDescription& tswd)
{
	
}*/