#include <iostream>
#include "WaitPrint.h"
#include <time.h>

using namespace std;

int main(){
	srand(time(nullptr));
	WaitPrint a(10);
	WaitPrint b(10);
	for (int i = 0; i < 5; i++)
	{
		a.Add(i+1, rand() % 5+1);
	}
	a.Show();
	cout << "Printer Queue \n";
	for (int i = 0; i < 5; i++)
	{
		b.Add(a.Extract(), i+1);
	}
	//a.Show();
	b.Show();
	return 0;
}