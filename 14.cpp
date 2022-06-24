#include <iostream>
#include <windows.h>

using namespace std;
class comp {
    double re, im;
public:
    comp(double, double);
    ~comp() {};
    comp operator * (comp); 
    comp operator + (comp); 
    comp operator - (comp); 
    friend ostream& operator << (ostream&, comp&); 
    friend istream& operator >> (istream&, comp&); 
};
comp::comp(double _re = 0, double _im = 0) { re = _re;  im = _im; }
comp comp :: operator * (comp z) {
    return comp((re * z.re - im * z.im), re * z.im - im * z.re);
}
comp comp :: operator + (comp z) {
    return comp((re + z.re), im + z.im);
}
comp comp :: operator - (comp z) {
    return comp((re - z.re), im - z.im);
}
ostream& operator << (ostream& out, comp& z) {
    out << z.re;	if (z.im > 0) out << '+';
    out << z.im << 'i' << endl; return out;
}
istream& operator >> (istream& in, comp& z) {
    return (in >> z.re >> z.im);
}
int  main() {
    comp A(3.14, 6.3), B(5.2, 4), D = A * B, C = A + B, E = B - A;
    cin >> B;
    cout << A << B << D << C << E;
    system("pause");
    return 0;
}
