#pragma once

template<typename T>

inline void Swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template<typename T>

inline void SelectionSort(T* collection, int size)
{
	T min;
	int minindex;

	for (int i = 0; i < size; i++)
	{
		min = collection[i];
		minindex = i;
		for (int j = i+1; j < size; j++)
		{
			if (collection[j] <= min)
			{
				min = collection[j];
				minindex = j;
			}			
		}

		Swap(collection[i], collection[minindex]);
		std::cout << collection[i] <<" ";
	}
	std::cout << std::endl;
}

// �������� ��������� �� ����������.
template<typename T>
T median(T* collection, int size)
{
	SelectionSort(collection,size);
	if (size % 2 == 1)
	{
		return collection[size / 2];
	}
	else
	{
		return (collection[size / 2] + collection[size / 2 - 1]) / 2;
	}
}

// �������� ������ �� ����������.
template<typename T>
T mode(T* collection, int size)
{
	SelectionSort(collection);

	int maxcount = 0;
	int index;

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if(collection[i]==collection[])
		}
	}
}

// �������� ������ ������������� �� ����������
//T average(T* collection, int size);

// ������ ������ �������� �� ���������� � �������� +
//T accumulates(T* collection, int size);

//����� ����������� ������� � ����������. ������ �� ������ �� ������ ������ � ������������� �������� <
//T max(T* collection, int size);

//����� ���������� ������� � ����������. ������ �� ������ �� ������ ������ � ������������� �������� <
//T min(T* collection, int size);

// ����� ���� ��������, � ����� �� �������� ���������� �� ����������, �� � ������� ���
//T* reverse(T* collection, int size);

// ����� ���� ��������, ����� ������� ���� ������� n �������� �� ����������.
//T* take(T* collection, int size, int n);

// ����� ���� ��������, ����� ������� ������ �������� �� ����������, � ���������� �� ������� n
//T* skip(T* collection, int size, int n);