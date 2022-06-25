#include <iostream>

using namespace std;

class A{};

class Y : public A {};

class Z : public A {};

class B : public A {};

class C : public A {};

class X : public Y, public Z, public B, public C{};

int main()
{

}