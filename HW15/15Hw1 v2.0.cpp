# include <iostream>
# include <time.h>
using namespace std;

void zapoln(int im, int jm, int**pArray){
	for (int i = 0; i < im; ++i)
	{
		pArray[i] = new int[jm];
	}
	for (int i = 0; i < im; i++)
	{
		for (int j = 0; j < jm; ++j)
		{
			pArray[i][j] = rand()%5;
			cout << pArray[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void delArry(int **pArray,int y){
	for (int i = 0; i < y; ++i)
	{
		delete[]pArray[i];
	}
	delete[]pArray;
}
void Ending(int im, int jm, int z, int x,int **mass){
	int **pArray = new int*[im];
	int ii = 0;	
	for (int i = 0; i < im; ++i)
	{
		pArray[i] = new int[jm];
	}
	if (z == 2)
	{
		for (int i = 0; i < im; ++i)
		{
			int jj = 0;
			for (int j = 0; j < jm; ++j)
			{
				if (i == (x - 1))
				{
					int tmp = 0;
					cin >> tmp;
					pArray[i][j] = tmp;
				}
				else
				{
					pArray[i][j] = mass[ii][jj];
					++jj;
				}
			}
			if (i != (x - 1))
			{
				++ii;
			}
		}
		cout << endl;
	}
	if (z == 1){
		for (int i = 0; i < im; ++i)
		{
			int jj = 0;
			int j;
		    for (j = 0; j < jm; ++j)
			{
			    if (j == (x - 1))
			    {
		     		int tmp = 0;
					cin >> tmp;
					pArray[i][j] = tmp;
				}
				else
				{
					pArray[i][j] = mass[ii][jj];
					++jj;
				}
			}
			if (j != (x - 1))
			{
				++ii;
			}
		}
		cout << endl;
	}
	for (int i = 0; i < im; ++i)
	{
		for (int j = 0; j < jm; ++j)
		{
			cout << pArray[i][j] << " ";
		}
		cout << endl;
	}
	if (z==1)
	{
		
		delArry(pArray, im);
		delArry(mass, im);
	}
	else
	{
		delArry(pArray, im);
		delArry(mass, jm);
	}
}
int main(){
	int im = 5; int jm = 5; int choice = 0; int x = 0; int y = 0;
	srand(time(NULL));
	int **pArray = new int*[im];
	zapoln(im, jm, pArray);
	cout << "Stolb-1 Stroka-2" << endl;
	cin >> choice;
	cout << "Position" << endl;
	cin >> x;
	if (choice==1)
	{
		++jm;
	}
	else if (choice == 2)
	{
		++im;
	}
	else
	{
		cout << "Error, wrong number" << endl;
		return 0;
	}
	cout << "Input 5 numbers" << endl;
	Ending(im, jm, choice,x, pArray);
	return 0;
}