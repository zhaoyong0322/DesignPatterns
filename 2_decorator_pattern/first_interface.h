#include <iostream>
using namespace std;

class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    virtual void draw() = 0;
};

class Rectangle: public Shape
{
public:
    void draw()
    {
        cout << "draw Rectangle" << endl;
    }
};

class Circle: public Shape
{
public:
    void draw()
    {
        cout << "draw Circle" << endl;
    }
};
