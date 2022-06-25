#include <iostream>
#include <string>
using namespace std;

class point {
protected:
double x, y;
public:
point (double x1=0.0, double y1=0.0): x(x1), y(y1) {}
void move (double x1=0.0, double y1=0.0) {x=x1; y=y1;}
};  

class figure :public point {
protected:
double dx, dy; // "габариты" фигуры
public:
figure (double x1=0.0, double y1=0.0, double dx1=0.0, double dy1=0.0): point (x1, y1), dx(dx1), dy(dy1) {}
//изменить на заданную величину габариты
void grow (double k) {dx +=k; dy +=k;}
//вычислить площадь еще неизвестной фигуры
virtual double area() = 0; //чистая виртуальная функция
virtual string className() = 0; //чистая виртуальная функция
friend ostream& operator << (ostream& out, figure& );
};  
ostream& operator << (ostream& out, figure &fig )
{out<<fig.className() << ":\t center: x= " <<fig.x<< ",\ty= "<<fig.y;
out<< ";\n\tdx= "<<fig.dx<< ",\tdy= "<<fig.dy;
<<";\tarea = "<<fig.area();
return out;}

struct square: public figure {
square (double x1=0.0, double y1=0.0, double dx1=0.0, double dy1=0.0):figure(x1, y1, dx1, dy1){}
virtual double aerea ()
{return dx*dy;}
string className() {return string("square")}
};

int main() {
ellipse A(10.0, 8.0, 20.0, 20.0), B;
cout<<"Object A:\n "<<A<<endl;
A.move(5.0,5.0);
cout<<" A.move(5.0,5.0):\n" <<A<<endl;
A.grow(-18.0);
//cout<<" A.grow(-18.0):\n" <<A<<endl;
B=A;
cout<<"Object B:\n "<<B<<endl;
square C (1.0, 3.0, 5.0, 6.0), D;
cout<<"Object C:\n "<<C<<endl;
C.grow(-5.0);
cout<<" C.grow(-5.0):\n" <<C<<endl;
D. move (-10, 50);
cout<<" D.move(-10, 50):\n" <<D<<endl;
D.grow(10.0);
cout<<"Object D:\n "<<D<<endl;
return 0;
}
