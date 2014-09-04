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
	for (int i = strlen(mass); i >= 0; --i)
	{
		if (mass[i] == a)
		{
			printf("%d Position ", i + 1);
			break;
		}
	}
	printf("\n");
	return 0;
}