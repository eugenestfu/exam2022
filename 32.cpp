#include <iostream>
#include <cmath>
using namespace std;
class vect {
    int v[3];
public:
    vect(int* a, int* b) {
        v[0] = b[0] - a[0];
        v[1] = b[1] - a[1];
        v[2] = b[2] - a[2];
    };
    vect(int x, int y, int z) {
        v[0] = x;
        v[1] = y;
        v[2] = z;
    };
    vect(const vect& temp) {
        v[0] = temp.v[0];
        v[1] = temp.v[1];
        v[2] = temp.v[2];
    };
    ~vect() {};
    friend vect operator+(vect&, vect&);
    friend vect operator-(vect&, vect&);
    friend int sk(vect&, vect&);
    friend int lenght(vect&);
    friend int cos(vect&, vect&);
    void get() {
        cout << v[0] << " " << v[1] << " " << v[2] << endl;
    };
};
vect operator+(vect& a, vect& b) {
    return vect(a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2]);
};
vect operator-(vect& a, vect& b) {
    return vect(a.v[0] - b.v[0], a.v[1] - b.v[1], a.v[2] - b.v[2]);
};
int sk(vect& a, vect& b) {
    return (a.v[0] * b.v[0] + a.v[1] * b.v[1] + a.v[2] * b.v[2]);
};
int lenght(vect& a) {
    return(pow((a.v[0] * a.v[0] + a.v[1] * a.v[1] + a.v[2] * a.v[2]), 0.5));
};
int cos(vect& a, vect& b) {
    return(sk(a, b) / (lenght(a) * lenght(b)));
};
int main() {
    int one[]{ 1,1,1 };
    int two[]{ 2,2,2 };
    vect A(one, two);
    A.get();
    int three[]{3,3,3};
    int four[]{ 5,5,5 };
    vect B(three, four);
    B.get();
    vect C = A + B;
    C.get();
    vect D = B - A;
    D.get();
    cout << cos(C, D);
    return 0;
}
