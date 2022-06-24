//#include <windows.h>
// нужно дописать мейн!!!
#include <iostream>

using namespace std;

class vect {
    
    float* p;
    size_t  size;
    
public:
    vect(size_t);
    vect(float*, size_t);
    vect(const vect&);
    
    float& operator [] (size_t i) { return p[i]; }
    friend ostream& operator<< (ostream&, vect&);
    friend istream& operator>> (istream&, vect&);
    
    friend vect operator * (const vect&, const int);
    friend vect operator + (const vect&, const int);
    friend vect operator - (const vect&, const vect&);
    
    ~vect() { delete[] p; }
};

vect::vect(size_t n) {
    size = n;
    p = new float[size];
}
vect::vect(float* pm, size_t  n) {
    size = n;
    p = new float[size];
    for (size_t i = 0; i < size; i++) p[i] = pm[i];
}
vect::vect(const vect& z) {
    size = z.size;
    p = new float[size];
    for (size_t i = 0; i < size; i++) p[i] = z.p[i];
}

vect operator * (const vect& a, const int m) {
    for (int i=0; i<a.size; i++)
        a.p[i] *= m;
    return a;
}

vect operator - (const vect& a, const vect& b) {
    for (int i=0; i<a.size; i++)
        a.p[i] -= b.p[i];
    return a;
}

vect operator + (const vect& a, const int m) {
    for (int i=0; i<a.size; i++)
        a.p[i] += m;
    return a;
}

ostream& operator << (ostream& out, vect& z) {
    for (size_t i = 0; i < z.size; i++)
        out << z[i] << " ";
    out << endl;
    return out;
}

istream& operator >> (istream& in, vect& z) {
    for (size_t i = 0; i < z.size; i++) in >> z[i];
    return in;
}


int  main() {
    
    float a[2] = {2,4};
    float b[2] = {3,6};
    
    vect A(a, 2);
    vect B(b, 2);
    
    vect C = (A * 2);
    
    cout << C << endl;
    
    return 0;
}


