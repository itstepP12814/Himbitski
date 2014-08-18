#include <iostream>
#include "allsorts.h"

using namespace std;

void Bublesort(int mass[], int size){
	int tmp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (mass[j + 1]<mass[j])
			{
				tmp = mass[j+1];
				mass[j + 1] = mass[j];
				mass[j] = tmp;
			}
		}
	}
}