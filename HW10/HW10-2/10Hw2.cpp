#include <iostream>
#include <ctime>

using namespace std;

void main(){
	const int size = 20;
	int mass[size];
	srand(time(NULL));
	int leftSide=0;
	int rightSide=0;
	int min,x;
	int first, second;
	for (int i = 0; i < size; ++i)
	{
		mass[i] = rand() % 40-20;
		cout << mass[i] << " ";
	}
	cout << "\n\n";
	for (int j = 0; j < size; ++j)
	{
		if (mass[j]<0&&leftSide==0)
		{
			leftSide = j;
		}
	}
	cout << "Minimal Leftside number is: "<<  leftSide << "\n\n";
	for (int x = size-1; x >= 0; --x)
	{
		if (mass[x]<0&&rightSide==0)
		{
			rightSide = x;
		}
	}
	cout << "Minimal Rightside number is: " << rightSide << "\n\n";
	for (int i = leftSide+1; i < rightSide; ++i)
	{
		min = i;
		x = mass[i];
		for (int j = i + 1; j < rightSide; ++j)
		{
			if (x>mass[j])
			{
				x = mass[j];
				min = j;
			}
		}
		mass[min] = mass[i];
		mass[i] = x;
	}
	for (int c = 0; c < size; ++c)
	{
		cout << mass[c] << " ";
	}
	cout << endl;
}