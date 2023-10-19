#include <iostream>
using namespace std;

class Shape
{
public:
    Shape()
    {
        cout << "create Shape" << endl;
    }
    virtual ~Shape(){}
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    Circle()
    {
        cout << "create Circle" << endl;
    }
    void draw() override
    {
        cout << "draw Circle" << endl;
    }
};

class Square: public Shape
{
public:
    Square()
    {
        cout << "create Square" << endl;
    }
    void draw() override
    {
        cout << "draw Square" << endl;
    }
};

class Rectangle: public Shape
{
public:
    Rectangle()
    {
        cout << "create Rectangle" << endl;
    }
    void draw () override
    {
        cout << "draw Rectangle" << endl;
    }
};
