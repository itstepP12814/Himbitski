#include <iostream>

using namespace std;
void calculate(float &x, float &y, char &q){
	float z;
	switch (q){
	case '+':
		z = x + y;
		cout << "Result: " << z << endl;
		break;
	case '-':
		z = x - y;
		cout << "Result: " << z << endl;
		break;
	case '*':
		z = x * y;
		cout << "Result: " << z << endl;
		break;
	case '/':
		if (y != 0)
		{
			z = x / y;
			cout << "Result: " << z << endl;
		}
		else
		{
			cout << "Erorr!!!!" << endl;
		}
		break;
	}

}
int main(){
	float x, y;
	float *ix = &x;
	float *iy = &y;
	char q;
	char *iq = &q;
	cout << "Input 1 number" << endl;
	cin >> x;
	cout << "Choose operation" << endl;
	cin >> q;
	cout << "Input 2 number" << endl;
	cin >> y;
	cout << endl;
	calculate(x, y, q);
}