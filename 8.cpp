//#include <windows.h>

#include <iostream>

using namespace std;

template <class T>
class vect {
    T* p;
    size_t  size;
public:
    vect(size_t n) {
        size = n;
        p = new T[size];
    }
    
    T& operator [] (size_t i) { return p[i]; }
    
    ~vect() { delete[] p; }
};


int  main() {
    
    vect<float> A(7);
    
    cout << "Р’РІРµРґРёС‚Рµ 7 С‡РёСЃРµР»:" << endl;
    for (int i = 0; i<7; i++)
        cin >> A[i];
    for (int i = 0; i<7; i++)
        cout << A[i] << " ";
    cout << endl;
    
    vect<int> B(3);
    cout << "Р’РІРµРґРёС‚Рµ 3 С‡РёСЃР»Р°:" << endl;
    for (int i = 0; i<3; i++)
        cin >> B[i];
    for (int i = 0; i<3; i++)
        cout << B[i] << " ";
    cout << endl;
    
    vect<char> C(3);
    cout << "Р’РІРµРґРёС‚Рµ 3 СЃРёРјРІРѕР»Р°:" << endl;
    for (int i = 0; i<3; i++)
        cin >> C[i];
    for (int i = 0; i<3; i++)
        cout << C[i] << " ";
    cout << endl;
    
    return 0;
}