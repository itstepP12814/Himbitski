#include <iostream>
#include <ctime>

using namespace std;

void sdvig(int **mas, int a, int b, int side, int tm)
{
	int c = b+a;
	int *mass = new int[c];
	if (side == 1) // UP
	{
		int *mass = new int[c];
		for (int x = 0; x < tm; ++x)
		{
			for (int j = 0; j < b; ++j)
			{
				mass[j] = mas[0][j];
			}
			for (int i = 1; i < a; ++i)
			{
				for (int j = 0; j < b; ++j)
				{
					mas[i - 1][j] = mas[i][j];
				}
			}
			for (int j = 0; j < b; ++j)
			{
				mas[a - 1][j] = mass[j];
			}
		}
		delete[]mass;
	}
	else if (side == 2) // DOWN
	{
		int *mass = new int[c];
		for (int x = 0; x < tm; ++x)
		{
			for (int j = 0; j < b; ++j)
			{
				mass[j] = mas[a-1][j];
			}
			for (int i = a-2; i >= 0; --i)
			{
				for (int j = 0; j < b; ++j)
				{
					mas[i + 1][j] = mas[i][j];
				}
			}
			for (int j = 0; j < b; ++j)
			{
				mas[0][j] = mass[j];
			}
		}
		delete[]mass;
	}
	else if (side ==3) // RIGHT
	{
		int *mass = new int[c];
		for (int x = 0; x < tm; ++x)
		{
			for (int i = 0; i < a; ++i)
			{
				mass[i] = mas[i][b-1];
			}
			for (int i = 0; i < a; ++i)
			{
				for (int j = b-2; j >=0; --j)
				{
					mas[i][j+1] = mas[i][j];
				}
			}
			for (int i = 0; i < a; ++i)
			{
				mas[i][0] = mass[i];
			}
		}
		delete[]mass;
	}
	else if (side == 4) // LEFT
	{
		int *mass = new int[c];
		for (int x = 0; x < tm; ++x)
		{
			for (int i = 0; i < a; ++i)
			{
				mass[i] = mas[i][0];
			}
			for (int i = 0; i < a; ++i)
			{
				for (int j = 1; j < b; ++j)
				{
					mas[i][j-1] = mas[i][j];
				}
			}
			for (int i = 0; i < a; ++i)
			{
				mas[i][b-1] = mass[i];
			}
		}
		delete[]mass;
	}
	else
	{
		cout << "Wrong number" << endl;
	}
}
void delArry(int **pArray, int b)
{
	for (int i = 0; i < b; ++i)
	{
		delete[]pArray[i];
	}
	delete[]pArray;
}
int main(){
	srand(time(NULL));
	int a; int b; int side; int vectr; int tm;
	cout << "Input a" << endl;
	cin >> a;
	cout << "input b" << endl;
	cin >> b;
	cout << "Input Up-1 Down-2 Right-3 Left-4" << endl;
	cin >> side;
	cout << "Inpunt number of Translation" << endl;
	cin >> tm;
	int **mas = new int*[a];
	for (int i = 0; i < a; ++i)
	{
		mas[i] = new int[b];
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; ++j)
		{
			mas[i][j] = rand() % 9;
			printf("%2d ", mas[i][j]);
		}
		cout << endl;
	}
	cout << endl;
	sdvig(mas, a, b,side, tm);
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; ++j)
		{
			printf("%2d ", mas[i][j]);
		}
		cout << endl;
	}
	delArry(mas, a);
}