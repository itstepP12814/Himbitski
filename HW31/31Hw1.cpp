#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	Student(){};
	Student(string name_, int age_): name(name_),age(age_){};
	~Student(){};
protected:
	string name;
	int age;
};
class Aspirant:public Student{
public:
	Aspirant(){};
	Aspirant(string name_, int age_, string spec_):spec(spec_){
		this->name = name_;
		this->age = age_;
	};
	~Aspirant(){};
	void show(){
		cout << "Aspirant: " << name <<" age: " <<age<< " has a: "<< spec<<" specialization"<<endl;
	};
private:
	string spec;
};

int main(){
	Aspirant a("Tolya", 24, "Math");
	a.show();
	return 0;
}
