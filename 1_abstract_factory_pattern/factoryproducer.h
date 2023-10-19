#include "abstractfactory.h"

class FactoryProducer
{
public:
    FactoryProducer(){}
    AbstractFactory *getFactory(string type)
    {
        if (type.compare("ShapeFactory") == 0)
        {
            return new ShapeFactory();
        }
        else if (type.compare("ColorFactory") == 0)
        {
            return new ColorFactory();
        }
        else
        {
            return nullptr;
        }
    }
};

void abstract_factory_test() {
    FactoryProducer factoryProducer;
    AbstractFactory * shapeFactory = factoryProducer.getFactory("ShapeFactory");
    AbstractFactory * colorFactory = factoryProducer.getFactory("ColorFactory");
    cout << endl;
    Shape * circle = shapeFactory->getShape("Circle");
    circle->draw();
    cout << endl;
    Shape * square = shapeFactory->getShape("Square");
    square->draw();
    cout << endl;
    Shape * rectangle = shapeFactory->getShape("Rectangle");
    rectangle->draw();
    cout << endl;
    Color * red = colorFactory->getColor("Red");
    red->fill();
    cout << endl;
    Color * green = colorFactory->getColor("Green");
    green->fill();
    cout << endl;
    Color * blue = colorFactory->getColor("Blue");
    blue->fill();

}
