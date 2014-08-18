#include <iostream>
#include "allsorts.h"

using namespace std;

void downHeap(int mass[], long k, long n)
{
	int new_elem;
	long child;
	new_elem = mass[k];

	while (k <= n / 2) 
	{
		child = 2 * k;

		if (child < n && mass[child] < mass[child + 1])
		{ 
			child++;
		}
		if (new_elem >= mass[child])
		{
			break;
		}
		mass[k] = mass[child];   
		k = child;
	}
	mass[k] = new_elem;
}
void Pyramid(int mass[], int size)
{
	long i;
	int temp;

	for (i = size / 2 - 1; i >= 0; --i)
	{
		downHeap(mass, i, size - 1);
	}
	for (i = size - 1; i > 0; --i)
	{
		temp = mass[i];
		mass[i] = mass[0];
		mass[0] = temp;
		downHeap(mass, 0, i - 1);
	}
}

