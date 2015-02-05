#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>

using namespace std;

class Phonebase{
private:
	class Abonent{
	public:
		Abonent(const int& phone_) :left(nullptr), right(nullptr), phone(phone_){};
		Abonent(int phone, string name) :left(nullptr), right(nullptr){};
		Abonent() :left(nullptr), right(nullptr), name(nullptr), phone(0){};
		~Abonent(){ delete left; delete right; }
		string name;
		unsigned int  phone;
		Abonent *left;
		Abonent *right;
	};
	size_t size_;
	Abonent *root;
	Abonent* cur;
public:
	Abonent* SearchName(string name) {
		Abonent *current = this->root;
		while (current && current->name != name){
			if (name < current->name) {
				if (!current->left) {
					if (current->name != name)
						cout << "The name was not found." << endl;
					cur = current;
					return current;
				}
				current = current->left;
			}
			else {
				if (!current->right) {
					if (current->name != name)
						 cout << "The name was not found." << endl;
					cur = current;
					return current;
				}
				current = current->right;
			}
		}
		if (current) {
			cout << "Name was found" << endl;
			cur = current;
			return current;
		}
	};

	void Add(string name, int number){
		Abonent *temp = new Abonent(number, name);
		if (!root) {
			root = temp;
			cur = root;
		}
		else {
			Abonent *current = root;
			while (current) {
				if (number < current->phone){
					current = current->left;
				}
				else
				{
					current = current->right;
				}
			}
		}
	};

	void ModifyCurrent(string name, int number) { 
		cur->name = name; cur->phone = number; 
	};

	Abonent* SearchPhone(int number) {
		Abonent *current = this->root;
		while (current && current->phone != number){
			if (number < current->phone) {
				if (!current->left) {
					if (current->phone!= number) {
						cout << "The phone was not found." << endl;
						cur = current;
						return current;
					}
				}
				current = current->left;
			}
			else {
				if (!current->right) {
					if (current->phone != number) {
						cout << "The phone was not found." << endl;
						cur = current;
						return current;
					}
				}
				current = current->right;
			}
		}
		if (current) {
			cout << "The phone was found" << endl;
			cur = current;
			return current;
		}
	};
	void PrintToFile(Abonent *node, ofstream &s){
		Abonent *current = node;
		if (current) {
			PrintToFile(current->left, s);
			s << current->phone << endl;
			s << current->name << endl << endl;
			PrintToFile(current->right, s);
		}
	};

	void SaveToFile(string file){
		ofstream f(file);
		PrintToFile(this->root, f);
		f.close();
	};

	void ReadFromFile(string file){
		ifstream f(file);
		string name;
		int number;
		while (!f.eof()){
			f >> number;
			f >> name;
			this->Add(name, number);
			}
			f.close();
	};

	class iterator{
	private:
		Abonent* cur;
	public:
		iterator() : cur(nullptr){};
		iterator& operator++(){};
		string& operator*()const;
		bool operator==(const iterator& another) const;
		bool operator!=(const iterator& another) const{
			return !(operator==(another));
		};
	};
	iterator begin(){};
	iterator end(){ return iterator(); };
	Phonebase() : root(nullptr), size_(0){};
	size_t size(){ return size_; }
	string& operator[](const int& index){
			Abonent**current = &root;
			while ((*current) != nullptr)
			{
				if ((*current)->phone == index)
				{
					return (*current)->name;
				}
				if (index<(*current)->phone)
				{
					current = &((*current)->left);
				}
				else
				{
					current = &((*current)->right);
				}
			}
			(*current) = new Abonent(index);
			size_++;
			return (*current)->name;
		};
	~Phonebase(){ delete root; }
};

int main(){
	Phonebase a;
	a[12] = "Petrov";
	a[15] = "Lavrov";
	a[8] = "Ivanov";
	a[11] = "Sidorov";
	a[5] = "Komarov";
	a[18] = "Kozlov";
	a.SearchPhone(11);
	a.Add("Kirov", 43);
	a.SearchPhone(43);
	a.SaveToFile("data.txt");
	return 0;
}
