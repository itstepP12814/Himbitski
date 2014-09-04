#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	int m, n;
	const int size = 101;
	char mas[] = "I have bad feeling about this";
	char mas2[size];
	printf("Input from \n");
	scanf("%d", &m);
	printf("Input to \n");
	scanf("%d", &n);
	for (int i = m; i < n; ++i)
	{
		mas2[i - m]=mas[i];
		printf("%c ",mas[i]);
	}
	printf("\n");
}