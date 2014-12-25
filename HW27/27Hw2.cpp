#include <iostream>
#include <ctime>


using namespace std;
template <typename T> struct Item
{
	T number;
	Item *next;
	Item *prev;
};
template <typename T> class Doublelist{
	size_t size;
	T junk;
	Item<T> *begin;
	Item<T> *end;
public:
	Doublelist<T>::Doublelist(){
		begin = nullptr;
		end = nullptr;
		size = 0;
	};
	void push_front(T number){
		if (begin == nullptr)
		{
			begin = new Item<T>;
			end = begin;
			begin->next = nullptr;
			begin->prev = nullptr;
		}
		else{
			begin->prev = new Item<T>;
			begin->prev->prev = nullptr;
			begin->prev->next = begin;
			begin = begin->prev;
		}
		begin->number = number;
	}
	void push_back(T number){
		if (end == nullptr)
		{
			end = new Item<T>;
			begin = end;
			end->next = nullptr;
			end->prev = nullptr;
		}
		else{
			end->next = new Item<T>;
			end->next->next = nullptr;
			end->next->prev = end;
			end = end->next;
		}
		end->number = number;
	}
	void Print(){
		Item<T>* iterator = begin;
		while (iterator->next != nullptr)
		{
			cout << iterator->number << endl;
			iterator = iterator->next;
		}
	}
};
int main(){
	srand(time(NULL));
	Doublelist<int> list;
	list.push_front(rand() % 10+0.4);
	for (int i = 1; i < 10; i++)
	{
		list.push_back(i + 0.54);

	}
	list.Print();
	return 0;
}