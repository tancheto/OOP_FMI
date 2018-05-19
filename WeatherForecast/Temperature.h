#pragma once
class Temperature
{
private:
	int min;
	int max;
	int avg;

public:
	Temperature();
	Temperature(int min, int avg, int max);

	void SetTemperature(int min, int max, int average);

	int GetMin() const;
	int GetAverage() const;
	int GetMax() const;
	int GetAmplitude() const;

	bool operator==(const Temperature& t);
	bool operator!=(const Temperature& t);
	bool operator <(const Temperature& t);
	bool operator >(const Temperature& t);
	bool operator<=(const Temperature& t);
	bool operator>=(const Temperature& t);
};

