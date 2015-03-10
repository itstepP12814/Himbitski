#include <iostream>
using namespace std;


class Point{
	int X;
	int Y;
public:
	Point(){
		X = Y = 0;
	}
	void SetPoint(int iX, int iY){
		X = iX;
		Y = iY;
	}
	void Show(){
		cout << "----------------------------\n\n";
		cout << X << "\t" << Y << "\n\n";
		cout << "----------------------------\n\n";
	}
};

class Figura{

	Point*obj;
	int count;
	int color;

public:
	Figura(){
		count = color = 0;
		obj = NULL;
	}

	void CreateFigura(int cr, int ct){
		if (ct<3) exit(0);
		count = ct;
		color = cr;
		obj = new Point[count];
		if (!obj) exit(0);
		int tempX, tempY;
		for (int i = 0; i<count; i++){
			cout << "Set X\n";
			cin >> tempX;
			cout << "Set Y\n";
			cin >> tempY;
			obj[i].SetPoint(tempX, tempY);
		}
	}

	void ShowFigura(){
		cout << "----------------------------\n\n";
		cout << "Color" << color << "\n\nPoints - " << count << "\n\n";
		for (int i = 0; i<count; i++){
			obj[i].Show();
		}
	}
	~Figura(){
		if (obj != NULL) delete[]obj;
	}
};

class ManFiguer{
public:
	ManFiguer():obj(nullptr),count(0){}; 
void creatManFiguer(int x){
		if (0 == x){ exit(0); }
		count = x;
		obj = new Figura[count];
		if (!obj) { exit(0); }
		int tempX, tempY;
		for (int i = 0; i < count; ++i)
			 {
			cout << "Enter the number of figuers: ";
			cin >> tempX;
			cout << "Enter the color of figure: ";
			cin >> tempY;
			obj[i].CreateFigura(tempY, tempX);
			}
	};
	~ManFiguer(){ if (obj != NULL) delete[]obj; };
	void show(){
		cout << "----------------------------\n\n";
		for (int i = 0; i < count; ++i){
			obj[i].ShowFigura();
		}
	}
private:
	Figura *obj;
	int count;
};

void main(){
	ManFiguer f;
	f.creatManFiguer(3);
	f.show();
}
