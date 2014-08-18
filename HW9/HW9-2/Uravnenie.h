#ifndef URAVNENIE_H
#define URAVNENIE_H
template <typename T> T Line(T a, T b){
	T x;
	x = -(b / a);
	return printf("Line root:\n %0.2f", x);
}
template <typename T> T Square(T a, T b, T c){
	T x;
	T D;
	D = (b*b) - (4 * a*c);
	if (D>0)
	{
		printf("x1 = %0.2f\n", (-(b)-D) / (2 * a));
		printf("x2 = %0.2f\n", (-(b)+D) / (2 * a));
	}
	else if (D=0)
	{
        printf("x = %0.2f\n", -(b) / (2 * a));
	}
	else
	{
		printf("You dont have roots\n");
	}
		
}
#endif // !Uravnenie_H
