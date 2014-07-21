#include <iostream>
using namespace std;
void number(int a, int sys){
	int mass[10];
	char chislo;
	int x = 0;
	while (a!=0)
	{
		mass[x] = a%sys;
		a = a / sys;
		++x;
	}
	cout << "Result: ";
	for ( int i = x-1; i >=0;  --i)
	{
		if ((mass[i]>=0)&&(mass[i]<=9))
		{
			chislo = 48 + mass[i];
		}
		else
		{
			chislo = 55 + mass[i];
		}
		cout << chislo;
	}
	cout << endl;
}
void main(){
	int a; 
	int sys; 
	cout << "Enter number: "<<endl;
	cin >> a;
	cout << "Choose system: " << endl;
	cin >> sys;
	number(a, sys);
}