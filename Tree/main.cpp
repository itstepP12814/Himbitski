#include <iostream>
#include <string>
using namespace std;

struct Item{
	int key;
	string value;
	Item *left;
	Item *right;
	Item *next;
	Item *prev;
};
class Tree{
private: 
	Item* root;
	Item *current;
public:
	Tree(){
		root = nullptr;
		current = nullptr;	
	};
	string &operator[](int i){
		Item**current = &root;
		while (*current!=nullptr)
		{
			if ((*current)->key==i)
			{
				return (*current)->value;
			}
			if (i<(*current)->key)
			{
				*current = (*current)->left;
			}
			else
			{
				*current = (*current)->right;
			}
		}
		*current = new Item;
		(*current)->left = (*current)->right = nullptr;
		(*current)->key = i;
		return (*current)->value;

	};
	~Tree(){};
};
int main(){
	Tree a;
	a[1] = "Lol";
	a[10] = "Chashbr";
	cout << a[1] << endl;
	return 0;
}