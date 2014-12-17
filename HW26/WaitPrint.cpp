#include <iostream>
#include "WaitPrint.h"

using namespace std;

WaitPrint::WaitPrint(int m)
{
	MaxQueueLength = m;
	Wait = new int[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	QueueLength = 0;
}
WaitPrint::~WaitPrint()
{
	delete[]Wait;
	delete[]Pri;
}
void WaitPrint::Show(){
	for (int i = 0; i<QueueLength; i++){
		cout <<"Computer Number: "<< Wait[i] << " - Priority " << Pri[i] <<"\n\n";
	}
}
void WaitPrint::Clear()
{
	QueueLength = 0;
}
bool WaitPrint::IsEmpty()
{
	return QueueLength == 0;
}
bool WaitPrint::IsFull()
{
	return QueueLength == MaxQueueLength;
}
int WaitPrint::GetCount()
{
	return QueueLength;
}
void WaitPrint::Add(int c, int p)
{
	if (!IsFull()){
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}
int WaitPrint::Extract()
{
	if (!IsEmpty()){
		int max_pri = Pri[0];
		int pos_max_pri = 0;
		for (int i = 1; i<QueueLength; i++)
		if (max_pri<Pri[i]){
			max_pri = Pri[i];
			pos_max_pri = i;
		}
		int temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];
		for (int i = pos_max_pri; i<QueueLength - 1; i++){
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		QueueLength--;
		//cout << "Computer Number: " << temp1 << "\n\n";
		return temp1;
	}
	else {
		return -1;
	}
}


