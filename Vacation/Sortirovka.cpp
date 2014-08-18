#include <iostream>
#include <ctime>
#include "allsorts.h"
#include <time.h>

using namespace std;

int main(){
	const int size = 500;
	int mass[size];
	srand(time(NULL));
	int l = mass[0];
	int r = mass[size - 1];
	int choose;
	for (int i = 0; i < size; ++i)
	{
		mass[i] = rand() % 40;
		cout << mass[i] << " ";
	}
	cout << "\n\n";
	cout << "Choose sort\n" << "1-quicksort\n" << "2-mergesort\n" << "3-Pyramid\n" << "4-Bublesort\n" << "5-Insertsort\n" << "6-selectosort\n";
	cin >> choose;
	switch (choose)
	{
	case(1):
		quicksort(mass, 0, size - 1);
		break;
	case(2):
		mergesort(mass, 0, size - 1);
		break;
	case(3):
		Pyramid(mass, size);
		break;
	case(4):
		Bublesort(mass, size);
		break;
	case(5):
		Insertsort(mass, size);
		break;
	case(6):
		selectsort(mass, size);
		break;
	default:
		cout << "Wrong number.ERORR\n";
		break;
	}
	for (int i = 0; i < size; ++i)
	{
		cout << mass[i] << " ";
	}
	cout << "\n\n";
}

