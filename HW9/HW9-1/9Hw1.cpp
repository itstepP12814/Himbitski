#include <iostream>
#include <time.h>
#include "arfm.h"

using namespace std;
int main(){
	srand(time(NULL));
	const int a = 10;
	int mass[a];
	for (int i = 0; i < a; i++)//Zapolnenie masiva
	{
		mass[i] = rand() % 10;
		cout<< mass[i]<<" ";
	}
	cout << "\n\n";
	cout << average(mass, a) << endl;//Vivod funkcii
}