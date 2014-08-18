#include <iostream>
#include "Uravnenie.h"

using namespace std;
int main(){
	float a, b, c;
	cout << "Insert a: " << endl;
	cin >> a;
	cout << "Insert b: " << endl;
	cin >> b;
	cout << "insert c: " << endl;
	cin >> c;
	cout << "\n\n";
	Line(a, b);
	cout << endl;
	cout << "Square roots:\n";
	Square(a, b, c);
}