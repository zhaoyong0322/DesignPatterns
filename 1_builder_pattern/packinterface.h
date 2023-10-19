#include <iostream>
using namespace std;

class Packing
{
public:
    Packing(){}
    virtual ~Packing(){}
    virtual string pack() = 0;
};

class Wrapper: public Packing
{
public:
    string pack()
    {
        return "Wrapper";
    }
};

class Bottle: public Packing
{
public:
    string pack()
    {
        return "Bottle";
    }
};
