#include <iostream>
#include "allsorts.h"
using namespace std;

void selectsort(int  mass[], int size)
{
	int tmp;
	for (int i = 0; i < size; ++i) 
	{
		int pos = i;
		tmp = mass[i];
		for (int j = i + 1; j < size; ++j) 
		{
			if (mass[j] < tmp)
			{
				pos = j;
				tmp = mass[j];
			}
		}
		mass[pos] = mass[i];
		mass[i] = tmp; 
	}
}