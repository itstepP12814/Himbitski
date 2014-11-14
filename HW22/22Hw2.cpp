#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class String{
public:
	String();
	String(const char*);
	String(const String &obj){
		Lenght = obj.Lenght;
		s = (char*)malloc(Lenght + Lenght);
		strcpy(s, obj.s);
	}
	void printToStream(){
		cout << "You creat\n";
		cout << s << endl;
	};
      String operator*(const String &a){
		char* b = (char*)malloc(Lenght + 1);
		int count = 0;
		for (int i = 0; i < Lenght; ++i)
		{
			for (int j = 0; j < a.Lenght; ++j)
			{
				if (s[i] == a.s[j])
				{
					b[count++] = s[i];
					break;
				}
			}
		}
		b[count] = '\0';
		String cross(b);
		free(b);
		return cross;
	}
	String &operator=(const String &d){
		if (this == &d){
			return *this;
		}
		free(s);
		Lenght = d.Lenght;
		s = (char*)malloc(Lenght+1);
		strcpy(s, d.s);
		return *this;
	}
	~String();
private:
	char *s;
	size_t Lenght;
};
String::String(){
	Lenght = 0;
	s = NULL;
}
String::String(const char *str){
	s = (char*)malloc(strlen(str) + 1);
	strcpy(s, str);
	Lenght = strlen(str);
}
String::~String(){
	cout << "Destructor working:  " <<s<<endl;
	free(s);
}

int main(){
	String a("Minsk");
	a.printToStream();
	String b("Mexico");
	b.printToStream();
	String c;
	c = a*b;
	c.printToStream();
	return 0;
}





















































//char* c_str() const { return s; };// метод записи
/*String String::Cross(const String &a, const String &b){
	String result;
	for (int i = 0; i<a.Lenght; ++i)
	{
		for (int j = 0; j<b.Lenght; ++j)
		{
			if (a.s[i] == b.s[j]){
				result.s += a.s[i];
				
			}
		}
	}
	return result;
}
int main(){
	String a;//("Mexico");
	//a.printToStream(cout);
	String b;//("Minsk");
	//b.printToStream(cout);
	cout << endl;
	String c;
	c.Cross(a, b);
	return 0;
}*/