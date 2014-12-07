#include <iostream>

using namespace std;

class Time
{
public:
	Time();
	Time(unsigned int,unsigned int);
	~Time(){};
	Time& operator +(const Time &b) const{
		Time tmp;
		tmp.hour = hour + b.hour;
		if (tmp.hour>24)
		{
			tmp.hour -= 24;
		}
		tmp.minutes = minutes + b.minutes;
		if (tmp.minutes>60)
		{
			tmp.minutes -= 60;
		}
		return tmp;
	};
	Time& operator -(const Time &b) const{
		Time tmp;
		if (hour>b.hour)
		{
			tmp.hour = hour - b.hour;
			if (minutes > b.minutes)
			{
				tmp.minutes = minutes - b.minutes;
			}
			else
			{
				tmp.minutes = minutes - b.minutes+60;
			}
			return tmp;
		}
		if (hour==b.hour)
		{
			if (minutes > b.minutes)
			{
				tmp.minutes = minutes - b.minutes;
			}
			else
			{
				tmp.minutes = minutes - b.minutes + 60;
			}
			return tmp;
		}
		if (hour<b.hour)
		{
			tmp.hour = b.hour - hour;
			if (minutes > b.minutes)
			{
				tmp.minutes = minutes - b.minutes;
			}
			else
			{
				tmp.minutes = minutes - b.minutes + 60;
			}
			return tmp;
		}
	};
	void operator ==(const Time &b) const{
		Time tmp;
		if (hour>b.hour)
		{
			tmp.hour = hour;
			tmp.minutes = minutes;
			cout <<"Time "<<tmp.hour<<" : "<<tmp.minutes << " is biggest\n";
			}else if (b.hour>hour)
				{
			tmp.hour = b.hour;
			tmp.minutes = b.minutes;
			cout << "Time " << tmp.hour << " : " << tmp.minutes << " is biggest\n";
				}else if (hour==b.hour)
					{
						if (minutes>b.minutes)
						{
							tmp.hour = b.hour;
							tmp.minutes = b.minutes;
							cout << "Time " << tmp.hour << " : " << tmp.minutes << " is biggest\n";
						}
						else(minutes < b.minutes);
						{
							tmp.hour = hour;
							tmp.minutes =minutes;
							cout << "Time " << tmp.hour << " : " << tmp.minutes << " is biggest\n";
						}
					}
	};
	void setupTime(){
		Time tmp;
		cout << "Input Hours\n";
		cin >> tmp.hour;
		cout << "Input Minutes\n";
		cin >> tmp.minutes;
		hour = tmp.hour;
		minutes = tmp.minutes;
	};
	void showupTime(){
		cout << "Time: " << hour << " hours  : " << minutes << " minutes\n";
	};
	void conversion(){
		Time tmp;
		if (hour>12)
		{
			tmp.hour = hour-12;
			tmp.minutes = minutes;
			cout << tmp.hour << " : " << tmp.minutes << " PM\n";
		}
		else
		{
			cout << tmp.hour << " : " << tmp.minutes << " AM\n";
		}
	};
private:
	int hour;
	int minutes;
};
Time::Time()
{
	hour = 0;
	minutes = 0;
}
Time::Time(unsigned int a, unsigned int b){
	hour = a;
	minutes = b;
};
int main(){
	Time a(15,53);
	a.showupTime();
	Time b(13,24);
	b.showupTime();
	//Time c;
	//c.setupTime();
	//c = a + b;
	a == b;
	//c.showupTime();
	b.conversion();
	return 0;
}