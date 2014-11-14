#include <iostream>
#include <ctime>

using namespace std;

class Date
{
public:
	Date();
	Date(unsigned int, unsigned int, unsigned int);
	Date(int res){}
	void show();
	void Dayintheyear(const Date &, const Date &);
	void Plusday(int, const Date&);
	~Date();
	operator int()
	{
		return res;
	}
    Date& operator - (const Date &b)const{
		int mas[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int x = 0;
		int x2 = 0;
		Date temp;
		temp.year = year - b.year;
		/*if (month >= b.month)
		{
			temp.month = month - b.month;
		}
		else
		{
			temp.month = month - b.month + 12;
			--temp.year;
		}*/
		for (int i = 0; i < month-1; ++i)
		{
			x += mas[i];
		}
		x += day;
		for (int i = 0; i < b.month-1; ++i)
		{
			x2 += mas[i];
		}
		x2 += b.day;
        temp.day = x - x2;
		return temp;
	}
	Date& operator +(const Date &b) const{
		Date temp2;
		temp2.day = day + b.day;
		temp2.month = month + b.month;
		temp2.year = year + b.year;
		return temp2;
	}
private:
	int day;
	int month;
	int year;
	int res;
};
Date::Date()
{
	year = 0;
	month = 0;
	day = 0;
}
Date::Date(unsigned int iday, unsigned int imonth, unsigned int iyear)
{
	day = iday; month = imonth; year = iyear;
}
Date::~Date()
{
	cout << "Destructor works:  " << year << endl;
}
void Date::show()
{
	cout << "Date are: Year: " << year << " Month: " << month << " Day: " << day << endl;
}
void Date::Dayintheyear(const Date &c, const Date &b){
	int mas[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int res = 0;
	int tmp2 = b.year;
	if (c.year==0)
	{
		res = 365 + c.day;
	}
	else
	{
		res = (c.year * 365) + (c.day);
	}
	for (int i = 0; i <= c.year; ++i)
	{
		if (tmp2 % 4 == 0)
		{
			res += 1;
		}
		++tmp2;
	}
	cout << "Number of Days: "<< res << endl;
}
void Date::Plusday(int in,const Date &b){
	int mas[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	Date j;
	j.day = b.day + in;
	j.month = b.month;
	j.year = b.year;
	for (int i = b.month-1; i < 12; ++i)
	{
		if ((j.day > mas[i]))
		{
			j.day -= mas[i];

			if (j.month <=12)
			{
				++j.month;
				if ((j.month > 12))
				{
					j.year++;
					j.month = 1;
					i = -1;
				}
				if ((j.year % 4 == 0)&&(j.month ==2))
				{
					j.day -= 1;
				}
			}

		}
		if (j.day <= mas[i])
		{
			break;
		}
	}
	cout << "Date are: Year: " << j.year << " Month: " << j.month << " Day: " << j.day << endl;
}
int main(){
	int in;
	Date a(2,5, 2016);
	Date b(18,9, 2007);
	a.show();
	b.show();
	Date c = a - b;
	c.Dayintheyear(c,b);
	cout << "Enter number of day\n";
	cin >> in;
	c.Plusday(in, b);
	return 0;
}