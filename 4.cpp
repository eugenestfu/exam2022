#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Complex         // класс "Комплексное число"
{
private:
    double re, im;      // действительная и мнимая части

public:
    // конструкторы 

    Complex()
    {
    };

    Complex(double r)
    {
        re = r;
        im = 0;
    }

    Complex(double r, double i)
    {
        re = r;
        im = i;
    }



    // деструктор
    ~Complex()
    {
    }

    // остальные функции



    // оператор присваивания
    Complex& operator = (Complex& c)
    {
        re = c.re;
        im = c.im;

        return (*this);
    }


 

    // оператор сложения
    Complex operator + (const Complex& c)
    {
        return Complex(re + c.re, im + c.im);
    }



    

    // оператор умножения
    Complex operator * (const Complex& c)
    {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    

    // укажем дружественные операторы, которым мы разрешаем доступ
    // к личным (private) данным
    friend ostream& operator<< (ostream&, const Complex&);
    friend istream& operator>> (istream&, Complex&);
    friend Complex operator- ( Complex& c1,  Complex& c2);
    friend Complex operator-- (Complex& c);
};

// оператор вычитания
Complex operator -(Complex& c1, Complex& c2)
{
    Complex temp;
    temp.re = c1.re - c2.re;
    temp.im = c1.im - c2.im;
    return Complex(temp);
};

Complex operator--(Complex& c)
{
    Complex temp;
    temp.re = c.re - 1.0;
    temp.im = c.im - 1.0;
    return Complex(temp);
};
// перегрузка оператора <<
ostream& operator<< (ostream& out, const Complex& c)
{
    out << "(" << c.re << ", " << c.im << ")";
    return out;
}
int main()
{
    Complex a(5, 2);
    Complex b(3, -3);

    cout << "a = " << a << "; b =" << b << endl;


    cout << "a = " << a << "; b =" << b << endl;

    Complex c = a + b;

    cout << c << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << --a;
    return 0;
}