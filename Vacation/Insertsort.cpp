#include <iostream>
#include "allsorts.h"

using namespace std;

void Insertsort(int mass[], int size)
{
	int tmp;
	for (int i = 1, j; i < size; ++i) 
	{
		tmp = mass[i];
		for (j = i - 1; j >= 0 && mass[j] > tmp; --j)
		{
			mass[j + 1] = mass[j];
		}
		mass[j + 1] = tmp; 
	}
}