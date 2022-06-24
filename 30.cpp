#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
// ����������� ������
class Data {
    int* mas;
    size_t size;
public:
    Data(size_t n) {
        size = n;
        mas = new int[size];
    };
    Data(int* MAS, size_t n) {
        size = n;
        mas = new int[size];
        for (int i = 0; i < size; i++) mas[i] = MAS[i];
    };
    Data(int* MAS, size_t n, size_t left, size_t right) {
        size = n;
        mas = new int[size];
        size_t j = 0;
        if (right - left > size-1) cout << "������\n";
        else for (size_t i = left-1; i < right; i++, j++)mas[i] = MAS[j];
    };
    Data(const Data& temp) { // ����������� �����������
        size = temp.size; 
        mas = new int[size];
        for (size_t i = 0; i < size; i++) mas[i] = temp.mas[i];
    };
    ~Data() { delete[] mas; };
    void operator+(Data& a) {
        for (size_t i = 0; i < size; i++) mas[i] += a.mas[i];
    };
    void operator-(Data& a) {
        for (size_t i = 0; i < size; i++) mas[i] -= a.mas[i];
    };
    void operator*(int N) {
        for (size_t i = 0; i < size; i++) mas[i] *= N;
    };
    void operator/(int N) {
        for (size_t i = 0; i < size; i++) mas[i] /= N;
    };
    int& operator [](size_t i) {
        try {
            if (i > size - 1) {
                throw out_of_range("����� �� �������");
            }
        }
        catch (const out_of_range o) {
            cout << o.what();
            exit(0);
        };
        return mas[i];
    };
    friend ostream& operator<< (ostream&, Data&);
};
ostream& operator << (ostream& out, Data& temp) {
    for (size_t i = 0; i < temp.size; i++)
        out << temp.mas[i] << " ";
    out << endl;
    return out;
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    {
        cout << "����������� � ����� ����������(������), ��������� � ���������" << endl;
        Data D(3);
        D[0] = 1;
        D[1] = 2;
        D[2] = 3;
        cout << D;
    };
    {
        cout << "����������� � ����� �����������(��������, ������)" << endl;
        int d[]{ 1,2,3 };
        Data D(d, size(d));
        cout << D;
    };
    {
        cout << "������� ������������ ������" << endl;
        int d[]{ 1, 2, 3, 4, 5};
        Data D(d, 5, 1, 4);
        cout << D;
    };
    {
        cout << "������� ������������ ������ - ����� �� �������" << endl;
        int d[]{ 1, 2, 3, 4, 5, 6 };
        Data D(d, 5, 1, 6);
        cout << D;
    };
    {
        cout << "��������" << endl;
        int d[]{ 1,2,3 };
        int d1[]{ 3,2,1 };
        Data D(d, size(d));
        Data D1(d1, size(d1));
        cout << D << D1;
        D + D1;
        cout << D;
        D - D1;
        cout << D;
        D * 2;
        cout << D;
        D / 2;
        cout << D;
    };
    {
        cout << "�����������" << endl;
        int d[]{ 1,2,3 };
        Data D(d, size(d));
        cout << D;
        Data D1(D);
        cout << D1;
    };
    {
        Data D(1);
        D[1] = 4;
        cout << "����� �� �������" << endl;
    };
    return 0;
}
