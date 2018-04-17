#pragma once

class String
{
private:
	char* str;
	int length;
	void setstr(const char*&s);

public:
	String(int length=100);
	String(const String &s);
	String& operator=(const String &s);
	~String();

	char* getstr()const;
	void setlength(const int);
	int getlength()const;
	int strlen(const char* &s) const;

};