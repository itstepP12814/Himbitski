#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	const int a = 5;
	int max;
	int mass[a][a];
	for (int i = 0; i < a; ++i)// Zapolnenie matrici
	{
		for (int j = 0; j < a; ++j)
		{
			mass[i][j] = rand() % 10;
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	max = -1;// Zadaem maximum
	for (int i = 0; i < a; ++i)//Prohod po matrice 
	{
		for (int j = 0; j < a; ++j)
		{
			if (i + j >= a - 1 && i <= j)// Uslovie poiska
				//A - (i <= j); B - (i >= j); V - (i <= j && i + j <= a-1); G - (i >= j && i + j >= a-1); D - ((i <= j && i + j <= a-1) || (i >= j && i + j >= a-1));
				//i - (i + j <= a-1); K - (i + j >= a-1); Z - (i + j >= a-1 && i <= j); J - (i + j <= a-1 && i >= j); E - ((i + j <= a-1 && i >= j) || (i + j >= a-1 && i <= j))
			{
				cout << mass[i][j] << " ";
				if (max < mass[i][j])
					max = mass[i][j];
			}
		}
	}
	cout << endl << endl;
	cout << max << endl;
}