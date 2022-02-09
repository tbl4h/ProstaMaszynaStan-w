#pragma once
#include <string>
#include <iostream>
using namespace std;

class Client
{
private:
    string name;
    int age;

public:
    Client() : name{"default"}, age{0} {}
    Client(string n, int a) : name{n}, age{a} {}
    Client(const Client &lhs) : name{lhs.name}, age{lhs.age} {}
    Client &operator=(Client &lhs)
    {
        if (this != addressof(lhs))
        {
            this->name = lhs.name;
            this->age = lhs.age;
        }
        return *this;
    }
    Client(const Client &&rrv) : name{move(rrv.name)}, age{move(rrv.age)} {}
    Client &operator=(Client &&rrv)
    {
        name = move(rrv.name);
        age = move(rrv.age);
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Client &obj)
    {
        os << "Imie: " << obj.name << " wiek: " << obj.age << endl;
    }
    void set_age(int a)
    {
        age = a;
    }
    int get_age() const { return age; }
    void set_name(const char *n)
    {
        name.clear();
        name = n;
    }
    string get_name() const { return name; }
};