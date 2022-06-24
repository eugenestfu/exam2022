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

    T& operator [] (size_t i){ return p[i]; }
    bool operator == (vect& second){ return size == second.size; }
    bool operator != (vect& second){ return size != second.size; }

    friend ostream& operator << (ostream& out, vect& z){
        for (size_t i = 0; i < z.size; i++) out << z[i] << " ";
        out << endl;
        return out;
    };

    friend istream& operator >> (istream& in, vect& z) {
        for (size_t i = 0; i < z.size; i++) in >> z[i];
        return in;
    };

};

int main(){


    vect<int> A(5);
    for (int i = 0; i < 5; i++) A[i] = i;
    char b[10] = { 'x','y','z' };
    vect<char> B(b, 3);
    vect<char> C = B;

    cout << " Demo C == B: ";
    cout << (C == B) << "\n";
    cout << " Demo C != B: ";
    cout << (C != B) << "\n";
    cout << " Demo A[0]: ";
    cout << A[0] << "\n";
    cout << " Demo B[1]: ";
    cout << B[1] << "\n";
    cout << " Demo C[2]: ";
    cout << C[2] << "\n";
}