#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	int m, n, x,z;
	const int size = 101;
	char mas[] = "I have bad feeling about this";
	char mas2[size];
	printf("Input from \n");
	scanf("%d", &m);
	printf("Input to \n");
	scanf("%d", &n);
	x = 0;
	for (int i = 0; i < m; ++i)
	{
		mas2[i] = mas[i];
		++x;
	}
	z = strlen(mas);
	for (int j = n;  j <= z; ++j)
	{
		mas2[x] = mas[j];
		++x;
	}
	printf("Result:\n");
	puts(mas2);
	return 0;
}