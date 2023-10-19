#include <string>
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
    virtual Shape *clone() = 0;
    virtual void test() = 0;
};

class Circle: public Shape
{
public:
    Circle(string type) : type(type)
    {
        cout << "create Circle" << endl;
    }
    ~Circle(){}
    Circle(const Circle& circle)
    {
        this->type = circle.type;
    }
    Shape *clone()
    {
        return new Circle(*this);
    }
    void test()
    {
        cout << "type: " << type << endl;
    }

private:
    string type;
};

void prototype_test() {
    Shape *circle1 = new Circle("circle");
    circle1->test();
    cout << endl;
    Shape *circle2 = circle1->clone();
    circle2->test();
    cout << endl;
    if (circle1 == circle2) {
        cout << "same" << endl;
    } else  {
        cout << "different" << endl;
    }
}
