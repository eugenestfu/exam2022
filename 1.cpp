#include <iostream>
#include <iomanip>

using namespace std;

class Book
{
public:
    string name;

    string author;

    int year;

    float price;




    Book()
    {
        cout << "Object is called: " << this << endl; //с умалчиваемыми (по умалчанию
        name = author = " ";
        year = price = 0;
        
    };

    Book(string name, string author, int year, float price) //с параметрами 
    {
        this->name = name;
        this->author = author;
        this->year = year;
        this->price = price;
    };

    Book(const Book& other) //копирования
    {
        this->name = name;
        this->author = author;
        this->year = year;
        this->price = price;
    };

    ~Book() // деструктор
    {
        cout << "Destructor has been called for " << this << endl;
    };

    //getters and setters (примеры)

    void SetName(string name)
    {
        this->name = name;
    };
    void Setyear(int year)
    {

        this->year = year;

    };
    int Getyear()
    {
        return year;
    };

    string GetAuthor()
    {
        return author;
    };

};

int (Book::*Getyear) (); //ukaz na kom-func

ostream& operator<<(ostream& os, const Book& book)
{
    os << setw(25) << book.author << endl;
    os << setw(25) << book.name << endl;
    os << setw(4) << book.year << endl;
    os << setw(5) << setprecision(4) << book.price << endl;

    return os;
};

istream& operator>> (istream& is, Book& book)
{
    
    is >> book.name >> book.author >> book.year >> book.price;

    return is;

}

int main()
{
    string name = "Skuka";
    const char *author = "Dibil";
    Book book1(name, author , 2022, 523.62);
    Book book2;

    cin >> book2;
    cout << book2 << endl;

    Book* book3 = &book1;
    
    cout << *book3 << endl;

}