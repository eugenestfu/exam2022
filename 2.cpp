#include <iostream>
#include <iomanip>

using namespace std;

class Worker
{
public:
    string FIO;
    string Job;
    float pay;

    Worker()
    {
        cout << "Object is called: " << this << endl; //с умалчиваемыми (по умалчанию
        FIO = Job = " ";
        pay = 0;

    };

    Worker(string FIO, string Job, float pay) //с параметрами 
    {
        this->FIO = FIO;
        this->Job = Job;
        this->pay = pay;
    };

    Worker(const Worker& other) //копирования
    {
        this->FIO = FIO;
        this->Job = Job;
        this->pay = pay;
    };

    ~Worker() // деструктор
    {
        cout << "Destructor has been called for " << this << endl;
    };

    //getters and setters (примеры)

    void Setname(string FIO)
    {
        this->FIO = FIO;
    };
   
    string GetJob()
    {
        return Job;
    };

};

int (Worker::* GetyFIO) (); //ukaz na kom-func

ostream& operator<<(ostream& os, const Worker& Worker)
{
    os << setw(30) << Worker.FIO << endl;
    os << setw(30) << Worker.Job << endl;
    os << setw(10) << setprecision(3) << Worker.pay << endl;

    return os;
};

istream& operator>> (istream& is, Worker& Worker)
{

    is >> Worker.FIO >> Worker.Job >> Worker.pay;
    return is;

}

int main()
{
    string FIO = "Ivanov Ivan Ivanovich";
    const char* Job = "Director";
    Worker Worker1(FIO, Job, 10000);
    Worker Worker2;
    cin >> Worker2;
    cout << Worker2 << endl;
    Worker* Worker3 = &Worker1;
    cout << *Worker3 << endl;

}