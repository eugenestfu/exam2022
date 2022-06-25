#include <iostream>

using namespace std;

class stroka  {
char*ch;                    // указатель на строку, на символьный массив
int len ;                      // длина строки
public:
stroka(char*cch)     //конструктор 1
{ len = сstrlen(cch) ; 
ch=new char [len+1];
cstrcpy (ch,cch); }
stroka(int N=20)        //конструктор 2
{ch = new char[N+1];  len=0;   ch[0]='\0' ;}
operator char* ( ) { return ch;}//операции – функции преобразования типов.
void vivod ( ) // выводит данные
{cout<< "строка: " <<ch<<" ,  длина строки="<<len;};
~stroka( )// деструктор
{delete[ ]ch;}
friend stroka&operator+(stroka&, stroka&);
//дружественная функция-операция 
};
stroka& operator+(stroka&A, stroka& B)
{ int N = A.len+ B.len;
stroka*ptr=new stroka(N);// выделяем память на суммарную строку
сstrcpy( ptr->ch , A.ch) ;// копируем в новую строку первуюстроку
сstrcat(ptr->ch ,B.ch) ; // присоединяем к ней и вторую строку
return *ptr ;       //возвращаем объект 
}
	
operator char* ( ) {return ch;}

operator int ( ) {return len;}                

int main(){}

