#include <iostream>

using namespace std;

class Counter{
protected:
	int obj,step, min, max;
public:
	/*Counter(){
		int step = 1, min = 0, max = 100;
	}
	/*~Counter(){
		cout << "Destructor is working\n";
	}*/
	void Show();
	void PlusOne();
	void Inmin(int);
	void Inmax(int);
};

Counter a;

void Counter::PlusOne(){
	++obj;
	if (obj > max)
	{
		step++;
		obj = min;
	}

}
void Counter:: Inmin(int a){
	min = a;
	obj = min;
}
void Counter::Inmax(int b){
	max = b;
}
void Counter::Show(){
	cout << "Counter from " << min << " to " << max << " is on " << obj <<" step\n";
}
int main(){
	int inpmin=0, inpmax=0;
	int choice = 0;
	cout << "Input min\n";
	cin >> inpmin;
	cout << "Input max\n";
	cin >> inpmax;
	a.Inmin(inpmin);
	a.Inmax(inpmax);
	do
	{
		cout << "Step Up-1, Show Counter-2, Exit-0\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			a.PlusOne();
			break;
		case 2:
			a.Show();
			break;
		case 0:
			cout << "Goodbye\n";
			break;
		}
	} while (choice!=0);
	return 0;
}