#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

typedef struct 
{
	unsigned int bitH : 5;
	unsigned int bitM : 6;
	unsigned int bitS : 6;
	unsigned int bitMs : 10;
}red;
void InputTim(red &time){
	int tmp;
	cout << "Input Hours: " << endl;
	cin >> tmp;
	if (tmp>=24||tmp<0)
	{
		return;
	}
	time.bitH = tmp;
	cout << "Input Minutes: " << endl;
	cin >> tmp;
	if (tmp >= 60 || tmp <0)
	{
		return;
	}
	time.bitM= tmp;
	cout << "Input Second: " << endl;
	cin >> tmp;
	if (tmp >= 60 || tmp < 0)
	{
		return;
	}
	time.bitS = tmp;
	cout << "Input MiliSecond: " << endl;
	cin >> tmp;
	if (tmp >= 1000 || tmp < 0)
	{
		return;
	}
	time.bitMs = tmp;
}
void ShowTim(red time)
{
		cout << " Time:" << endl;
		cout << time.bitH << ":";
		cout << time.bitM << ":";
		cout << time.bitS << ":";
		cout << time.bitMs << endl;
}
int main(){
	int tmp;
	cout << "Show current time -1, Set time -2" << endl;
	cin >> tmp;
	if (tmp==1)
	{
		time_t rawtime;
		struct tm * timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		printf("Current time: %s", asctime(timeinfo));
	}
	else if (tmp == 2)
	{
		red tmptime = {};
		InputTim(tmptime);
		ShowTim(tmptime);
		return 0;
	}
	else
	{
		cout << "Lol wrong number" << endl;
		return 0;
	}
}