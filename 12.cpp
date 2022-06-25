#include <iostream>
#include <Windows.h>

using namespace std;

class Circle
{
public:
	double x;
	double y;
	double R;

	Circle(double _x, double _y, double _R)
	{
		x = _x;
		y = _y;
		R = _R;
	}
	void moveShape(double _x, double _y)
	{
		x += _x;
		y += _y;
	}
};

class Square
{
public:
	double x;
	double y;
	double L;

	Square(double _x, double _y, double _L)
	{
		x = _x;
		y = _y;
		L = _L;
	}
	
	void moveShape(double _x, double _y)
	{
		x += _x;
		y += _y;
	}
};

class CircleInSquare : public Square, public Circle
{

public:
	double x;
	double y;

	CircleInSquare(double _x, double _y, double _R) : Square(_x, _y, _R * 2), Circle(_x, _y, _R) 
	{
		x = _x;
		y = _y;
	}

	void moveShape(double _x, double _y)
	{
		x += _x;
		y += _y;
	}

	void whereShape()
	{
		cout << "Центр фигру находится в (" << x << ";" << y << ")" << endl;
	}
};


// В задание не сказано, но я думаю если реализовать в начале всего этого какой нибудь абстрактный класс фигуры
// И определить в нем какую то базовую логику по типу мувфигуры и икс игрек может какая поблажка будет))0
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	CircleInSquare test(1, 2, 3);
	test.whereShape();
	test.moveShape(2, 3);
	test.whereShape();
}