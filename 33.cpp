#include <iostream>

using namespace std;

template <class T>
class Point{
    T x;
    T y;
public:
    ~Point(){};
    Point (T _x = 0, T _y = 0){
        this->x = _x;
        this->y = _y;
    };
    void Show();
};

template <class T>
void Point<T>::Show(){
    cout << "x: " << x << "\ty: " << y << "\n";
}


template class Point<int>;
template class Point<char>;

int main(){

    cout << "\nstatic\n";
    Point A(1,3);
    A.Show();
    Point B('A','B');
    B.Show();

    cout << "\ndynamic\n";
    Point<int>*C = new Point<int>[2];
    C[0].Show();
    C[1].Show();
    delete[]C;
    


}