#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person();
	Person(string, string, string, string);
	~Person();
	void Print();
	void Name(string);
	void Age(string);
	void Phone(string);
	void Sex(string);
private:
	string name;
	string age;
	string phone;
	string sex;
};

Person::Person()
{
}
Person::Person(string a, string b, string c, string d)
{
	cout << "Person is created\n";
	name = a;
	sex = b;
	age = c;
	phone = d;
}
void Person::Print(){
	cout << name << " " << age << " " << sex << " " << phone << endl;
}
void Person::Name(string a){
	getline(cin, a);
	name = a;
}void Person::Age(string a){
	getline(cin, a);
	age = a;
}void Person::Phone(string a){
	getline(cin, a);
	phone = a;
}
void Person::Sex(string a){
	getline(cin, a);
	sex = a;
}
Person::~Person()
{
	cout << "Destroy them all!!! Ahahahahah\n";
}
int main(){
	int choice = 0;
	string a,b,c,d;
	Person Red("Vasya", "male", "25", "245-14-88");
	Red.Print();
	do
	{
		cout << "If you wnat change name-1,age-2,phone-3,sex-4,show changes-5,exit-0\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Input new name\n";
			getline(cin, a);
			Red.Name(a);
			break;
		case 2:
			cout << "Input new age\n";
			getline(cin,c);
			Red.Age(c);
			break;
		case 3:
			cout << "Input new phone\n";
			getline(cin, d);
			Red.Phone(d);
			break;
		case 4:
			cout << "Input new sex\n";
			getline(cin, b);
			Red.Sex(b);
			break;
		case 5:
			Red.Print();
			break;
		default:
			break;
		}

	} while (choice!=0);
}