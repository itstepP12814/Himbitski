#include <iostream>
#include <ctime>
#include "Function.h"

using namespace std;

void randomizer(int mass[],int size,int x[]){
	int temp;
	int temp2;
	for (int i = 0; i < size; ++i)
	{
		x[i]=0;
	}
	for (int i = 0; i < size; ++i)
	{
		if (x[i] == 1)
		{
			continue;
		}
		temp=rand() % 20;
		while (x[temp]==1&&temp!=i)
	    {
		    temp = rand() % 20;
	    }
		x[i] = 1;
		x[temp] = 1;
		temp2 = mass[i];
		mass[i] = mass[temp];
		mass[temp] = temp2;
	}
}