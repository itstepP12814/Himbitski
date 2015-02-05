#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Firm{
	string name;
	string ownername;
	string phone;
	string address;
	string career;
	Firm * next;
	Firm * previous;
};

class PhoneBook
{
public:
	PhoneBook() : begin(nullptr), end(nullptr){};
	~PhoneBook(){};
	void add(string, string, string, string, string);
	void printAll();
	void ByName(string name){
		Firm *iterator = begin;
		while (iterator) {
			if (iterator->name == name){
				cout << iterator->name << endl;
			}
			iterator = iterator->next;
		}
	};
	void ByOwner(string owner){
		Firm *iterator = begin;
		while (iterator) {
			if (iterator->ownername == owner){
					cout << iterator->ownername << endl;
			}
				iterator = iterator->next;
		}
	};
	void ByPhone(string phone){
		Firm *iterator = begin;
		while (iterator) {
			if (iterator->phone == phone){
				cout << iterator->phone << endl;
			}
			iterator = iterator->next;
		}
	};
	void ByBusiness(string career){
		Firm *iterator = begin;
		while (iterator) {
			if (iterator->career == career){
				cout << iterator->career << endl;
			}
			iterator = iterator->next;
		}
	};
	void write(){
		ofstream out("data.txt");
		Firm *iterator = begin;
		while (iterator!= nullptr)
		{
			out <<"{"<< iterator->name << " " << iterator->ownername << " " << iterator->phone << " " << iterator->address << " " << iterator->career <<"}"<<"\n";
			iterator = iterator->next;
		}
		out.close();
	}
	void read(){
		ifstream in("data.txt");
		Firm* temp = new Firm;
		string tmp;
		vector<string> tmpr;
		int position;
		int count = -1;
		char Buf[1000];
		while(!in.eof()){
			in.getline(Buf, 999, '\n');
			position = 0;
			while (position < strlen(Buf)){
				if (Buf[position] == '{') {
					++position;
					while (Buf[position] != '}')
					{
						tmp.push_back(Buf[position]);
						++position;
						if (Buf[position] == ' ')
						{
							tmpr.push_back(tmp);
							tmp.clear();
						}
					}
					tmpr.push_back(tmp);
					tmp.clear();
				}
				++position;
			}
			temp->name = tmpr[++count];
			temp->ownername = tmpr[++count];
			temp->phone = tmpr[++count];
			temp->address = tmpr[++count];
			temp->career = tmpr[++count];
			temp->next = temp->previous = nullptr;
		}
		in.close();
	}
private:
	Firm* begin;
	Firm* end;
};

void PhoneBook::add(string _name, string _owner, string _phone, string _address, string _career){
	if (end == nullptr)
	{
		end = new Firm;
		begin = end;
		end->next = nullptr;
		end->previous = nullptr;
		begin->name = _name;
		begin->ownername = _owner;
		begin->phone = _phone;
		begin->address = _address;
		begin->career = _career;
	}
	else{
		end->next = new Firm;
		end->next->next = nullptr;
		end->next->previous = end;
		end = end->next;
		end->name = _name;
		end->ownername = _owner;
		end->phone = _phone;
		end->address = _address;
		end->career = _career;
	}
}
void PhoneBook::printAll(){
	Firm* iterator = begin;
	while (iterator!= nullptr)
	{
		cout << iterator->name << " ";
		cout << iterator->ownername << " ";
		cout << iterator->phone << " ";
		cout << iterator->address << " ";
		cout << iterator->career << endl;
		iterator = iterator->next;
	}
};
int main(){
	PhoneBook a;
	a.add("FBI", "Hoover", "1239854", "Broadway_ave.", "Security");
	a.add("MMM", "Mavrodi", "2532532", "Arbat_str.", "Finance");
	a.add("MTZ", "Ivanov", "3538517", "Kirova_str.", "Production");
	a.read();
	//a.write();
	//a.printAll();
	return 0;
}