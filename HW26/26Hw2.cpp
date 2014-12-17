#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

class BusStop
{
public:
	BusStop(){
		int *wait = nullptr;
		Maxlength = 0;
		len = 0;
	};
	BusStop(int a){
		Maxlength = a;
		wait = new int[Maxlength];

		len = 0;
	};
	void Add(int c){
		if (!isFull())
		{
			wait[len++] = c;
		}
	};
	bool Extract(){
		if (!isEmpty())
		{
			int temp = wait[0];
			for (int i = 1; i < len; i++)
			{
				wait[i - 1] = wait[i];
			}
			wait[len - 1] = temp;
			return 1;
		}
		else return 0;
	};
	void Clear(){
		len = 0;
	};
	int isEmpty(){ return len == 0; };
	int isFull(){ return len == Maxlength; };
	int GetCount(){ return len; };
	void Show(){
		for (int i = 0; i < len; ++i)
		{
			cout << wait[i] << " ";
		}
	};
	~BusStop(){ delete[]wait; };
	void TimeatStop(){};
private:
	int *wait;
	int Maxlength;
	int len;
};
int main(){
	srand(time(nullptr));
	int x = rand() % 25 + 1;
	BusStop a(x);
	for (size_t i = 0; i < x; i++)
	{
		a.Add(i+1);
	}
	a.Show();
	cout << endl;
	a.Extract();
	cout << endl;
	a.Show();
	return 0;
}
/*VERSION 2.0
#include <iostream>
#include <string>
using namespace std;

class Bus
{
public:
	struct Item{
		string stop;
		Item* next;
		Item* prev;
	};
	Item * where;
	Item * whis;
	Bus() : whis(nullptr){};
	void addStop(string stop){
		if (whis == nullptr)
		{
			whis = new Item;
			where = whis;
			whis->next = nullptr;
			whis->prev = nullptr;
		}
		else{
			whis->next = new Item;
			whis->next->next = nullptr;
			whis->next->prev = whis;
			whis = whis->next;
			whis->next = where;
		}
		whis->stop = stop;
	}
private:

};
int main(){
	Bus B47;
	B47.addStop("Kirova str.");
	B47.addStop("Babrujskaya str.");
	B47.addStop("Maskouskaya str.");
	B47.addStop("Nezalezhnasci str.");
	for (size_t i = 0; i < 8; ++i)
	{
		cout << B47.where->stop << endl;
		B47.where = B47.where->next;
	}
	return 0;
}
*/