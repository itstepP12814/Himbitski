#include <iostream>
#include <string>
#include <exception>
using namespace std;

int reading(string s){
	int res = 0;
	const int x = 10;
	long temp = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i]<'0'||s[i]>'9')
		{
			throw exception("Incorrect symbol\n");
		}
		temp = res;
		res = res*x + ((int)s[i] - 48);
		if (temp>res)
		{
			throw exception("Number is not in the Int value\n");
		}
	}
	return res;
}
int main(){
	try{
		int x;
		string s;
		cin >> s;
		x = reading(s);
		cout << x << endl;
	}
	catch (exception s)
		{
		cout << s.what()<< endl;
		}
	return 0;
}