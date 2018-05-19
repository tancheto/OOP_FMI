#include "Temperature.h"

Temperature::Temperature():min(12),max(12),avg(12)
{
}

Temperature::Temperature(int min, int avg, int max)
{
	if (min <= avg <= max)
	{
		SetTemperature(min, max, avg);
	}

	else
	{
		SetTemperature(12, 12, 12);
	}
}

void Temperature::SetTemperature(int min, int max, int average)
{
	this->min = min;
	this->max = max;
	this->avg = average;
}

int Temperature::GetMin() const
{
	return this->min;
}

int Temperature::GetAverage() const
{
	return this->avg;
}

int Temperature::GetMax() const
{
	return this->max;
}

int Temperature::GetAmplitude() const
{
	return (this->max - this->min);
}

bool Temperature::operator==(const Temperature& t)
{
	if (this->max == t.GetMax() && this->min == t.GetMin() && this->avg == t.GetAverage())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Temperature::operator!=(const Temperature& t)
{
	return !(*this == t);
}

bool Temperature::operator <(const Temperature& t)
{
	if (this->max < t.GetMax())
	{
		return true;
	}
	else
	{
		if (this->min < t.GetMin())
		{
			return true;
		}
		else
		{
			if (this->avg < t.GetAverage())
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
	}
}

bool Temperature::operator<=(const Temperature& t)
{
	return (*this < t || *this == t);
}

bool Temperature::operator >(const Temperature& t)
{
	return !(*this <= t);
}

bool Temperature::operator>=(const Temperature& t)
{
	return (*this > t || *this == t);
}