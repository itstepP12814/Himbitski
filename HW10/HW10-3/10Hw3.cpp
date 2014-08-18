#include <iostream>
#include <ctime>
#include "Function.h"

using namespace std;

void main(){
	const int size = 20;
	int mass[size];
	int x[size];
	int num;
	int flag = 0;
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		mass[i]=rand() % 20+1;
		cout << mass[i] << " ";
	}
	cout << endl;
	randomizer(mass, size, x);
	for (int i = 0; i < size; ++i)
	{
		cout << mass[i] << " ";
	}
	cout << "\n\n";
	num = rand() % 20 + 1;
	cout <<"Number: "<< num << endl;
	int j;
	for (j= 0; j < size; j++)
	{
	
		if (mass[j] == num)
		{
			flag = 1;
			cout << "Number place: " << j << "\n\n";
			break;
		}
	}
	if (flag==1)
	{
		bublesort(mass, size, j);
	}
	else{
		cout << "LOL. wrong number!!!!!" << "\n";
	}
	for (int j = 0; j < size; ++j)
	{
		cout << mass[j] << " ";
	}
	cout << endl;
}