#include <iostream>

using namespace std;
//a)
class X{};
class A : virtual public X{};
class B : virtual public X{};
class C : public A, public B, virtual public X{};
//b)
class A{};
class B : virtual public A{};
class C : virtual public A{};
class D : public B, public C{};

int main()
{

}