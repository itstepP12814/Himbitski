#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
	const int size = 101;
	char a;
	char mass[size];
	printf("Input string: ");
	gets(mass);
	printf("Input symbol: ");
	a = getchar();
	for (int i = 0; i < strlen(mass); i++)
	{
		if (mass[i]==a)
		{
			printf("%d Position ", i + 1);
		}
	}
	printf("\n");
	return 0;
}