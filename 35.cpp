#include <iostream>

using namespace std;

class Place {
    static Place* list_start;
    const char* name;
    Place* next;

public:
    Place(const char* _name) {

        name = _name;
        next = 0;
        ListAdd();
    }

    const char* GetName() {
        return name;
    }

    void ListAdd() {
        if (list_start == 0) {
            list_start = this;
        }
        else {
            Place* last = list_start;
            while (last->next != 0) {
                last = last->next;
            }
            last->next = this;
        }
    }

    virtual ~Place() {
    }

    virtual void WhoAreYou(int pos) = 0;

    static void ListPrint() {
        Place* now = list_start;
        int pos = 0;
        while (now != 0) {
            pos++;
            now->WhoAreYou(pos);
            now = now->next;
        }
    }

    static void ListClean() {
        Place* now = list_start;
        while (now != 0) {
            Place* x = now;
            now = now->next;
            delete x;
        }
        list_start = 0;
    }
};


class City : public Place {
public:
    City(const char* name) : Place(name) {}
    virtual void WhoAreYou(int pos) {
        cout << "n" << pos << " City " << GetName() << endl;
    }
};

class Region : public Place {
public:
    Region(const char* name) : Place(name) {}
    virtual void WhoAreYou(int pos) {
        cout << "n" << pos << " Region " << GetName() << endl;
    }
};

class BigCity : public City {
public:
    BigCity(const char* name) : City(name) {}
    virtual void WhoAreYou(int pos) {
        cout << "n" << pos << " Mega " << GetName() << endl;
    }
};




Place* Place::list_start = 0;

int main()
{

    new City("Moscow ful");
    new BigCity("Moscow");
    new Region("Obl");

    

    cout << "list output...\n";
    Place::ListPrint();

    cout << "list clean...\n";
    Place::ListClean();

    return 0;
}