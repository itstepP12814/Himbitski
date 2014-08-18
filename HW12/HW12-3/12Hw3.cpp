#include <iostream>
#include <time.h>

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
	int step = 0;
	const int N = 10;
	int mas1[N];
	int *px = mas1;
	int mas2[N];
	int *py = mas2;
	int mas3[N + N];
	int *pz = mas3;
	int mas4[N + N];
	int *q3 = mas4;
	cout << "1 array: ";
	gen(px, N);
	cout << "2 array: ";
	gen(py, N);
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
	px = px - N;
	py = py - N;
	cout << "3 array: ";
	for (int i = 0; i < N + N; ++i)
	{
		printf("%3d", *pz);
		++pz;
	}
	pz = pz - (N + N);
	cout << endl;
	int *q = px;
	for (int i = 0; i < N; ++i)
	{
		int  *h = py;
		for (int j = 0; j < N; ++j)
		{
			if (*q==*h)
			{
				*pz = *q;
				++pz;
				++step;
			}
			++h;
		}
		++q;
	}
	pz = pz - step;
	cout << "Common elements: ";
	for (int i = 0; i < step; ++i)
	{
		printf("%3d", *pz);
		++pz;
	}
	cout << endl;
	// 1 iskluchenie + poslednee zadanie
	q = px;
	int flag;
	step = 0;
	for (int i = 0; i < N; ++i)
	{
		flag = 0;
		int  *h = py;
		for (int j = 0; j < N; ++j)
		{
			if (*q == *h)
			{
				flag = 1;
				break;
			}
			++h;
		}
		if (flag == 0)
		{
			*pz = *q;
			*q3 = *q;
			++q3;
			++pz;
			++step;
		}
		++q;
	}
	pz = pz - step;
	int z=step;
	cout << "Exceptions A: ";
	for (int i = 0; i < step; ++i)
	{
		printf("%3d", *pz);
		++pz;
	}
	cout << endl;
	pz = pz - step;
	//2 iskluchenie + poslednee zadanie
	q = py;
	step = 0;
	for (int i = 0; i < N; ++i)
	{
		flag = 0;
		int  *h = px;
		for (int j = 0; j < N; ++j)
		{
			if (*q == *h)
			{
				flag = 1;
				break;
			}
			++h;
		}
		if (flag == 0)
		{
			*q3 = *q;
			*pz = *q;
			++q3;
			++pz;
			++step;
		}
		++q;
	}
	pz = pz - step;
	cout << "Exceptions B: ";
	for (int i = 0; i < step; ++i)
	{
		printf("%3d", *pz);
		++pz;
	}
	cout << endl;
	pz = pz - step;
	q3 = q3 - (z + step);
	cout << "Exceptions A+B: ";
	for (int i = 0; i <z+step; ++i)
	{
		printf("%3d", *q3);
		++q3;
	}
	cout << "\n";
}