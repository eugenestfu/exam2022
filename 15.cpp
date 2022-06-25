#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

using namespace std;

class MyString
{
public:
	int len;
	char * str;

	MyString() : MyString("") {}

	MyString(const char * _string)
	{
		len = strlen(_string);
		str = new char[len + 1];
		strcpy(str, _string);
	}

	MyString(const MyString& obj)
	{
		len = obj.len;
		str = new char[len + 1];
		strcpy(str, obj.str);
	}

	MyString operator + (const MyString& str2)
	{	
		MyString temp;
		delete[] temp.str;
		temp.len = len + str2.len;
		temp.str = new char[temp.len + 1];
		strcpy(temp.str, str);
		strcpy(temp.str + len, str2.str);
		return temp;
	}

	friend ostream& operator << (ostream& os, MyString & str1)
	{
		os << str1.str;
		return os;
	}

	~MyString()
	{
		delete[]str;
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MyString str1("Привет!");
	cout << str1 << endl;
	MyString str2(str1);
	cout << str2 << endl;
	MyString str3 = str1 + str2;
	cout << str3;
}