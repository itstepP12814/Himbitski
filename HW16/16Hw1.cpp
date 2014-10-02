#include <iostream>
#include <stdio.h>
#include <string.h>
 
#define N 20

using namespace std;

const char size = 100;
const int size2 = 10;
struct VideoShop
{
	char nameMovie[size]; 
	char director[size]; 
	char genre[size]; 
	int rating; 
	double price;
};

int main(){
	VideoShop Terminator = { "Terminator", "Cameron", "Action", 85, 7.2 };
	VideoShop Star_Wars = { "Star wars", "Lucas", "Fantasy", 100, 14.7 };
	VideoShop LOTR = { "Lord of the Rings", "Jackson", "Fantasy", 96, 20.3 };
	VideoShop Avatar = { "Avatar", "Cameron", "Fantasy", 87, 32.7 };
	VideoShop Scream = { "Scream", "Craven", "Horror", 62, 5.5 };
	VideoShop Friends = { "Friends", "Darabont", "Comedy", 93, 23 };
	VideoShop Green_mile = { "Green mile", "Halvorson", " Drama", 100, 18.8 };
	VideoShop Fahrenheit = { "Fahrenheit 9/11", "Moore", "Documentary", 74, 15.4 };
	VideoShop mass[N] = { Terminator, LOTR, Avatar, Star_Wars, Scream, Friends, Green_mile, Fahrenheit };
	int choice;
	int x = 1;
	char mass2[N];
	while (x == 1)
	{
		cout << "1.Search by Moviename" << endl;
		cout << "2.Search by Director" << endl;
		cout << "3.Search by Genre" << endl;
		cout << "4.Search Most popular in Genre" << endl;
		cout << "5.Show all" << endl;
		cout << "6.Add movie" << "\n\n";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
				  cout << "Input Movie name: ";
				  cout << endl;
				  cin >> mass2;
				  for (int i = 0; i < N; ++i)
				  {

					  if (strcmp(mass[i].nameMovie, mass2) == 0)
					  {
						  cout << mass[i].nameMovie << " ";
						  cout << mass[i].director << " ";
						  cout << mass[i].genre << " ";
						  cout << mass[i].price << "$" << " ";
						  cout << "Rating % " << mass[i].rating << endl;
						  break;
					  }
				  }
				  break;
		}
		case 2:
		{
				  cout << "Input Director name: ";
				  cout << endl;
				  cin >> mass2;
				  for (int i = 0; i < N; ++i)
				  {

					  if (strcmp(mass[i].director, mass2) == 0)
					  {
						  cout << mass[i].nameMovie << " ";
						  cout << mass[i].director << " ";
						  cout << mass[i].genre << " ";
						  cout << mass[i].price << "$" << " ";
						  cout << "Rating % " << mass[i].rating << endl;
						  break;
					  }
				  }
				  break;
		}
		case 3:
		{
				  cout << "Input Genre name: ";
				  cout << endl;
				  cin >> mass2;
				  for (int i = 0; i < N; ++i)
				  {

					  if (strcmp(mass[i].genre, mass2) == 0)
					  {
						  cout << mass[i].nameMovie << " ";
						  cout << mass[i].director << " ";
						  cout << mass[i].genre << " ";
						  cout << mass[i].price << "$" << " ";
						  cout << "Rating % " << mass[i].rating << endl;
						  break;
					  }
				  }
				  break;
		}
		case 4:
		{
				  cout << "Input Genre name: ";
				  cout << endl;
				  cin >> mass2;
				  int c = -1;
				  int j = -1;
				  for (int i = 0; i < N; ++i)
				  {

					  if (strcmp(mass[i].genre, mass2) == 0)
					  {
						  if (c < mass[i].rating)
						  {
							  c = mass[i].rating;
							  j = i;
						  }
					  }
				  }
				  if (c != -1)
				  {
					  cout << mass[j].nameMovie << " ";
					  cout << mass[j].director << " ";
					  cout << mass[j].genre << " ";
					  cout << mass[j].price << "$" << " ";
					  cout << "Rating % " << mass[j].rating << endl;
				  }
				  break;
		}
		case 5:
		{
				  for (int i = 0; i < N; i++)
				  {
					  if (mass[i].price == 0)
					  {
						  break;
					  }
					  cout << mass[i].nameMovie << " ";
					  cout << mass[i].director << " ";
					  cout << mass[i].genre << " ";
					  cout << mass[i].price << "$" << " ";
					  cout << "Rating % " << mass[i].rating << endl;
				  }
				  break;
		}
		case 6:
		{
				  int j = -1;
				  char nameM[size];
				  char Surn[size];
				  char Gen[size];
				  double Pr;
				  int Rat;
				  for (int i = 0; i < N; ++i)
				  {
					  if (mass[i].price == 0)
					  {
						  j = i;
						  break;
					  }
				  }
					  cout << "Input Moviename" << endl;
					  cin >> nameM; // Functia gets ne hochet rabotat. Ne poluchilos razobratsa
					  cout << "Directors Surname" << endl;
					  cin >> Surn;
					  cout << "Input Genre" << endl;
					  cin >> Gen;
					  cout << "Input Price" << endl;
					  cin >> Pr;
					  cout << "Input Rating" << endl;
					  cin >> Rat;
					  for (int i = 0; i < size; ++i)
					  {
						  mass[j].nameMovie[i] = nameM[i];
					  }
					  for (int i = 0; i < size; ++i)
					  {
						  mass[j].director[i] = Surn[i];
					  }
					  for (int i = 0; i < size; ++i)
					  {
						  mass[j].genre[i] = Gen[i];
					  }
					  mass[j].price = Pr;
				      mass[j].rating = Rat;
				 break;
		}
		default:
			break;
		}
		cout << "Return to main menu? 1-Yes 2-No" << endl;
		cin >> x;
	}
}

