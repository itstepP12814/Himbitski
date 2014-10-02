# include <iostream>
using namespace std;

void zapoln(int im, int jm){
	int **pArray = new int*[im];
	for (int i = 0; i < im; ++i)
	{
		pArray[i] = new int[jm];
	}
	for (int i = 0; i < im; i++)
	{
		for (int j = 0; j < jm; ++j)
		{
			pArray[i][j] = 1;
			cout << pArray[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < im; ++i)
	{
		delete[]pArray[i];
	}
	delete[]pArray;
}
void inputx(int im, int jm, int z){
	int **pArray = new int*[im];
	for (int i = 0; i < im; ++i)
	{
		pArray[i] = new int[jm];
	}
	for (int i = 0; i < im; ++i)
	{
		for (int j = 0; j < jm-1; ++j)
		{
			if (j==z)
			{
				pArray[i][j] = 0;
				cout << pArray[i][j] << " ";
				
			}
			pArray[i][j] =1;
			cout << pArray[i][j] << " ";
			
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < im; ++i)
	{
		delete[]pArray[i];
	}
	delete[]pArray;
}
void inputy(int im, int jm, int z){
	int **pArray = new int*[im];
	for (int i = 0; i < im; ++i)
	{
		pArray[i] = new int[jm];
	}
	for (int i = 0; i < im; ++i)
	{

		for (int j = 0; j < jm; ++j)
		{
			while (i == z&&j < jm)
			{
				pArray[i][j] = 0;
				cout << pArray[i][j] << " ";
				++j;
			}
			if (i!=z)
			{
				pArray[i][j] = 1;
				cout << pArray[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < im; ++i)
	{
		delete[]pArray[i];
	}
	delete[]pArray;
}
int main(){
	int im = 5; int jm = 5; int choice = 0; int x = 0; int y = 0;
	zapoln(im, jm);
	cout << "Input 1 for Length, Input 2 for Width" << endl;
	cin >> choice;
	if (choice==1)
	{
		cout << "Input number" << endl;
		cin >> x;
		++jm;
		--x;
		inputx(im, jm, x);
	}
	else if (choice==2)
	{
		cout << "Input number" << endl;
		cin >> y;
		++im;
		--y;
		inputy(im, jm, y);
	}
	else
	{
		cout << "Wrong number!!!!" << endl;
		return 0;
	}
	return 0;
}