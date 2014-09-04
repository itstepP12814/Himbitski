#include <iostream>

using namespace std;

void main(){
	int x;
	int y = 1;
	int *iy = &y;
	int *ix = &x;
	cout << "Input number: " << endl;
	cin >> x;
	cout << endl;
	for (int i = 1; i <= *ix; ++i)
	{
		*iy *= i;
	}
	cout << "Result: " << *iy << endl;
}