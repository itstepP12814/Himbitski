#include <iostream>

using namespace std;

void tower(int num, int start,int end, int mid){
	if (num!=0)
	{
		tower(num - 1, start, mid, end);
		cout << start << " move to " << end << endl;
		tower(num - 1, mid, end, start);
	}
}
int main(){
	int num;
	cout << "Input number of disks" << endl;
	cin >> num;
	int start = 1;
	int mid = 2;
	int end = 3;
	tower(num, start, end, mid);
}