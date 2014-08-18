#ifndef ARFM_H
#define ARFM_H
template <typename T> float average(T mass[], T a){
	T summ = 0;
	for (T i = 0; i < a; ++i)
	{
		summ += mass[i];
	}
	 return float (summ) /float (a);
}
#endif // !ARFM_H
