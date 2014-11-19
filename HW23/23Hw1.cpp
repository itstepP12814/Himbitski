#include <iostream>

using namespace std;

class Array
{
private:
	int *ar;
	size_t s;
public:
	Array();
	Array(size_t);
	Array(const Array &);
	Array& operator=(const Array &obj){
		if (s<obj.s)
		{
			ar = (int*)realloc(ar, (obj.s)*sizeof(int));
			s = obj.s;
		}
		for (int i = 0; i <s; i++)
		{
			ar[i] = obj.ar[i];
		}
		return *this;
	}
	Array operator+(const Array &obj){
		Array temp;
		temp.s = s + obj.s;
		temp.ar = (int*)realloc(temp.ar, temp.s*sizeof(int));
		for (int i = 0; i < s; ++i)
		{
			temp.ar[i] = ar[i]; 
		}
		for (int i = s; i < temp.s; ++i)
		{
			temp.ar[i] = obj.ar[i - s];
		}
		return temp;
	};
	Array operator-(const Array &obj){
		Array temp;
		if (s>obj.s)
		{
			temp.s = s - obj.s;
			temp.ar = (int*)realloc(temp.ar, (temp.s)*sizeof(int));
			for (int i = 0; i < temp.s; i++)
			{
				temp.ar[i] = ar[i];
			}
		}
		else
		{
			cout << "2 array is bigger than 1\n";
			return 0;
		}
		return temp;
	};
	Array& operator++(){
		ar = (int*)realloc(ar, (++s)*sizeof(int));
		return *this;
	};
	Array& operator--(){
		ar = (int*)realloc(ar, (--s)*sizeof(int));
		return *this;
	};
	int& operator[](int);
	size_t sz();
	~Array();
};

Array::Array()
{
	s = 0;
	ar = (int*)malloc(s*sizeof(int));
}
Array::Array(size_t siz)
{
	s = siz;
	ar = (int*)malloc(s*sizeof(int));
}
Array::Array(const Array &obj)
{
	s = obj.s;
	ar = (int*)malloc(s*sizeof(int));
	this->operator=(obj);
}
int& Array ::operator[](int x){
	if (x<s)
	{
		return ar[x];
	}
	cout << "You out of the array borders\n";
}
size_t Array::sz(){
	return s;
}
Array::~Array()
{
	free(ar);
}
int main(){
	int x = 1;
	Array a(7);
	for (int i = 0; i < a.sz(); i++)
	{
		a[i] = x++;
		cout << a[i] << " ";
	}
	cout << endl;
	Array b(5);
	for (int i = 0; i < b.sz(); i++)
	{
		b[i] = x++;
		cout << b[i] << " ";
	}
	cout << endl;
	Array c = a + b;
	for (int i = 0; i < c.sz(); i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	a++;
	for (int i = 0; i < a.sz(); i++)
	{
		if (a.sz() - i == 1)
		{
			a[i] = 0;
			cout << a[i] << endl;
		}
		else
		{
			cout << a[i] << " ";
		}
	}
	b--;
	for (int i = 0; i < b.sz(); i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}