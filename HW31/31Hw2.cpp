#include <iostream>
#include <string>

using namespace std;

class Passport
{
public:
	Passport(){};
	Passport(string name, string add):Ownername(name),Address(add){};
	~Passport(){};
protected:
	string Ownername;
	string Address;
};

class ForeignPasport:public Passport
{
public:
	ForeignPasport(){};
	ForeignPasport(string name, string add, int vis,string serial):visa(vis),serialnumber(serial){
		this->Ownername = name;
		this->Address = add;
	};
	~ForeignPasport(){};
	void show(){
		cout << "Owner of the passport: " <<Ownername << endl;
		cout << "Owner address: " <<Address << endl;
		cout << "Count of visas: " << visa << endl;
		cout << "Serial number: " << serialnumber << endl;
	}
private:	
	int visa;
	string serialnumber;
};


int main(){
	ForeignPasport a("Ivanov", "Minsk Kirova str.", 5, "MP 1243464");
	a.show();
	return 0;
}