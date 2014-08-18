#include <iostream>
#include "allsorts.h"

using namespace std;

void merge(int mass[], int l, int r, int m){
	int mas[500];
	int start = l;
	int fin = m + 1;
	for (int j = l; j <= r; ++j)
	{
		if ((start<=m)&&((fin>r)||(mass[start]<mass[fin])))
		{
			mas[j] = mass[start];
			++start;
		}
		else
		{
			mas[j] = mass[fin];
			++fin;
		}
	}
	for (int i = l; i <= r; ++i)
	{
		mass[i] = mas[i];
	}
}
void mergesort(int mass[], int l, int r){
	int m = (l + r) / 2;
	if (l < r){
		mergesort(mass, l, m);
		mergesort(mass, m + 1, r);
		merge(mass, l, r, m);
	}
}
