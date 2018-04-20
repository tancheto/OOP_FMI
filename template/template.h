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

// Пресмята медианата на колекцията.
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

// Пресмята модата на колекцията.
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

// Пресмята средно аритметичното на колекцията
//T average(T* collection, int size);

// Сумира всички елементи на колекцията с оператор +
//T accumulates(T* collection, int size);

//Връща максималния елемент в колекцията. Трябва да работи за всички типове с имплементиран оператор <
//T max(T* collection, int size);

//Връща минималния елемент в колекцията. Трябва да работи за всички типове с имплементиран оператор <
//T min(T* collection, int size);

// Връща нова колекция, в която са записани елементите на подадената, но в обратен ред
//T* reverse(T* collection, int size);

// Връща нова колекция, която съдържа само първите n елемента от подадената.
//T* take(T* collection, int size, int n);

// Връща нова колекция, която съдържа всички елементи от подадената, с изключение на първите n
//T* skip(T* collection, int size, int n);