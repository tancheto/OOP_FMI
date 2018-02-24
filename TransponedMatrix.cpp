// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void array_transponed(int n, int m)
{
	int **arr = new int*[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cout << "Vuvedete chislo:";
			cin >> arr[i][j];
		}
	}

	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout << endl;
	}


	delete arr;
}


int main()
{
	int N, M;
	cout << "Vuvedete n:"; cin >> N;
	cout << "Vuvedete m:"; cin >> M;

	array_transponed(N, M);

    return 0;
}

