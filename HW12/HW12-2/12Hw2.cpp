#include <iostream>
#include <time.h>
#include "Buble.h"

using namespace std;
void gen(int *p, int N){
	for (int i = 0; i < N; ++i)
	{
		*p = rand() % 20;
		printf("%3d", *p);
		++p;
	}
	p = p - (N - 1);
	cout << endl;
}
void main(){
	srand(time(NULL));
	const int N = 10;
	int mas1[N];
	int *px = mas1;
	int mas2[N];
	int *py = mas2;
	int mas3[N+N];
	int *pz = mas3;
	gen(px, N);
	gen(py, N);
	Bublesort(px, N);
	Bublesort(py, N);
	for (int i = 0; i < N; ++i)
	{
		*pz = *px;
		++pz;
		++px;
	}
	for (int i = 0; i < N; ++i)
	{
		*pz = *py;
		++pz;
		++py;
	}
	pz = pz - (N + N);
	Bublesort(pz, (N + N));
	for (int i = 0; i < N+N; i++)
	{
		printf("%3d", *pz);
		++pz;
	}
	cout << endl;
}