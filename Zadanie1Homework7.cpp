#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void main(){
	const int a = 3;
	const int b = 4;
	int mass[a][b];
	srand(time(NULL));
	int counter = 0;
	for (int i = 0; i < a; ++i)// ������� �������� ���������� ������� � ����� �����
	{
		for (int j = 0; j < b; ++j)
		{
			mass[i][j] = rand() % 10;
			cout << mass[i][j] << " ";
			if (mass[i][j] == 0)
			{
				++counter;// ������� �����
			}
		}
		cout << endl;
	}
	cout << "The number of nulls you have is: "<< counter << endl;
}
