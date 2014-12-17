#pragma once
class WaitPrint
{
private:
	int * Wait;
	int * Pri;
	int MaxQueueLength;
	int QueueLength;
public:
	void Add(int c, int p);
	int Extract();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Show();
	WaitPrint(int m);
	~WaitPrint();
};

