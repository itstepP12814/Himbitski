#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    const int size = 101;
	char mass[size];
	puts("Input symbols, max 100");
	gets(mass);
    printf ("Number of symbols:%d \n",strlen(mass));
	printf ("Symbols left:%d \n", size - 1 - strlen(mass));
	return 0;
}