#include <iostream>

using namespace std;

void main(){
	int x,y;
	cout << "Input number: " << "\t";
	cin >> x;
	cout << "Input number for rate: " << "\t";
	cin >> y;
	int z = 0;
	int *iz = &z;
	int *ix = &x;
	int *iy = &y;
	int q = (*ix %*iy);
	while ((*ix/ *iy)&&(q==0))
	{
		q = (*ix %*iy);
		*ix /= *iy;
		++z;
	}
	if (q!=0)
	{
		cout << "Error number " << *iy << " doesnt have rate" << endl;
	}
	else
	{
		cout << "Result: \t" << *iz << endl;
	}

}