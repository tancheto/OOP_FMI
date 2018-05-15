#include"Timestamp.h" 

Timestamp::Timestamp()
{
	this->stamp = 0;
}
Timestamp::Timestamp(const unsigned long s)
{
	SetValue(s);
}
unsigned long Timestamp::GetValue() const
{
	return this->stamp;
}
void Timestamp::SetValue(const unsigned long s)
{
	this->stamp = s;
}

std::ostream& operator<<(std::ostream& os, const Timestamp &stamp)
{
	os << stamp.GetValue();
	return os;
}
std::istream& operator>>(std::istream& is, Timestamp &stamp)
{
	unsigned long temp;

	is >> temp;
	stamp.SetValue(temp);
	return is;
}

void Timestamp::operator+=(unsigned long d)
{
	this->SetValue(this->GetValue() + d);
}

Timestamp& Timestamp::operator+(unsigned long d)
{
	this->SetValue(this->GetValue() + d);
	return *this;
}

