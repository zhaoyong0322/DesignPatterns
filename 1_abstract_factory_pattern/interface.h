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

class Circle: public Shape
{
public:
    Circle()
    {
        cout << "create Circle" << endl;
    }
    void draw()
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
    void draw()
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
    void draw()
    {
        cout << "draw Rectangle" << endl;
    }
};

class Color
{
public:
    Color()
    {
        cout << "create Color" << endl;
    }
    virtual ~Color(){}
    virtual void fill() = 0;
};

class Red: public Color
{
public:
    Red()
    {
        cout << "create Red" << endl;
    }
    void fill()
    {
        cout << "fill Red" << endl;
    }
};

class Green: public Color
{
public:
    Green()
    {
        cout << "create Green" << endl;
    }
    void fill()
    {
        cout << "fill Green" << endl;
    }
};

class Blue: public Color
{
public:
    Blue()
    {
        cout << "create Blue" << endl;
    }
    void fill()
    {
        cout << "fill Blue" << endl;
    }
};
