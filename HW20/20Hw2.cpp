#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Student{
protected:
	string name;
	string spec;
	int age;
public:
	void Set();
	void Show();
	Student(){
		age = 0;
		string name();
		string spec();
	}
	~Student(){

	}
};
class StdGroup{
protected:
	string groupname;
public:
	vector<Student> Group;
	StdGroup(string n);
	void Show();
};
StdGroup::StdGroup(string n){
	groupname = n;
	cout << "Group: " << groupname << " is created\n";
};
void Student::Set(){
	string n; string s; int a;
	cout << "Input name\n";
	cin >> n;
	name = n;
	cout << "Input spec\n";
	cin >> s;
	spec = s;
	cout << "Input age\n";
	cin >> a;
	age = a;
}
void Student::Show(){
	cout << "Student name " << name << " age: " << age << " has a " << spec << " specialization\n";
}
void StdGroup::Show(){
	cout << " in Group: " << groupname << endl;
}
int main(){
	int a = 0;
	StdGroup obj("Vasilky");
	Student ob;
	do
	{
		cout << "Add Student-1, Show all-2, Exit-0\n";
		cin >> a;
		switch (a)
		{
		case 1:
			ob.Set();
			obj.Group.push_back(ob);
			break;
		case 2:
			for (int i = 0; i < obj.Group.size(); ++i)
			{
				obj.Group[i].Show();
				obj.Show();
			}
			break;
		case 0:
			cout << "Goodbye\n";
			break;
		}
	} while (a!=0);
	return 0;
}