#include <iostream>

using namespace std;
void main(){
	double a, b, c;
	double &ia = a;
	double *iia = &ia;
	double &ib = b;
	double *iib = &ib;
	double &ic = c;
	double *iic = &ib;
	cout << "Input 1 number: \t";
	cin >> a;
	cout << "Input 2 number: \t";
	cin >> b;
	if (*iib!=0)
	{
		*iic = *iia / *iib;
		cout << "Result: \t" << *iic << endl;
	}
	else
	{
		cout << "Cant dived !!!NULL!!!!!" << endl;
	}
}