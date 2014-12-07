#include <iostream>
#include <time.h>

using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(size_t, size_t);
	int* operator[](int s) { return x + s*f; }
	Matrix& operator +(const Matrix&a){
		for (int i = 0; i <f*s; ++i)
		{
			x[i] += a.x[i];
		}
		return *this;
	};
	Matrix& operator *(const Matrix&a){
		for (int i = 0; i < f*s; ++i)
		{
			x[i] *= a.x[i];
		}
		return *this;
	}
	void getElement(int i, int j) {
		int d = i;
		d = (i*f) + (s - j);
		cout << x[d] << endl;
	}
	void show(){
		for (int i = 0; i < (f*s); i++)
		{
			cout << x[i] << " ";
			if ((i+1)%f==0&&i!=0)
			{
				cout << endl;
			}
		}
		cout << endl;
	}
	void transpon(){
		int *y;
		y = (int*)malloc(s*f*sizeof(int));
		if (y==NULL)
		{
			exit(1);
		}
		int c = 0;
		for (int i = 0; i < f*s; ++i)
		{
			if (i%f==c||i==c)
			{
				y[i] = x[i];
				cout << y[i] << " ";
			}
			else if (i==((f*s)-1))
			{
				++c;
				i = c;
				--i;
				cout << endl;
			}
			
		}
		cout << endl;
	};
	~Matrix(){};
private:
	int *x;
	size_t f;
	size_t s;
};
Matrix::Matrix()
{

	x = nullptr;
	f = 0;
	s = 0;
}
Matrix::Matrix(size_t ff, size_t ss)
{
	f = ff;
	s = ss;
	x = (int*)malloc(s*f*sizeof(int));
	for (int i = 0; i < f*s; i++)
	{
		x[i] = rand() % 10;
	}
}
int main(){
	srand(time(NULL));
	Matrix a(3, 2);
	//a.show();
	//Matrix b(5, 5);
	//a[1][2] = 12;
	//a[0][1] = 8;
	//b.show();
	a.show();
	//b.show();
	//Matrix c; 
	//c = a*b;
	//c.show();
	//c = a + b;
	//c.show();
	a.transpon();
	//a.show();
	return 0;
}