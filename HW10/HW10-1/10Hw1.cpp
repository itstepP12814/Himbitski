#include <iostream>
#include "Sortirovka.h"
#include <ctime>

using namespace std;

void main(){
	const int Size = 10;
	int mass[Size];
	srand(time(NULL));
	int third;
	for (int i = 0; i < Size; ++i)
	{
		mass[i] = rand() % 10;
		cout << mass[i] << " ";
	}
	cout << endl;
	cout << "Choose sort varinat\n";
	cout << "Increase sort: push 0\n";
	cout << "Wane sort: push any other number\n";
	cin >> third;
	sort(mass, Size, third);
	for (int j = 0; j < Size; ++j)
	{
		cout << mass[j] << " ";
	}
}