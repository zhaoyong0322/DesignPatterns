#include <string>
#include <iostream>
using namespace std;

class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    virtual void draw() = 0;
};

//不变的对象，可共享的资源
class CommonSource {
public:
    CommonSource(string c) : m_color(c) {
        cout << "create CommonSource: " << m_color <<" [ "<< this <<" ]"<< endl;
    }
    string color() {
        return m_color;
    }
private:
    string m_color;
};


//可变的对象
class Circle : public Shape
{
public:
    Circle(CommonSource* pSC): m_pSC(pSC) {
        cout << "create Circle: " << m_pSC << endl;
    }
    void setX(int x)
    {
        this->x = x;
        //cout << "set x success" << endl;
    }
    void setY(int y)
    {
        this->y = y;
        //cout << "set y success" << endl;
    }
    void setRadius(int radius)
    {
        this->radius = radius;
        //cout << "set radius success" << endl;
    }
    void draw()
    {
        cout << "draw Circle [color: " + m_pSC->color() + ", x: " + std::to_string(x) + ", y: " + std::to_string(y) + ", radius: " + std::to_string(radius) + "]" << endl << endl;
    }

private:
    int x;
    int y;
    int radius;
    CommonSource* m_pSC;

};
