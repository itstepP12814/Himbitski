#include <iostream>
#include "Buble.h"

using namespace std;
void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void Bublesort(int *p, int size){
	int tmp;
	int *m = p;
	for (int i = 0; i < size - 1; ++i)
	{
		m = p;
		int *q = m + 1;
		for (int j = i; j < size-1; ++j)
		{
			if (*q<*m)
			{
				swap(m, q);
			}
			++q;
			++m;
		}
	}
}