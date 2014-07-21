#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
// Pechat simvolov
void prin(int a){
	for (int i = 0; i < a; i++)
	{
		cout << "*";
	}
	cout << endl;
}
// Brosok igroka
int brosokP(){
	int a = 0;
	int b = 0;
	int x = 0;
	a = rand() % 6+1;
	b = rand() % 6+1;
	prin(a);
	prin(b);
	x = a + b;
	cout << "Plyr: " << a<<"\t"<<b << "\n";
	return x;
}
// Brosok compa
int brosokC(){
	int a = 0;
	int b = 0;
	int x = 0;
	a = rand() % 6+1;
	b = rand() % 6+1;
	prin(a);
	prin(b);
	x = a + b;
	cout << "Comp: " << a << "\t" << b << "\n";
	return x;
}
void main(){
	srand(time(NULL));
	char z;
	float maxP = 0;
	float maxC = 0;
	int turnP;
	int turnC;
	cout << "Type any symbol to throw dice: \n";// Kontrolniy brosok
	cin >> z;
	turnP= brosokP();
	turnC= brosokC();
	cout << "\n\n";
	for (size_t i = 0; i < 5; i++)// Broski
	{

		if (turnP >= turnC)
		{
			maxP+=brosokP();
			maxC+=brosokC();
			cout << endl;
		}
		else
		{
			maxC += brosokC();
			maxP += brosokP();
			cout << endl;
		}
	}
	maxP /= 5;
	maxC /= 5;
	cout << "Result:" << endl;// Srednee po broskam
	cout << "Plyr: " << maxP << "\n";
	cout << "Comp: " << maxC << "\n";
}