#ifndef SORT_H
#define SORT_H
void sort(int mass[],int Size,int third){
	int x;
	long i, j;
	if (third == 0)
	{
		for (int i = 0; i < Size; ++i)
		{
			for (int j = Size - 1; j >i; --j)
			{
				if (mass[j - 1] > mass[j])
				{
					x = mass[j - 1];
					mass[j - 1] = mass[j];
					mass[j] = x;
				}
			}
		}
	}
	else
	{
		for (int i = Size-1; i >=0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (mass[j] < mass[j + 1])
				{
					x = mass[j];
					mass[j] = mass[j + 1];
					mass[j + 1] = x;
				}
			}

		}
	}
}
#endif // !SORT_H
