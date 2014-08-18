#include <iostream>
#include <ctime>

using namespace std;
void swap(int *a,int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void main()
{
	const int size = 20;
	int mass[size];
	int *pa = mass;
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		mass[i] = rand() % 20;
		cout << mass[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size - 1; i = i + 2)
	{
		swap(pa + i, pa + i + 1);
	}
	cout << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
}
