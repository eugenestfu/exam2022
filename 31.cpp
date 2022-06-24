//#include <windows.h>
// дописать мейн!!!
#include <iostream>

using namespace std;

// СЃСЂР°РІРЅРёРІР°РµС‚ СЃС‚СЂРѕРєРё РїРѕ СЂР°Р·РјРµСЂСѓ Рё СЃРёРјРІРѕР»Р°Рј
bool StrCmp(char*, char*);

// СЃС‚СЂРѕРєРё СЂР°Р·РјРµСЂ
int StrLen(char*);

class String {
    char* str;
    size_t size;
    
public:
    String();
    String(char* _str, size_t size);
    String(char* _str);
    String(const String&);
 
 
    String& operator = (const String&);
    friend String operator + (const String&, const String&);
    String& operator += (const String&);
 
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);
    friend bool operator>(const String&, const String&);
    friend bool operator>=(const String&, const String&);
    friend bool operator<(const String&, const String&);
    friend bool operator<=(const String&, const String&);
 
    const char& operator[](int) const;
 
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::istream& operator>>(std::istream&, String&);
 
    ~String();
};
 
String::String(char* _str, size_t _size) {
    size = _size;
    str = new char[size];
    for (int i = 0; i < size; i++)
        str[i] = _str[i];
}
 
String::String(char* _str) {
    size = StrLen(_str)+1;
    str = new char[size];
    for (int i = 0; i < size; i++)
        str[i] = _str[i];
}

String::String(const String& rhs) {
    str = new char[size];
    for (int i = 0; i < size; i++)
        str[i] = rhs[i];
}
 
String::~String() {
    delete str;
}
 
String& String::operator = (const String& rhs) {
    if (this != &rhs) {
        delete[] this->str;
        this->str = new char[size];
        for (int i = 0; i < size; i++)
            this->str[i] = rhs.str[i];
    }
    return *this;
}
 
String& String::operator += (const String& rhs) {
    size_t sz = this->size + rhs.size;
    char* ts = new char[sz];
    
    for (size_t i = 0; i < this->size; i++)
        ts[i] = this->str[i];
    for (size_t ii = this->size, j = 0; ii <= sz; ii++, j++)
        ts[ii] = rhs.str[j];
    
    delete this->str;
    this->str = ts;
    return *this;
}
 
String operator+(const String& lhs, const String& rhs) {
    String ts = lhs;
    return ts += rhs;
}
 
bool operator==(const String& lhs, const String& rhs) { return StrCmp(lhs.str, rhs.str); }
bool operator!=(const String& lhs, const String& rhs) { return !(StrCmp(lhs.str, rhs.str)); }
bool operator>(const String& lhs, const String& rhs) { return (StrLen(lhs.str) > StrLen(rhs.str)) ? true : false; }
bool operator>=(const String& lhs, const String& rhs) { return (StrLen(lhs.str) >= StrLen(rhs.str)) ? true : false; }
bool operator<(const String& lhs, const String& rhs) { return (StrLen(lhs.str) < StrLen(rhs.str)) ? true : false; }
bool operator<=(const String& lhs, const String& rhs) { return (StrLen(lhs.str) <= StrLen(rhs.str)) ? true : false; }
 
const char& String::operator[](int i) const { return this->str[i]; }
 
std::ostream& operator<<(std::ostream& os, const String& obj) {
    return os << obj.str;
}
 
std::istream& operator >> (std::istream& is, String& obj) {
    char BUFF[2048];
    is.getline(BUFF, sizeof BUFF);
    obj = BUFF;
    return is;
}

int StrLen(char* _str) {
    int size = 0;
    while (_str[size] != 0) size++;
    return size;
}

bool StrCmp(char* str_f, char* str_s) {
    int i = 0;
    while (str_f[i] == str_s[i] && i < StrLen(str_f)) i++;
    return (i == StrLen(str_f)) ? true : false;
}
 

int  main() {
        
    String A;
    cout << "Р’РІРµРґРёС‚Рµ СЃС‚СЂРѕРєСѓ: " << endl;
    cin >> A;
    cout << "Р’С‹ РІРІРµР»Рё: " << A << endl;
    
    
    
    
    return 0;
}

