#include <iostream>

using namespace std;

template <class T>
class vect{
    T* p;
    size_t size;
public:
    vect(size_t n){
        size = n;
        p = new T[size];
    };
    vect(T* pm, size_t n){
        size = n;
        p = new T[size];
        for (size_t i = 0; i < size; i++) p[i] = pm[i];
    };

    size_t Get(){return size;}
    T& operator [] (size_t i){ return p[i]; }

};

int main(){


    vect<int> A(5);
    for (int i = 0; i < 5; i++) A[i] = i;
    char b[10] = { 'x','y','z' };
    vect<char> B(b, 3);
    vect<char> C = B;

    cout << A.Get() << "\t" << B.Get() << "\t" << C.Get() << "\n";


 }