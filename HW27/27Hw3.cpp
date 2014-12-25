#include <iostream>
#include <ctime>

using namespace std;

template <typename T> class Array{
	size_t size;
	size_t count;
	T *data;
	size_t grow;
public:
	Array(){
		data = nullptr;
		grow = 1;
		count = 0;
		size = 0;
	};
	int GetSize(){
		cout<<"Size of Array is:  "<< size <<" elements\n";
		return size;
	}
	void SetSize(size_t s, size_t g){
		grow = g;
		if (s==size)
		{
			return;
		}
		size = s;
		if (size>0)
		{
			if (size%grow != 0)
			{
				data = (T*)realloc(data, sizeof(T)*(size + (grow - size%grow)));
			}
			else if (size%grow == 0)
			{
				data = (T*)realloc(data, sizeof(T)*size);
			}
		}
		if (count>size)
		{
			count = size;
		}
	
	};
	int Array<T>::GetUpperBound()
	{
		return count - 1;
	}
	bool Array<T>::isEmpty()
	{
		if (count == 0) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Array<T>::FreeExtra(){}
	void Array<T>::removeAll()
	{
		free(data);
		data = NULL;
		count = 0;
		size = 0;
	}
	T GetAt(size_t i){
		if (i >= 0 && i < counter)
		{
			return data[i];
		}
	}
	T SetAt(size_t i,T d){
		if (i >= 0 && i<size)
		{
			data[index] = d;
			count = i + 1;
		}
	}
    T&operator[](size_t index){
				return data[index];
	}
	void Add(T d)
	{
		if (count<size)
		{
			data[count++] = d;
		}
		else if (count >= size)
		{
			SetSize(size + 1,grow);
			data[size - 1] = d;
			count++;
		}
	}
	T** GetData()
	{
		return &data;
	}
	void Append(Array &obj){
		int maxCount = GetUpperBound()>obj.GetUpperBound() ? GetUpperBound() + 1 : obj.GetUpperBound() + 1;
		int minCount = GetUpperBound()<obj.GetUpperBound() ? GetUpperBound() + 1 : obj.GetUpperBound() + 1;
		this->SetSize(maxCount, grow);

		for (int i = 0; i<minCount; i++)
		{
			data[i] += obj[i];
		}
	}
	Array<T> &operator= (const Array &obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		grow = obj.grow;
		count = obj.count;
		size = obj.size;
		data = (T*)realloc(data, sizeof(T)*(size + (grow - size%grow)));
		for (int i = 0; i<count; i++)
		{
			data[i] = obj.data[i];
		}

		return *this;
	}
	void Print(){
		for (int i = 0; i<count; i++)
		{
			cout << data[i] << " ";
		}

		cout << endl;
	}
	void InsertAt(int position, T d)
	{
		if (position<0 || position >= count)
		{
			cerr << "Error\n";
		}
		if (count >= size)
		{
			SetSize(size + 1,grow);
		}
		for (int i = count; i >= position; i--)
		{
			data[i] = data[i - 1];
		}
		data[position-1] = d;
		count++;
	}
	void Array<T>::RemoveAt(int position)
	{
		if (position<0 || position >= counter)
		{
			return 0;
		}
		for (int i = position; i<count; i++)
		{
			data[i] = data[i + 1];
		}
		counter--;
	}
	~Array(){
		if (data)
		{
			free(data);
		}
		data = nullptr;
	}
};
int main(){
	srand(time(NULL));
	Array<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Print();
	cout << list.GetUpperBound() << endl;
	cout << list.isEmpty() << endl;
	cout << list.GetSize() << endl;
	Array<int> list2;
	list2 = list;
	list.Append(list2);
	list.Print();
	list.InsertAt(1, 9);
	list.Print();
	return 0;
}