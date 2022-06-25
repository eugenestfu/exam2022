#include <iostream>

using namespace std;

class Point {
    int x;
    int y;
public:
    Point(int _x = 0, int _y = 0) {
        this->x = _x;
        this->y = _y;
    };
    virtual void Show();
    virtual int Move(int _x, int _y);
    virtual ~Point() { };
};

void Point::Show() {
    cout << "x: " << x << "\ty: " << y << "\n";
};

int Point::Move(int _x, int _y) {
    x = _x;
    y = _y;
    cout << "Moved: (" << "x: " << x << "\ty: " << y << ")\n";
    return x, y;
};


class Circle : public Point {
    int r;
public:
    Circle(int _r = 0) {
        this->r = _r;
    }
    virtual void ShowR() {
        cout << "r: " << r << "\t";
        Show();
    }

};


int main() {

    Point A(0, 0);
    A.Show();
    A.Move(2, 3);
    Circle B(3);
    B.Move(3, 4);
    B.ShowR();

    return 0;
}
