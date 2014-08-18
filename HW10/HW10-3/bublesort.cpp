#include <iostream>
#include "Function.h"

using namespace std;

void bublesort(int mass[], int size, int j){
	for (int i = j-1; i >=0; --i)
	{
		for (int n= 0; n < i; ++n)
		{
			if (mass[n]>mass[n+1])
			{
				int tmp = mass[n];
				mass[n] = mass[n + 1];
				mass[n + 1] = tmp;
			}
		}
	}
	for (int i = size - 1; i > j; --i)
	{
		for (int n = j+1; n < i; ++n)
		{
			if (mass[n]<mass[n + 1])
			{
				int tmp = mass[n];
				mass[n] = mass[n + 1];
				mass[n + 1] = tmp;
			}
		}
	}
}