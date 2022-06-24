#include <iostream>

using namespace std;

class Transport {
    static Transport* list_start;
    const char* name;
    Transport* next;

public:
    Transport(const char* _name) {

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
            Transport* last = list_start;
            while (last->next != 0) {
                last = last->next;
            }
            last->next = this;
        }
    }

    virtual ~Transport() {
    }

    virtual void WhoAreYou(int pos) = 0;

    static void ListPrint() {
        Transport* now = list_start;
        int pos = 0;
        while (now != 0) {
            pos++;
            now->WhoAreYou(pos);
            now = now->next;
        }
    }

    static void ListClean() {
        Transport* now = list_start;
        while (now != 0) {
            Transport* x = now;
            now = now->next;
            delete x;
        }
        list_start = 0;
    }
};


class Auto : public Transport {
public:
    Auto(const char* name) : Transport(name) {}
    virtual void WhoAreYou(int pos) {
        cout << "n" << pos << " Auto " << GetName() << endl;
    }
};

class Train : public Transport {
public:
    Train(const char* name) : Transport(name) {}
    virtual void WhoAreYou(int pos) {
        cout << "n" << pos << " Train " << GetName() << endl;
    }
};

class Express : public Train {
public:
    Express(const char* name) : Train(name) {}
    virtual void WhoAreYou(int pos) {
        cout << "n" << pos << " Express " << GetName() << endl;
    }
};





Transport* Transport::list_start = 0;

int main()
{

    new Auto("Merc");
    new Train("Rus");
    new Express("Mos");

    

    cout << "list output...\n";
    Transport::ListPrint();

    cout << "list clean...\n";
    Transport::ListClean();

    return 0;
}