#include <iostream>

using namespace std;
const int size = 100;
#define S 6
template <class T> void sort(T mass[], int size)
{

	int p;
	Student x;

	for (int j = 0; j<size; ++j)
	{
		p = j;
		x = mass[j];
		for (int k = j + 1; k<size; ++k)
		{
			int s = 0; 
			if (mass[k].name[s] == x.name[s])
			{
				s++;
			}
			if (mass[k].name[s]<x.name[s])
			{
				p = k;
				x = mass[k];
			}
		}
		mass[p] = mass[j];
		mass[j] = x;
	}
}

struct Student
{
	char name[size];
	int group;
	unsigned int zachet : 30;
}alstd[S];
int main()
{
	int allstudents = S;
	int x = 0;
	int m = 0;
	int sdn = 0;
	cout << "Input student? Yes-1 No-0" << endl;
	cin >> x;
	if (x == 1);
	{
		for (int i = 0; i < allstudents; ++i)
		{
			do
			{
				cout << "Input Surname: " <<"\t";
				fflush(stdin);
				cin.getline(alstd[i].name, sizeof(alstd[i].name));
				cout << "Number of group: " << "\t";
				cin >> alstd[i].group;
				cout << "Sdano-1  Nesdano-0: " << "\t";
				cin >> sdn;
				alstd[i].zachet = sdn;
			} while (sdn<0 || sdn>1);
		}
	}
	do
	{
		cout << "0 - Zachteno" << endl;
		cout << "1 - Nezachteno" << endl;
		int choice_1;
		do
		{
			cin >> choice_1;
		} while (choice_1<0 || choice_1>1);
		if (choice_1 == 0)
		{
			cout << "Sort by Alphabet-1 by Group-0" << endl;
			cin >> m;
			if (m == 0)
			{
				cout << "\nNumber of group" << endl;
				int number = 0;
				cin >> number;
				int counter = 0;
				for (int i = 0; i < S; ++i)
				{
					if ((alstd[i].group == number) && (alstd[i].zachet == 1))
					{
						cout << "\nSurname: " << alstd[i].name << endl;
						cout << "Number of group: " << alstd[i].group << endl;
						counter++;
					}
				}
				cout << "\nStudent in group: " << number << " Sdavshih zachet: " << counter << endl;
			}
			else
			{
				sort(alstd, S);
				for (int j = 0; j < S; ++j)
				{
					if (alstd[j].zachet == 1)
					{
						cout << "\nSurname: " << alstd[j].name << endl;
						cout << "Number of group: " << alstd[j].group << endl;
					}
				}
			}
		}
		if (choice_1 == 1)
		{
			cout << "Sort by Alphabet-1 by Group-0" << endl;
			int choice_2;

			do
			cin >> choice_2;
			while (choice_2<0 || choice_2>1);

			if (choice_2 == 0)
			{
				cout << "\nNumber of group" << endl;
				int number;
				cin >> number;
				int counter = 0;

				for (int j = 0; j < S; j++)
				{
					if ((alstd[j].group == number)&&(alstd[j].zachet == 0))
					{
						cout << "\nSurname: " << alstd[j].name << endl;
						cout << "Number of group: " << alstd[j].group << endl;
						counter++;
					}
				}

				cout << "\nStudent in group: " << number << "Ne Sdavshih zachet: " << counter << endl;
			}

			else
			{
				sort(alstd, S);
				for (int j = 0; j < S; j++)
				{
					if (alstd[j].zachet == 0)
					{
						cout << "\nSurname: " << alstd[j].name << endl;
						cout << "Number of group: " << alstd[j].group << endl;
					}

				}
			}
		}
	cout << "\nShow another list yes-1 no-0" << endl;
	do
	cin >> x;
	while (x<0 || x>1);
	} while (x == 1);
}