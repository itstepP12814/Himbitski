#include <iostream>
#include <exception>
#include <time.h>
using namespace std;
 

class Stack
{
public:
	Stack(){
		obj = 0;
		for (int i = 0; i < 10; i++)
		{
			stak[i] = -1;
		}
	};
	~Stack(){};
	void Push(int x){
		for (int obj = 0; obj < x; obj++)
		{
			if (obj>= 10)
			{
				throw exception("Stack is overflow\n");
			}
			stak[obj] = rand() % 5;
			
		}
	}
	void Pop(int x,int y){
		int temp = x;
		if (y > temp)
		{
			throw exception("Stack isnt so big\n");
		}
		for (int i = x; i >=y; --i)
		{
			stak[x] = -1;
		}
	}
	void Show(int x){
		cout << "________________________________\n";
		while (x!=0)
		{
			cout << stak[--x] << " ";
			
		}
		cout << endl;
	}
private:
	int obj;
	int stak[10];
};

int main(){
	try{
		srand(time(NULL));
		Stack a;
		int x, y;
		cout << "Input Stack lenght. Max 10\n";
		cin >> x;
		a.Push(x);
		cout << "Input\n";
		cin >> y;
		a.Pop(x,y);
		if (x==y)
		{
			throw exception("Stack is empty!");
		}
		a.Show(x-y);
	}
	catch(exception s)
	{
		cout << s.what() << endl;
	}
	return 0;
}