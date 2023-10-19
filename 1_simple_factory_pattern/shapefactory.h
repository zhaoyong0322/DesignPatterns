#include "interface.h"

class ShapeFactory
{
public:
    ShapeFactory(){}

    Shape* getShape(string type)
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
};

void simple_factory_test() {

    ShapeFactory shapeFactory;
    Shape* pShape = shapeFactory.getShape("Square");
    pShape->draw();
    cout <<"---------"<< endl;
    pShape = shapeFactory.getShape("Rectangle");
    pShape->draw();
    cout <<"---------"<< endl;
    pShape = shapeFactory.getShape("Circle");
    pShape->draw();
    cout << endl;

}
