#include "interface.h"
#include <string>

class AbstractFactory
{
public:
    AbstractFactory()
    {
        cout << "create AbstractFactory" << endl;
    }
    virtual ~AbstractFactory(){}
    virtual Shape * getShape(string type) = 0;
    virtual Color * getColor(string type) = 0;
};

class ShapeFactory: public AbstractFactory
{
public:
    ShapeFactory()
    {
        cout << "create ShapeFactory" << endl;
    }
    Shape * getShape(string type)
    {
        if (type.compare("Circle") == 0) {
            return new Circle();
        } else if (type.compare("Square") == 0) {
            return new Square();
        } else if (type.compare("Rectangle") == 0) {
            return new Rectangle();
        } else {
            return nullptr;
        }
    }
    Color * getColor(string type)
    {
        return nullptr;
    }
};

class ColorFactory: public AbstractFactory
{
public:
    ColorFactory()
    {
        cout << "create ColorFactory" << endl;
    }
    Color *getColor(string type)
    {
        if (type.compare("Red") == 0) {
            return new Red();
        } else if (type.compare("Green") == 0) {
            return new Green();
        } else if (type.compare("Blue") == 0) {
            return new Blue();
        } else {
            return nullptr;
        }
    }
    Shape * getShape(string type)
    {
        return nullptr;
    }
};
