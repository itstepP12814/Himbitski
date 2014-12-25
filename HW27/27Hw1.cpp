#include <iostream>
using namespace std;

struct Element
{
	char data;
	Element * Next;
};


class List
{
	Element * Head;
	Element * Tail;
	int Count;

public:
	List();
	~List();
	void Add(char data);
	void Del();
	void DelAll();
	void Print();
	void addPosition(int position, char data);
	void delPosition(int position);
	int foundPosition(char data);
	int GetCount();
};
List::List()
{
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	DelAll();
}
int List::GetCount()
{
	//cout << Count << endl;
	return Count;
}
void List::Add(char data)
{
	Element * temp = new Element;
	temp->data = data;
	temp->Next = NULL;
	if (Head != NULL){
		Tail->Next = temp;
		Tail = temp;
	}
	else{
		Head = Tail = temp;
	}
	Count++;
}
void List::Del()
{
	Element * temp = Head;
	Head = Head->Next;
	delete temp;
}
void List::DelAll()
{
	while (Head != 0)
		Del();
}
void List::delPosition(int position){
	if (position<1 || position>Count)
	{
		cout << "Error!";
		exit(1);
	}

	if (position == 1){
		Element * temp = Head;
		Head = Head->Next;
		delete temp;
	}

	else if (position == Count){
		int i = 1;
		Element * temp = Head;
		while (i<Count - 1){
			temp = temp->Next;
			i++;
		}
		Tail = temp;
		delete Tail->Next;
		Tail->Next = NULL;
	}
	else
	{
		Element * temp = Head;
		int i = 1;
		while (i<position - 1){
			temp = temp->Next;
			i++;
		}

		Element * prev = temp;
		Element * cur = temp->Next;
		Element * next = cur->Next;
		prev->Next = next;
		delete cur;
	}
	Count--;
}
void List::addPosition(int position, char data){
if (position<1 || position>Count)
{
	cout << "Error!";
	exit(1);
}
if (position == 1){
	Element * temp = Head;
	Head = new Element;
	Head->data = data;
	Head->Next = temp;
}
else if (position == Count){
	Element * temp = Tail;
	Tail = new Element;
	Tail->data = data;
	Tail->Next = NULL;
	temp->Next = Tail;
}
else
{
	Element * temp = Head;
	int i = 1;
	while (i<position - 1){
		temp = temp->Next;
		i++;
	}
	Element * prev = temp;
	Element * next = temp->Next;
	Element * cur = new Element;
	prev->Next = cur;
	cur->data = data;
	cur->Next = next;
}
Count++;
}
void List::Print()
{
	Element * temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}
	cout << "\n";
}
int List::foundPosition(char data){
	Element * temp = Head;
	for (int i = 0; i < Count-1; ++i)
	{
		if (temp->data == data)
		{
			cout << i + 1 << endl;
			return i+1;
		}
		temp = temp->Next;
	}
	return NULL;
}
int main()
{
	List lst;
	char s[] = "Hello, World !!!\n";
	cout << s << "\n\n";
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		lst.Add(s[i]);
	}
	//lst.Print();
	lst.GetCount();
	lst.delPosition(3);
	lst.Print();
	lst.foundPosition('W');
	lst.addPosition(3, 'l');
	lst.Print();
	return 0;
}

