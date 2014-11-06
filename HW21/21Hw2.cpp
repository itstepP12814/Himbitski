#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class String{
public:
	String();
	String(const char*);
	String(int);
	void printToStream(ostream &str);
	void setToStream(istream &str);
	~String();
private:
	char *s;
	size_t Lenght;
};
String::String(){
	int d = 80;
	s = new char[d];
	cout << "Input word less than 80 symbols\n";
	gets(s);
	cout << endl;
}
String::String(const char *str){
	s = (char*)malloc(strlen(str)+1);
	strcpy(s, str);
	Lenght = strlen(str);
	cout << endl;
}
String::String(int c){
	cout << "Input word\n";
	s = new char[c];
	setToStream(cin);
}
void String::printToStream(ostream &str){
	cout << "You creat\n";
	str << s << endl;
}
void String::setToStream(istream &str){
	str >> s;
}
String::~String(){
	cout << "Destructor working:    " <<s<<endl;
	free(s);
}
int main(){
	String a;
	a.printToStream(cout);
	String b("Minsk");
	b.printToStream(cout);
	cout << endl;
	String c(100);
	cout << endl;
	c.printToStream(cout);
	cout << endl;
	return 0;
}