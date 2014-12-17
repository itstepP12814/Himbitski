#include <iostream>
#include <time.h>

using namespace std;

class Bandit
{
public:
	Bandit(){
		Maxsize =0;
		size = 0;
		Drum = nullptr;
	};
	Bandit(int a){
		Maxsize = a;
		Drum = new int[Maxsize];
		for (int i = 0; i < Maxsize; ++i)
		{
			Drum[i] = i+1;
		}
	};
	~Bandit(){
		delete[]Drum;
	};
	void extract(){
		int count = 0;int	tmp = 0;
		for (int i = 0; i < 3; i++)
		{
			int y = rand() % 3;
			if (count==0)
			{
				count++;
				tmp = y + 1;
			}
			if (tmp == Drum[y])
			{
				count++;
			}
			cout << Drum[y] << " ";
		}
		cout << endl;
		if (count==4)
		{
			cout << "You Win\n";
		}
		else{ cout << "You loose\n"; }
	};
private:
	int * Drum;
	size_t Maxsize;
	size_t size;
};
int main(){
	int f = 1;
	srand(time(nullptr));
	Bandit a(3);
	while (f==1)
	{
		cout << "Push the Button\n";
		cin.get();
		a.extract();
		cout << "Exit-0, Try Again-1\n";
		cin >> f;
		cin.get();
	}

	return 0;
}