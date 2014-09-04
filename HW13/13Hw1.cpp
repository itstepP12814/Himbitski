#include <iostream>

using namespace std;

void main(){
	int x = 5;
	int y = 2;
	int z = 8;
	int *px = &x;
	int *py = &y;
	int *pz = &z;
	*pz = *px + *py;
	cout << *pz << endl;
}