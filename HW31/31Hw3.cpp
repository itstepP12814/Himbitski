#include <iostream>

using namespace std;

class Dot
{
public:
	Dot(){};
	Dot(float xx,float yy):x(xx),y(yy){};
	~Dot(){};

protected:
	float x;
	float y;
};
class Circle:public Dot
{
public:
     Circle(){};
	 Circle(float xx,float yy, float rr):radius(rr){
		 cout << "Circle created" << endl;
	 };
	 ~Circle(){};
protected:
	float radius;
};
class Square:public Dot
{
public:
	Square(){};
	Square(float xx,float yy,float rx,float uy):rightx(rx),up_y(uy){
		cout << "Square created" << endl;
	};
	~Square(){};
protected:
	float rightx;
	float up_y;
};
class CircleSquare:public Circle,public Square{
public:
	CircleSquare(){};
	CircleSquare(float xx, float yy, float rx, float uy, float rr) :Square(xx, yy, rx, uy), Circle((xx + rx) / 2.0, (yy - uy) / 2.0, rr){
		cout << "Circle in Square is created" << endl;
	};
	~CircleSquare(){};
protected:

};
int main(){
	CircleSquare x(2.0,3.0,3.0,2.0,5.0);
	return 0;
}