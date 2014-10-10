# include <iostream>

using namespace std;
const int size = 12;

struct Computer
{
	unsigned int korps : 1;
	unsigned int video : 1;
	unsigned int sound : 1;
	unsigned int dtype : 1;
	unsigned int wific : 1;
	unsigned int dvdrm : 1;
}HomePC[size];
int main(){
	int choice = 0;
	int counter = 0;
	cout << "Input form of Case: ATx-1 or AT-0" << endl;
	cin >> choice;
	HomePC[counter].korps = choice;
	++counter;
	cout << "Input form of Video: Discret-1 or Built in-0" << endl;
	cin >> choice;
	HomePC[counter].video = choice;
	++counter;
	cout << "Input form of Sound: Discret-1 or Built in-0" << endl;
	cin >> choice;
	HomePC[counter].sound = choice;
	++counter;
	cout << "Input form of reading Disk: DVD-1 or CD-0" << endl;
	cin >> choice;
	HomePC[counter].dvdrm = choice;
	++counter;
	cout << "Input form of plugin Internet: Wifi-1 or ADSL modem-0" << endl;
	cin >> choice;
	HomePC[counter].wific = choice;
	++counter;
	cout << "Input form of Winchester Disks: SDD-1 or HDD-0" << endl;
	cin >> choice;
	HomePC[counter].dtype = choice;
	counter = 0;
	cout << "Show computer configuration? Yes-1 No-0" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "Configuration of yours PC is: " << endl;
		if (HomePC[counter].korps == 1)
		{
			cout << "1.case form is: ATx" << endl;;
			++counter;
		}
		else
		{
			cout << "1.case form is: AT" << endl;;
			++counter;
		}
		if (HomePC[counter].video == 1)
		{
			cout << "2.video card is: discret"<< endl;;
			++counter;
		}
		else
		{
			cout << "2.video card is:  built-in"<<endl;
			++counter;
		}
		if (HomePC[counter].sound == 1)
		{
			cout << "3.sound card is: discret" << endl;
			++counter;
		}
		else
		{
			cout << "3.sound card is:  built-in" << endl;
			++counter;
		}
		if (HomePC[counter].dvdrm == 1)
		{
			cout << "4.your ROM is: DVD" << endl;
			++counter;
		}
		else
		{
			cout << "4.your ROM is: CD" << endl;
			++counter;
		}
		if (HomePC[counter].wific == 1)
		{
			cout << "5.your internet plugin is: wi-fi" << endl;
			++counter;
		}
		else
		{
			cout << "5.your internet plugin is: ADSL modem" << endl;
			++counter;
		}
		if (HomePC[counter].dtype == 1)
		{
			cout << "6.your winchester is: SDD" << endl;
			++counter;
		}
		else
		{
			cout << "6.your winchester is: HDD" << endl;
			++counter;
		}
	}
	else
	{
		return 0;
	}
}