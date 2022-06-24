#include <iostream>
#include <Windows.h>
using namespace std;
class obrabotka {
    size_t Num;
public:
    obrabotka(size_t n) { };
    virtual void make() = 0;
};
class One : public obrabotka {
public:
    One(size_t n) : obrabotka(n) { make(); };
    virtual void make() {
        cout << "Первая обработка" << endl;
    };
};
class Two : public obrabotka {
public:
    Two(size_t n) : obrabotka(n) { make(); }
    virtual void make() {
        cout << "Вторая обработка" << endl;
    };
};
class Three : public obrabotka {
public:
    Three(size_t n) : obrabotka(n) { make(); }
    virtual void make() {
        cout << "Третья обработка" << endl;
    };
};
class menu : public obrabotka {
public:
    menu(size_t n) : obrabotka(n) {
        if (n == 1)One(0);
        if (n == 2)Two(0);
        if (n == 3)Three(0);
    };
    virtual void make(){}
};
int main(){
    SetConsoleOutputCP(1251);
    new menu(1);
    new menu(2);
    new menu(3);
    return 0;
}

