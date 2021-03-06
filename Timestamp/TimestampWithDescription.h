#pragma once
#include"Timestamp.h"

class TimestampWithDescription : public Timestamp
{
private:
	char* descr;

public:
	TimestampWithDescription(unsigned long value = 0, char* d = "");
	TimestampWithDescription(TimestampWithDescription& tswd);
	TimestampWithDescription& operator=(TimestampWithDescription& tswd);
	~TimestampWithDescription();

	char* GetDescription();
	void SetDescription(const char* descr);

	friend long StrLen(const char* &arr);
	friend void StrCpy(char* &dest, const char* &source);
	friend void DoubleSize(char* &arr);
};

/*
std::ostream& operator<<(std::ostream& os, TimestampWithDescription& tswd);

std::istream& operator >> (std::istream& is, TimestampWithDescription& tswd);
*/
