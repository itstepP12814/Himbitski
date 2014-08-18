#include <iostream>
#include "Round.h"

using namespace std;
int main(){
	float num;
	int a;
	cout << "Enter number\n";
	cin >> num;
	cout << "Accuracy to within\n";
	cin >> a;
	round(num, a);
}